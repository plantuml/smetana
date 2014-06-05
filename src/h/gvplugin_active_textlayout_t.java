package h;
import core.*;
import core.annotation.*;

// 4ht0rt62yul08h6v5kje6jk1x

@TranslatedBy("plantuml")
public class gvplugin_active_textlayout_t extends Structure {
        public gvtextlayout_engine_t engine;
        public int id;
        public StarChar type;
        
        public void reset() {
            engine = null;
            id = 0;
            type = null;
        }
}

// typedef struct gvplugin_active_textlayout_s {
//         gvtextlayout_engine_t *engine;
//         int id;
//         char *type;
//     } gvplugin_active_textlayout_t;