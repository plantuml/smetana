package smetana;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TypedefStruct extends PieceOfCodeC {

	public static final String TYPEDEF_STRUCT = "typedef struct";

	protected String getFolderName() {
		return "ctoj1";
	}

	public TypedefStruct(String s, Iterator<String> it) {
		addRaw(s);
		int level = 0;
		while (it.hasNext()) {
			s = it.next();
			addRaw(s);
			if (s.equals("{")) {
				level++;
			} else if (s.equals("}")) {
				level--;
			}
			if (level == 0 && s.equals(";")) {
				return;
			}
		}
	}

	private static Set<String> already = new HashSet<String>();

	public void exportMe() throws IOException {
		final String n = getClassName();
		if (already.contains(n)) {
			return;
		}
		already.add(n);
		createJavaFile();
		createCtojFile();
	}

	private void createJavaFile() throws IOException {
		String path = "src/h";
		final File javaFile = new File(path, getClassName() + ".java");
		javaFile.getParentFile().mkdirs();
		final PrintWriter pw = new PrintWriter(javaFile);
		pw.println("package h;");
		pw.println("import core.*;");
		pw.println("import core.annotation.*;");
		pw.println();
		pw.println("// " + getSignature());
		pw.println();
		if (getCtojFile().exists()) {
			exportJavaFromCtoj(pw);
		} else {
			pw.println("public class " + getClassName() + " {");
			pw.println("}");
		}
		pw.println();
		pw.print("// ");
		for (String s : getRaw()) {
			s = s.replaceAll("\n", "\n// ");
			pw.print(s);
		}
		pw.close();
	}

	public String getClassName() {
		final Pattern p0 = Pattern.compile("typedef\\s+struct\\s+\\w+\\s+(\\w+)");
		final Matcher m0 = p0.matcher(getRaw().get(0));
		if (m0.find()) {
			return manageUppercase(m0.group(1));
		}
		final Pattern p1 = Pattern.compile("typedef\\s+struct\\s*\\w*\\s*\\{.+\\}\\s*(\\w+)\\s*;\\s*$");
		final Matcher m1 = p1.matcher(getCompactString());
		if (m1.find()) {
			return manageUppercase(m1.group(1));
		}
		final Pattern p3 = Pattern.compile("struct\\s+(\\w+)");
		final Matcher m3 = p3.matcher(getRaw().get(0));
		if (m3.find()) {
			return manageUppercase(m3.group(1));
		}
		final String last = getRaw().get(getRaw().size() - 2).trim();
		if (last.matches("^\\w+$")) {
			return manageUppercase(last);
		}
		final Pattern p4 = Pattern.compile("typedef\\s+.*\\(\\*(\\w+)\\)");
		final Matcher m4 = p4.matcher(getRaw().get(0));
		if (m4.find()) {
			return manageUppercase(m4.group(1));
		}
		System.err.println("err1");
		System.err.println(getRaw());
		throw new IllegalStateException();
	}

	private String manageUppercase(String s) {
		// multispline.c contains ipair and Ipair...
		// So we have to do something to upercase letter...
		if (s.equals("Ipair")) {
			return "_Ipair";
		}
		if (s.equals("Queue")) {
			return "_Queue";
		}
		if (s.equals("Block_t")) {
			return "_Block_t";
		}
		if (s.equals("Freeblock")) {
			return "_Freeblock";
		}
		if (s.equals("Freelist")) {
			return "_Freelist";
		}
		if (s.equals("Freenode")) {
			return "_Freenode";
		}
		if (s.equals("PtItem")) {
			return "_PtItem";
		}
		if (s.equals("Node_t")) {
			return "_Note_t___";
		}
		if (s.equals("Pair")) {
			return "_Pair";
		}
		if (s.equals("Point")) {
			return "_Point";
		}
		// final StringBuilder sb = new StringBuilder();
		// for (int i = 0; i < s.length(); i++) {
		// final char c = s.charAt(i);
		// if (Character.isUpperCase(c)) {
		// sb.append("_" + c + "_");
		// } else {
		// sb.append(c);
		// }
		// }
		return s;
	}

}
