package h;
import core.*;
import core.annotation.*;

// c5u1u6iz4msxf9y4q5w78w22

@TranslatedBy("plantuml")
public class gvplugin_active_device_t extends Structure {
        public gvdevice_engine_t engine;
        public int id;
        public gvdevice_features_t features;
        public StarChar type;
        
        public void reset() {
        	engine = null;
        	id = 0;
        	features = null;
        	type = null;
        }
        
}

// typedef struct gvplugin_active_device_s {
//         gvdevice_engine_t *engine;
//         int id;
//         gvdevice_features_t *features;
//         const char *type;
//     } gvplugin_active_device_t;