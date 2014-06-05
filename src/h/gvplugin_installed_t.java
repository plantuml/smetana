package h;
import core.*;
import core.annotation.*;

// dcmpl8ruksxab5p8161qcvxcw

@TranslatedBy("plantuml")
public class gvplugin_installed_t extends Structure {
	public int id;         /* an id that is only unique within a package 
			of plugins of the same api.
			A renderer-type such as "png" in the cairo package
			has an id that is different from the "ps" type
			in the same package */
	public StarChar type;	/* a string name, such as "png" or "ps" that
			distinguishes different types withing the same
			 (renderer in this case) */
	public int quality;    /* an arbitrary integer used for ordering plugins of
			the same type from different packages */
	public StarVoid engine;   /* pointer to the jump table for the plugin */
	public StarVoid features; /* pointer to the feature description 
				void* because type varies by api */

	public gvplugin_installed_t(int id, StarChar type, int quality, StarVoid engine, StarVoid features) {
		this.id = id;
		this.type = type;
		this.quality = quality;
		this.engine = engine;
		this.features = features;
	}

}

// typedef struct {
// 	int id;         /* an id that is only unique within a package 
// 			of plugins of the same api.
// 			A renderer-type such as "png" in the cairo package
// 			has an id that is different from the "ps" type
// 			in the same package */
// 	const char *type;	/* a string name, such as "png" or "ps" that
// 			distinguishes different types withing the same
// 			 (renderer in this case) */
// 	int quality;    /* an arbitrary integer used for ordering plugins of
// 			the same type from different packages */
// 	void *engine;   /* pointer to the jump table for the plugin */
// 	void *features; /* pointer to the feature description 
// 				void* because type varies by api */
//     } gvplugin_installed_t;