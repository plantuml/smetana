package preprocessor;

import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;

import org.anarres.cpp.Main;

/*
 * Execute C preprocessor on a single C file.
 * Generates file in kgraphviz-2.28.0 folder
 * 
 */
public class PreprocFileC {
	private final String path;

	public PreprocFileC(String f) {
		if (new File(f).exists() == false) {
			throw new IllegalArgumentException();
		}
		this.path = f;
	}

	public void process() throws Exception {
		final List<String> arg = new ArrayList<String>();
		arg.add("-DHAVE_CONFIG_H");
		addPath(arg);
		arg.add("-DDOT_ONLY");
		addPath(arg);
		arg.add("-D__STD_C");
		addPath(arg);
		arg.add("-D_BEGIN_EXTERNS_");
		addPath(arg);
		arg.add(path);
		System.err.println(arg);
		PrintStream old = System.out;
		final String newFile = "k" + path;
		new File(newFile).getParentFile().mkdirs();
		PrintStream ps = new PrintStream(newFile);
		System.setOut(ps);
		Main.main(arg.toArray(new String[0]));
		ps.close();
		System.setOut(old);
	}

	// Add all .h directory for preprocessor
	private void addPath(List<String> arg) {
		for (File f : new File(PreprocDirC.GRAPHVIZ_2_38_0 + "/lib").listFiles()) {
			if (f.isDirectory()) {
				arg.add("-I");
				arg.add(PreprocDirC.GRAPHVIZ_2_38_0 + "/lib/" + f.getName());
			}
		}
	}

	// public static void main(String[] args) throws Exception {
	// FileC fc = new FileC("graphviz-2.28.0/lib/dotgen2/dotinit.c");
	// fc.process();
	// }

}
