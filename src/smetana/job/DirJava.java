package smetana.job;

import java.io.File;
import java.io.IOException;

/*
 * Preprocessing of all lib folder and subfolder.
 * Generated kgraphviz-2.28.0 folders.
 */
public class DirJava {

	final private File dir;

	public DirJava(File dir) {
		this.dir = dir;
	}

	public void process(String stringToDetect) throws IOException {
		for (File f : dir.listFiles()) {
			if (f.isDirectory()) {
				new DirJava(f).process(stringToDetect);
			} else if (f.isFile() && f.getName().endsWith(".java")) {
				System.err.println(f);
			}
		}

	}

}
