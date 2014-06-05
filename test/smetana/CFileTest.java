package smetana;

import java.io.File;
import java.io.IOException;

import junit.framework.TestCase;

public class CFileTest extends TestCase {

	public void testToJavaFileFile() throws IOException {
		// File f = new File("kgraphviz-2.38.0/lib/dotgen/dotinit.c");
		// File f = new File("kgraphviz-2.38.0/lib/common/labels.c");
		// File f = new File("kgraphviz-2.38.0/lib/cdt/dtclose.c");
		// File f = new File("kgraphviz-2.38.0/lib/common/ellipse.c");
		// File f = new File("kgraphviz-2.38.0/lib/cgraph/y.tab.c");
		// File f = new File("kgraphviz-2.38.0/lib/ast/pathfind.c");
		// File f = new File("kgraphviz-2.38.0/lib/ast/strton.c");
		// File f = new File("kgraphviz-2.38.0/lib/cgraph/grammar.c");
		// File f = new File("kgraphviz-2.38.0/lib/cgraph/main.c");
		// File f = new File("kgraphviz-2.38.0/lib/common/ellipse.c");
		// File f = new File("kgraphviz-2.38.0/lib/dotgen/acyclic.c");
		// File f = new File("kgraphviz-2.38.0/lib/glcomp/glcompset.c");
		// File f = new File("kgraphviz-2.38.0/lib/gvc/regex_win32.c");
		// File f = new File("kgraphviz-2.38.0/lib/gvc/gvc.c");
		// File f = new File("kgraphviz-2.38.0/lib/cgraph/agerror.c");
		File f = new File("kgraphviz-2.38.0/lib/cgraph/attr.c");
		// File f = new File("kgraphviz-2.38.0/lib/circogen/block.c");
		CFile cfile = new CFile(f);

		cfile.toJavaFile();

	}

}
