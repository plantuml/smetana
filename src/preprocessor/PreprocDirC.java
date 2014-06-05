package preprocessor;

import java.io.File;

/*
 * Preprocessing of all lib folder and subfolder.
 * Generated kgraphviz-2.28.0 folders.
 */
public class PreprocDirC {

	public static final String GRAPHVIZ_2_38_0 = "graphviz-2.38.0";
	final private File dir;

	public PreprocDirC(File dir) {
		this.dir = dir;
	}

	public void process() throws Exception {
		for (File f : dir.listFiles()) {
			if (f.isDirectory()) {
				new PreprocDirC(f).process();
			} else if (f.isFile() && f.getName().endsWith(".c")) {
				new PreprocFileC(f.getPath()).process();
			}
		}

	}

	public static void main(String[] args) throws Exception {
		new PreprocDirC(new File(GRAPHVIZ_2_38_0 + "/lib")).process();
		new PreprocDirC(new File(GRAPHVIZ_2_38_0 + "/plugin")).process();
	}

}
