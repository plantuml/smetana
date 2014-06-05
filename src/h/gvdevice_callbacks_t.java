package h;
import core.*;
import core.annotation.*;

// f3e0bdxm3k2e7dwusmutjfhyg

public class gvdevice_callbacks_t {
}

// typedef struct gvdevice_callbacks_s {
// 	void (*refresh) (GVJ_t * job);
//         void (*button_press) (GVJ_t * job, int button, pointf pointer);
//         void (*button_release) (GVJ_t * job, int button, pointf pointer);
//         void (*motion) (GVJ_t * job, pointf pointer);
//         void (*modify) (GVJ_t * job, const char *name, const char *value);
//         void (*del) (GVJ_t * job);  /* can't use "delete" 'cos C++ stole it */
//         void (*read) (GVJ_t * job, const char *filename, const char *layout);
//         void (*layout) (GVJ_t * job, const char *layout);
//         void (*render) (GVJ_t * job, const char *format, const char *filename);
//     } gvdevice_callbacks_t;