package smetana.job;

import java.io.File;
import java.io.IOException;


/*
 * Preprocessing of all lib folder and subfolder.
 * Generated kgraphviz-2.28.0 folders.
 */
public class LastModif {

	private File recentFile;

	public void process(File dir) throws Exception {
		for (File f : dir.listFiles()) {
			if (f.isFile() && f.getName().endsWith(".ctoj")) {
				if (recentFile == null || f.lastModified() > recentFile.lastModified()) {
					recentFile = f;
				}
			}
		}
	}

	public void updateJavaFiles() throws IOException {
		String s = recentFile.getName();
		s = s.substring(0, s.length() - 5);
		System.err.println("recentFile=" + s);
		// new DirJava(new File("src/gen")).process(s);
		// new DirJava(new File("src/h")).process(s);

		DirkC dir = new DirkC(new File(DirkC.KGRAPHVIZ_2_38_0 + "/lib"));
		dir.process(s);

	}

	public static void main(String[] args) throws Exception {
		final LastModif lastModif = new LastModif();
		lastModif.process(new File("ctoj1"));
		lastModif.process(new File("ctoj2"));
		System.err.println("lastModif=" + lastModif.recentFile);
		lastModif.updateJavaFiles();
	}

}
