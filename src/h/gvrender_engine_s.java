package h;
import core.*;
import core.annotation.*;

// c9lcfmvndhmluehnjakiea1ei

public class gvrender_engine_s {
}

// struct gvrender_engine_s {
// 	void (*begin_job) (GVJ_t * job);
// 	void (*end_job) (GVJ_t * job);
// 	void (*begin_graph) (GVJ_t * job);
// 	void (*end_graph) (GVJ_t * job);
// 	void (*begin_layer) (GVJ_t * job, char *layername,
// 			     int layerNum, int numLayers);
// 	void (*end_layer) (GVJ_t * job);
// 	void (*begin_page) (GVJ_t * job);
// 	void (*end_page) (GVJ_t * job);
// 	void (*begin_cluster) (GVJ_t * job);
// 	void (*end_cluster) (GVJ_t * job);
// 	void (*begin_nodes) (GVJ_t * job);
// 	void (*end_nodes) (GVJ_t * job);
// 	void (*begin_edges) (GVJ_t * job);
// 	void (*end_edges) (GVJ_t * job);
// 	void (*begin_node) (GVJ_t * job);
// 	void (*end_node) (GVJ_t * job);
// 	void (*begin_edge) (GVJ_t * job);
// 	void (*end_edge) (GVJ_t * job);
// 	void (*begin_anchor) (GVJ_t * job,
// 		char *href, char *tooltip, char *target, char *id);
// 	void (*end_anchor) (GVJ_t * job);
// 	void (*begin_label) (GVJ_t * job, label_type type);
// 	void (*end_label) (GVJ_t * job);
// 	void (*textspan) (GVJ_t * job, pointf p, textspan_t * span);
// 	void (*resolve_color) (GVJ_t * job, gvcolor_t * color);
// 	void (*ellipse) (GVJ_t * job, pointf * A, int filled);
// 	void (*polygon) (GVJ_t * job, pointf * A, int n, int filled);
// 	void (*beziercurve) (GVJ_t * job, pointf * A, int n,
// 			     int arrow_at_start, int arrow_at_end, int);
// 	void (*polyline) (GVJ_t * job, pointf * A, int n);
// 	void (*comment) (GVJ_t * job, char *comment);
// 	void (*library_shape) (GVJ_t * job, char *name, pointf * A, int n, int filled);
//     };