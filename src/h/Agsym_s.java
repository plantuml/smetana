package h;
import core.*;
import core.annotation.*;

// 38c2s12koxcpi2c7vwl72qrsp

@TranslatedBy("plantuml")
public class Agsym_s extends Structure {
	public final Dtlink_t link = new Dtlink_t(this);
	public StarChar name; /* attribute's name */
	public StarChar defval; /* its default value for initialization */
	public int id; /* its index in attr[] */
	public int kind; /* referent object type */
	public int fixed; /* immutable value */
	public int print; /* always print */

	public void reset() {
		link.reset();
		name = null;
		defval = null;
		id = 0;
		kind = 0;
		fixed = 0;
		print = 0;
	}

	public StarVoid substractByte(OFFSET offset) {
		if (getClass() != offset.reference) {
			throw new IllegalStateException();
		}
		if (offset.name.equals("link")) {
			return this;
		}
		System.err.println("OFFSET=" + offset);
		throw new UnsupportedOperationException();
	}
	public StarVoid ASREF(String nam) {
		if (nam.equals("link")) {
			return link;
		}
		if (nam.equals("name")) {
			return new StarStarCharAdapter() {
				public StarChar get() {
					return name;
				}

				public StarChar set(StarChar data) {
					name = data;
					return name;
				}
			};
		}
		return super.ASREF(nam);
	}
}


// struct Agsym_s {		/* symbol in one of the above dictionaries */
//     Dtlink_t link;
//     char *name;			/* attribute's name */
//     char *defval;		/* its default value for initialization */
//     int id;			/* its index in attr[] */
//     unsigned char kind;		/* referent object type */
//     unsigned char fixed;	/* immutable value */
//     unsigned char print;	/* always print */
// };