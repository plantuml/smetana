package h;
import core.*;
import core.annotation.*;

// bhyg6b8o9rt02pkq0cw5v7v8l

@TranslatedBy("plantuml")
public class Agattr_s extends Structure {
    public final Agrec_t h = new Agrec_t(this);			/* common data header */
    public Dict_t dict;		/* shared dict to interpret attr field */
    public StarStarChar str;			/* the attribute string values */
    
    public void reset() {
    	h.reset();
    	dict = null;
    	str = null;
    }
	public StarVoid castTo(Class clazz) {
		if (clazz==Agrec_t.class) {
			return h;
		}
		return super.castTo(clazz);
	}
}

// struct Agattr_s {		/* dynamic string attributes */
//     Agrec_t h;			/* common data header */
//     Dict_t *dict;		/* shared dict to interpret attr field */
//     char **str;			/* the attribute string values */
// };