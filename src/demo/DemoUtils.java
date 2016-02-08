package demo;

import h.Agedge_s;
import h.Agedgeinfo_t;
import h.Agnode_s;
import h.Agnodeinfo_t;
import h.bezier;
import h.boxf;
import h.pointf;
import h.splines;
import smetana.core.Macro;
import smetana.core.__ptr__;
import smetana.core.__struct__;
import smetana.core.amiga.StarArrayOfPtr;
import smetana.core.amiga.StarStruct;

public class DemoUtils {

	public static void printDebugEdge(Agedge_s e) {
		System.err.println("*********** PRINT EDGE ********** " + getUID(e));
		final Agedgeinfo_t data = (Agedgeinfo_t) Macro.AGDATA(e).castTo(Agedgeinfo_t.class);
		final splines splines = (splines) data.getPtr("spl");
		__struct__<boxf> bb = splines.getStruct("bb");
		// final bezier list = (bezier) splines.getPtr("list");
		System.err.println("splines.UID=" + ((StarStruct) splines).getUID36());
		System.err.println("splines.size=" + splines.getInt("size"));
		System.err.println("bb.LL=" + pointftoString(bb.getStruct("LL")));
		System.err.println("bb.UR=" + pointftoString(bb.getStruct("UR")));
		printDebugBezier((bezier) splines.getPtr("list").getPtr());

	}

	public static String getUID(Object o) {
		if (o instanceof StarArrayOfPtr) {
			return ((StarArrayOfPtr) o).getUID36();
		}
		return ((StarStruct) o).getUID36();
	}

	public static void printDebugBezier(bezier bezier) {
		System.err.println("bezier.size=" + bezier.getInt("size"));
		System.err.println("bezier.sflag=" + bezier.getInt("sflag"));
		System.err.println("splines.eflag=" + bezier.getInt("eflag"));
		System.err.println("bezier.sp=" + pointftoString(bezier.getStruct("sp")));
		System.err.println("bezier.ep=" + pointftoString(bezier.getStruct("ep")));
		System.err.println("bezier.list=" + getUID(bezier.getPtr("list")));
		for (int i = 0; i < bezier.getInt("size"); i++) {
			final __ptr__ pt = bezier.getPtr("list").plus(i).getPtr();
			System.err.println("pt=" + pointftoString(pt));
		}

	}

	public static void printDebugNode(Agnode_s n) {
		System.err.println("*********** PRINT NODE ********** ");
		final Agnodeinfo_t data = (Agnodeinfo_t) Macro.AGDATA(n).castTo(Agnodeinfo_t.class);
		System.err.println("width=" + data.getDouble("width"));
		System.err.println("height=" + data.getDouble("height"));
		System.err.println("ht=" + data.getDouble("ht"));
		System.err.println("lw=" + data.getDouble("lw"));
		System.err.println("rw=" + data.getDouble("rw"));
		System.err.println("coord=" + pointftoString(data.getStruct("coord")));

		__struct__<boxf> bb = data.getStruct("bb");
		System.err.println("bb.LL=" + pointftoString(bb.getStruct("LL")));
		System.err.println("bb.UR=" + pointftoString(bb.getStruct("UR")));
		// TODO Auto-generated method stub
	}

	public static String pointftoString(__struct__<pointf> point) {
		final StringBuilder sb = new StringBuilder();
		sb.append("(");
		sb.append(point.getDouble("x"));
		sb.append(" ; ");
		sb.append(point.getDouble("y"));
		sb.append(")");
		return sb.toString();

	}

	public static String pointftoString(__ptr__ point) {
		final StringBuilder sb = new StringBuilder();
		sb.append("(");
		sb.append(point.getDouble("x"));
		sb.append(" ; ");
		sb.append(point.getDouble("y"));
		sb.append(")");
		return sb.toString();
	}
}
