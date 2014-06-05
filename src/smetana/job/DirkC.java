package smetana.job;

import java.io.File;
import java.io.IOException;

import smetana.CFile;

/*
 * Preprocessing of all lib folder and subfolder.
 * Generated kgraphviz-2.28.0 folders.
 */
public class DirkC {

	public static final String KGRAPHVIZ_2_38_0 = "kgraphviz-2.38.0";
	final private File dir;

	public DirkC(File dir) {
		this.dir = dir;
	}

	public void process() throws Exception {
		for (File f : dir.listFiles()) {
			if (f.isDirectory()) {
				new DirkC(f).process();
			} else if (f.isFile() && f.getName().endsWith(".c")) {
				new CFile(f).toJavaFile();
			}
		}
	}

	public void process(String stringToDetect) throws IOException {
		for (File f : dir.listFiles()) {
			if (f.isDirectory()) {
				new DirkC(f).process(stringToDetect);
			} else if (f.isFile() && f.getName().endsWith(".c")) {
				new CFile(f).toJavaFile(stringToDetect);
			}
		}
	}

	public static void main(String[] args) throws Exception {
		new DirkC(new File(KGRAPHVIZ_2_38_0 + "/lib")).process();
		new DirkC(new File(KGRAPHVIZ_2_38_0 + "/plugin")).process();
	}

}
