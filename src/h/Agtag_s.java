package h;
import core.*;
import core.annotation.*;

// f4eovs59su6ztmd1h9rq229c2

@TranslatedBy("plantuml")
public class Agtag_s extends Structure {
	public int objtype;
    public boolean mtflock;		/* move-to-front lock, see above */
    public boolean attrwf;		/* attrs written (parity, write.c) */
    public int seq;	/* sequence no. */
	public @Unsigned Int id;
	
	public void reset() {
	    objtype = 0;
	    mtflock = false;
	    attrwf = false;
	    seq = 0;
	    id = null;
	}
	public void copyFrom(Structure o) {
		Agtag_s other = (Agtag_s) o;
		this.objtype = other.objtype;
		this.mtflock = other.mtflock;
		this.attrwf = other.attrwf;
		this.seq = other.seq;
		this.id = other.id;
		System.err.println("Warning : id are shared and not copied");
	}
}

// struct Agtag_s {
//     unsigned objtype:2;		/* see literal tags below */
//     unsigned mtflock:1;		/* move-to-front lock, see above */
//     unsigned attrwf:1;		/* attrs written (parity, write.c) */
//     unsigned seq:(sizeof(unsigned) * 8 - 4);	/* sequence no. */
//     unsigned long id;		/* client  ID */
// };