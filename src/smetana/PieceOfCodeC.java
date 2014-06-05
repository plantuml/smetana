package smetana;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public abstract class PieceOfCodeC {

	private final List<String> raw = new ArrayList<String>();

	final protected void addRaw(String s) {
		raw.add(s);
	}

	abstract protected String getFolderName();

	final protected void exportJavaFromCtoj(PrintWriter pw) throws IOException {
		final BufferedReader br = new BufferedReader(new FileReader(getCtojFile()));
		String s;
		boolean translatedByPresent = false;
		while ((s = br.readLine()) != null) {
			if (s.contains("@TranslatedBy(\"")) {
				translatedByPresent = true;
			}
			if (s.startsWith("!!!!!")) {
				br.close();
				if (translatedByPresent == false) {
					final String msg = "Missing @TranslatedBy in " + getCtojFile().getName();
					System.err.println(msg);
					throw new IOException(msg);
				}
				return;
			}
			pw.println(s);
		}
		br.close();
		throw new IllegalStateException();
	}

	final protected File getCtojFile() {
		return new File(getFolderName(), getSignature() + ".ctoj");
	}

	private static final Set<File> alreadyCreated = new HashSet<File>();

	final protected void createCtojFile() throws IOException {
		if (getCtojFile().exists()) {
			return;
		}
		final File tmpFile = new File(getFolderName(), getSignature() + ".tmp");
		if (alreadyCreated.contains(tmpFile)) {
			return;
		}
		alreadyCreated.add(tmpFile);
		tmpFile.getParentFile().mkdirs();
		final PrintWriter pw = new PrintWriter(tmpFile);

		createCtojFileSuppData(pw);
		pw.println();
		pw.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		final StringBuilder code = new StringBuilder();
		for (String s : raw) {
			code.append(s);
		}
		final StringTokenizer st = new StringTokenizer(code.toString(), "\n");
		while (st.hasMoreTokens()) {
			final String s = st.nextToken();
			if (s.matches("^\\s*$")) {
				continue;
			}
			pw.println(s);
		}
		pw.println();
		pw.close();
	}

	protected void createCtojFileSuppData(PrintWriter pw) throws IOException {
	}

	final protected String getSignature() {
		final Signer signer = new Signer();
		signer.addLine(getCompactString().replaceAll("\\s", ""));
		return signer.getSignature();
	}

	final protected String getCompactString() {
		final StringBuilder sb = new StringBuilder();
		for (String s : raw) {
			if (s.startsWith("//")) {
				continue;
			}
			if (s.startsWith("/*")) {
				continue;
			}
			s = s.replace('\n', ' ');
			sb.append(s);
		}
		return sb.toString();
	}

	final public List<String> getRaw() {
		return Collections.unmodifiableList(raw);
	}

}
