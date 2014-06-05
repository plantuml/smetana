package h;
import core.*;
import core.annotation.*;

// eo8sfsh5lby147igpryzvitu7

@TranslatedBy("plantuml")
public class Agclos_s extends Structure {
	final public Agdisc_t disc = new Agdisc_t(); /* resource discipline functions */
	final public Agdstate_t state = new Agdstate_t(); /* resource closures */
	public Dict_t strdict; /* shared string dict */
	public @Unsigned int seq[] = new int[3]; /* local object sequence number counter */
	public Agcbstack_t cb; /* user and system callback function stacks */
	public boolean callbacks_enabled; /* issue user callbacks or hold them? */
	
	public void reset() {
	    disc.reset();
	    state.reset();
	    strdict = null;
	    seq[0] = seq[1] = seq[2] = 0;
	    cb = null;
	    callbacks_enabled = false;
	}

	// public Dict_t *lookup_by_name[3];
	// public Dict_t *lookup_by_id[3];

	public StarVoid ASREF(String name) {
		if (name.equals("strdict")) {
			return new StarStarAdapter<Dict_t>() {
				public Dict_t get() {
					return strdict;
				}

				public void set(Dict_t value) {
					strdict = value;
				}
			};

		}
		return super.ASREF(name);
	}

}

// struct Agclos_s {
//     Agdisc_t disc;		/* resource discipline functions */
//     Agdstate_t state;		/* resource closures */
//     Dict_t *strdict;		/* shared string dict */
//     unsigned long seq[3];	/* local object sequence number counter */
//     Agcbstack_t *cb;		/* user and system callback function stacks */
//     unsigned char callbacks_enabled;	/* issue user callbacks or hold them? */
//     Dict_t *lookup_by_name[3];
//     Dict_t *lookup_by_id[3];
// };