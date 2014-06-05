package h;
import core.*;
import core.annotation.*;

// 5ho0f0m8hitlfq9j032lww947

@TranslatedBy("plantuml") 
public class Agraph_s extends Structure {
    public final Agobj_t base = new Agobj_t(this);
    public final Agdesc_t desc = new Agdesc_t();
    public final Dtlink_t link = new Dtlink_t();
    public Dict_t n_seq;		/* the node set in sequence */
    public Dict_t n_id;		/* the node set indexed by ID */
    public Dict_t e_seq, e_id;	/* holders for edge sets */
    public Dict_t g_dict;		/* subgraphs - descendants */
    public Agraph_t parent, root;	/* subgraphs - ancestors */
    public Agclos_t clos;		/* shared resources */
    
	public StarVoid castTo(Class clazz) {
		if (clazz==Agobj_t.class || clazz==Agobj_s.class) {
			return base;
		}
		return super.castTo(clazz);
	}
	
	public void reset() {
	    base.reset();
	    desc.reset();
	    link.reset();
	    n_seq = null;
	    n_id = null;
	    e_seq = e_id = null;
	    g_dict = null;
	    parent = root = null;
	    clos = null;
	}
}

// struct Agraph_s {
//     Agobj_t base;
//     Agdesc_t desc;
//     Dtlink_t link;
//     Dict_t *n_seq;		/* the node set in sequence */
//     Dict_t *n_id;		/* the node set indexed by ID */
//     Dict_t *e_seq, *e_id;	/* holders for edge sets */
//     Dict_t *g_dict;		/* subgraphs - descendants */
//     Agraph_t *parent, *root;	/* subgraphs - ancestors */
//     Agclos_t *clos;		/* shared resources */
// };