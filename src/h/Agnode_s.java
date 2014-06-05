package h;
import core.*;
import core.annotation.*;

// 5h58ys5dc8q21vir1hk2r7xr7

@TranslatedBy("plantuml") 
public class Agnode_s extends Structure {
    final public Agobj_t base = new Agobj_t(this);
    public Agraph_t root;
    final public Agsubnode_t mainsub = new Agsubnode_t();	/* embedded for main graph */
    public void reset() {
    	base.reset();
    	root = null;
    	mainsub.reset();
    }
	public StarVoid castTo(Class clazz) {
		if (clazz==Agobj_t.class) {
			return base;
		}
		return super.castTo(clazz);
	}
}

// struct Agnode_s {
//     Agobj_t base;
//     Agraph_t *root;
//     Agsubnode_t mainsub;	/* embedded for main graph */
// };