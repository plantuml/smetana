package h;
import core.*;
import core.annotation.*;

// 1wbtv41cwqamseppeo0vb4kjf

@TranslatedBy("plantuml")
public class Agdatadict_s extends Structure {
    public final Agrec_t h = new Agrec_t(this);			/* installed in list of graph recs */
    static public class dict extends Structure {
		public Dict_t n, e, g;
	public void reset() { n=e=g=null; }
    };
    public final dict dict = new dict();
    
    public void reset() {
       h.reset();
       dict.reset();
    }
	public StarVoid castTo(Class clazz) {
		if (clazz==Agrec_t.class) {
			return h;
		}
		return super.castTo(clazz);
	}
}

// struct Agdatadict_s {		/* set of dictionaries per graph */
//     Agrec_t h;			/* installed in list of graph recs */
//     struct {
// 	Dict_t *n, *e, *g;
//     } dict;
// };