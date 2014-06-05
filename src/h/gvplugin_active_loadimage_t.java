package h;
import core.*;
import core.annotation.*;

// 633mt1gwzq159n5j6n0lzgzam

@TranslatedBy("plantuml")
public class gvplugin_active_loadimage_t extends Structure {
	public gvloadimage_engine_t engine;
	public int id;
	public StarChar type;

	public void reset() {
		engine = null;
		id = 0;
		type = null;
	}

}

// typedef struct gvplugin_active_loadimage_t {
// 	gvloadimage_engine_t *engine;
// 	int id;
// 	const char *type;
//     } gvplugin_active_loadimage_t;