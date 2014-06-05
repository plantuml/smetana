package smetana;

import java.io.File;
import java.io.IOException;

import junit.framework.TestCase;

public class FileStringParserTest extends TestCase {

	public void testFileStringParserFile() throws IOException {
		File f = new File("kgraphviz-2.38.0/lib/dotgen/dotinit.c");
		FileStringParser parser = new FileStringParser(f);

		 for (String s : parser) {
		 System.err.println("<" + s + ">");
		 }

//		final Iterator<String> it = parser.iterator();
//		for (int i = 0; i < 3000; i++) {
//			System.err.println("<" + it.next() + ">");
//		}
	}

}
