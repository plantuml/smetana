package smetana;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.List;

public class StaticVarInit extends PieceOfCodeC {

	protected String getFolderName() {
		return "ctoj2";
	}

	public StaticVarInit(List<String> raw) {
		for (String s : raw) {
			addRaw(s);
		}
	}
	
	public StaticVarInit(String s, Iterator<String> it) {
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


	public void exportMe(PrintWriter pw) throws IOException {
		pw.println("// " + getSignature());
		pw.println("// " + getRaw().get(0).replace('\n', ' '));
		if (getCtojFile().exists()) {
			exportJavaFromCtoj(pw);
		} else {
			createCtojFile();
			createCtojFileSuppData(pw);
			pw.println();
			pw.println();
		}
	}

}
