package smetana;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Method extends PieceOfCodeC {

	protected String getFolderName() {
		return "ctoj2";
	}

	public Method(String s, Iterator<String> it) {
		if (CFile.TRACE) {
			System.err.println("STARTINGMETHOD");
		}
		addRaw(s);
		int level = 0;
		boolean exitAllowed = true;
		while (it.hasNext()) {
			if (level == 0 && s.matches("[\\s\\S]*\\)[\\s\\S]*\\w")) {
				exitAllowed = false;
			}
			if (CFile.TRACE) {
				System.err.println("s=" + s);
			}
			s = it.next();
			if (level == 0 && s.matches("[\\s\\S]*\\)[\\s\\S]*\\w")) {
				exitAllowed = false;
			}
			addRaw(s);
			if (s.equals("{")) {
				level++;
				exitAllowed = true;
			} else if (s.equals("}")) {
				level--;
			}
			if (exitAllowed && level == 0 && (s.equals(";") || s.equals("}"))) {
				if (CFile.TRACE) {
					System.err.println("ENDING");
				}
				return;
			}
		}
	}

	private String getMethodName() {
		final Pattern p = Pattern.compile("\\b(\\w+)\\s*\\(");
		final Matcher m = p.matcher(getRaw().get(0));
		if (m.find() == false) {
			System.err.println("error " + getRaw());
			// return "NOTFOUND";
			throw new IllegalStateException(getRaw().get(0));
		}
		final String result = m.group(1);
		if (result.equals("clone")) {
			return result + "_";
		}
		return result;

	}

	public String toString() {
		return getRaw().get(0);
	}

	public boolean containsBody() {
		for (String s : getRaw()) {
			if (s.contains("{")) {
				return true;
			}
		}
		return false;
	}

	public StaticVarInit convertToStaticVarInit() {
		return new StaticVarInit(getRaw());
	}

	protected void createCtojFileSuppData(PrintWriter pw) throws IOException {
		final String methodName = getMethodName();
		pw.println("public static Object " + methodName + "() {");
		pw.println("throw new UnsupportedOperationException();");
		pw.println("}");
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

	public boolean isStaticVarInit() {
		final String compact = getCompactString();
		return compact.contains("(") == false;
	}

}
