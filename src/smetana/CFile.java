package smetana;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Iterator;

public class CFile {

	public static final boolean TRACE = false;

	private final File f;

	public CFile(File f) throws IOException {
		this.f = f;
	}

	public void toJavaFile() throws IOException {
		final File javaFile = getJavaFile();
		System.err.println("javaFile=" + javaFile.getAbsolutePath());
		javaFile.getParentFile().mkdirs();
		final PrintWriter pw = new PrintWriter(javaFile);
		toJavaFile(pw);
		pw.close();
	}

	public void toJavaFile(String stringToDetect) throws IOException {
		// System.err.println("javaFile=" + javaFile.getAbsolutePath());
		if (containsString(stringToDetect)) {
			toJavaFile();
		}
	}

	private boolean containsString(String stringToDetect) throws IOException {
		final BufferedReader br = new BufferedReader(new FileReader(getJavaFile()));
		try {
			String s = null;
			while ((s = br.readLine()) != null) {
				if (s.contains(stringToDetect)) {
					return true;
				}
			}
			return false;
		} finally {
			br.close();
		}

	}

	private File getJavaFile() {
		String path = f.getPath();
		if (path.contains("/lib/") || path.contains("\\lib\\")) {
			path = path.replaceFirst("^.*\\Wlib\\W", "src/gen/lib/");
		} else if (path.contains("/plugin/") || path.contains("\\plugin\\")) {
			path = path.replaceFirst("^.*\\Wplugin\\W", "src/gen/plugin/");
		} else {
			throw new IllegalStateException();
		}
		path = path.replace('.', '_');
		path = path.replaceFirst("_c$", ".java");
		path = path.replaceFirst("interface.java$", "interface_.java");
		final File javaFile = new File(path);
		return javaFile;
	}

	private String getClassName() {
		String name = f.getName().replaceFirst("\\.\\w+$", "");
		name = name.replace('.', '_');
		name = name.replaceFirst("^interface$", "interface_");
		return name;
	}

	private String getPackageName() {
		String path = f.getPath();
		if (path.contains("/lib/") || path.contains("\\lib\\")) {
			path = path.replaceFirst("^.*\\Wlib\\W", "gen/lib/");
		} else if (path.contains("/plugin/") || path.contains("\\plugin\\")) {
			path = path.replaceFirst("^.*\\Wplugin\\W", "gen/plugin/");
		} else {
			throw new IllegalStateException();
		}
		path = path.replace('/', '.');
		path = path.replace('\\', '.');
		// path = path.replaceAll("[\\/]", "\\.");
		return path.substring(0, path.length() - f.getName().length() - 1);
	}

	private void toJavaFile(PrintWriter pw) throws IOException {

		pw.println("package " + getPackageName() + ";");
		pw.println("import h.*;");
		pw.println("import core.*;");
		pw.println("import core.annotation.*;");
		pw.println("import static core.JUtils.*;");
		pw.println("import static core.size_t.*;");
		pw.println("import static core.OFFSET.*;");
		pw.println("import static core.Macro.*;");
		pw.println("import static core.Memory.*;");
		pw.println("import static core.Stdlib.*;");
		pw.println(getAllImport());
		pw.println("public class " + getClassName() + " {");

		final FileStringParser parser = new FileStringParser(f);
		final Iterator<String> it = parser.iterator();
		while (it.hasNext()) {
			final String s = it.next();
			if (TRACE) {
				System.err.println("LOOKING:" + s);
			}
			if (ignoredLine(s)) {
				continue;
			}
			if (Character.isWhitespace(s.charAt(0))) {
				continue;
			}
			if (s.equals(";")) {
				continue;
			}
			if (s.startsWith("#")) {
				continue;
			}
			if (s.startsWith("/*")) {
				continue;
			}
			if (s.startsWith("//")) {
				continue;
			}
			if (s.startsWith(TypedefStruct.TYPEDEF_STRUCT)) {
				final TypedefStruct typedefStruct = new TypedefStruct(s, it);
				typedefStruct.exportMe();
				continue;
			}
			if (s.startsWith("typedef enum")) {
				final TypedefStruct typedefEnum = new TypedefStruct(s, it);
				typedefEnum.exportMe();
				continue;
			}
			if (s.startsWith("typedef union")) {
				final TypedefStruct typedefUnion = new TypedefStruct(s, it);
				continue;
			}
			if (s.startsWith("struct")) {
				final TypedefStruct struct = new TypedefStruct(s, it);
				struct.exportMe();
				continue;
			}
			if (s.startsWith("static struct")) {
				final TypedefStruct struct = new TypedefStruct(s, it);
				continue;
			}
			if (s.startsWith("enum")) {
				final TypedefStruct enumc = new TypedefStruct(s, it);
				continue;
			}
			if (s.startsWith("union")) {
				final TypedefStruct enumc = new TypedefStruct(s, it);
				continue;
			}
			// if (s.startsWith("extern ")) {
			// final Extern extern = new Extern(s, it);
			// continue;
			// }
			if (s.startsWith("typedef") && s.contains("(")) {
				final TypedefStruct typedef = new TypedefStruct(s, it);
				typedef.exportMe();
				continue;
			}
			if (s.contains("=")) {
				final StaticVarInit varinit = new StaticVarInit(s, it);
				varinit.exportMe(pw);
				continue;
			}
			final Method method = new Method(s, it);
			if (method.containsBody()) {
				method.exportMe(pw);
			} else if (method.isStaticVarInit()) {
				final StaticVarInit staticVarInit = method.convertToStaticVarInit();
				staticVarInit.exportMe(pw);
			}
		}

		pw.println("}");

	}

	private static String allImport;

	private static String getAllImport() {
		if (allImport != null) {
			return allImport;
		}
		final File dirGen = new File("src/gen/lib");
		if (dirGen.exists() == false) {
			allImport = "";
			return allImport;
		}
		final StringBuilder sb = new StringBuilder();
		for (File dir : dirGen.listFiles()) {
			if (dir.isDirectory()) {
				final String name = dir.getName();
				for (File java : dir.listFiles()) {
					final String className = java.getName();
					if (java.isFile() && className.endsWith(".java")) {
						final String n = className.substring(0, className.length() - 5);
						sb.append("import static gen.lib." + name + "." + n + ".*;");
						sb.append("\n");
					}
				}
			}
		}
		allImport = sb.toString();
		return allImport;
	}

	private boolean ignoredLine(String s) {
		if (s.equals("typedef unsigned char boolean")) {
			return true;
		}
		if (s.matches("^1\\s*$")) {
			// Because of _BEGIN_EXTERNS_
			return true;
		}
		return false;
	}
}
