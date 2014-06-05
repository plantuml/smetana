package h;
import core.*;
import core.annotation.*;

// 4af9oysh9wk1u0m5wjc60jcr3

@TranslatedBy("plantuml") 
public class gvplugin_active_render_t extends Structure {
        public gvrender_engine_t engine;
        public int id;
        public gvrender_features_t features;
        public StarChar type;
        
        public void reset() {
	        engine = null;
	        id = 0;
	        features = null;
	        type = null;
        }
}

// typedef struct gvplugin_active_render_s {
//         gvrender_engine_t *engine;
//         int id;
//         gvrender_features_t *features;
//         const char *type;
//     } gvplugin_active_render_t;