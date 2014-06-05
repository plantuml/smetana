package h;
import core.*;
import core.annotation.*;

// 7fv7yqhmqaa7u2qszrcz1x603

@TranslatedBy("plantuml") 
public class Agobj_s extends Structure {
	public final Agtag_t tag = new Agtag_t();
	public Agrec_t data;
	
	public void reset() {
	    tag.reset();
	    data = null;
	}

	public Agobj_s(Object parentStructure) {
		super(parentStructure);
	}

	public StarVoid castTo(Class clazz) {
		if (clazz == Agobj_t.class) {
			return this;
		}
		return super.castTo(clazz);
	}
}

// struct Agobj_s {
//     Agtag_t tag;
//     Agrec_t *data;
// };