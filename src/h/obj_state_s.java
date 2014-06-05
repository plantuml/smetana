package h;
import core.*;
import core.annotation.*;

// 7rfvc65ygzocig64xmd4vm8m8

public class obj_state_s {
}

// struct obj_state_s {
// 	obj_state_t *parent;
// 
// 	obj_type type;
// 	union {
// 	    graph_t *g;
// 	    graph_t *sg;  
// 	    node_t *n;
// 	    edge_t *e;
// 	} u;
// 
// 	emit_state_t emit_state; 
// 
// 	gvcolor_t pencolor, fillcolor, stopcolor;
// 	int gradient_angle;
// 	float gradient_frac;
// 	pen_type pen;
// 	fill_type fill;
// 	double penwidth;
// 	char **rawstyle;
// 
// 	double z, tail_z, head_z;   /* z depths for 2.5D renderers such as vrml */
// 
// 	/* fully substituted text strings */
// 	char *label;
// 	char *xlabel;
// 	char *taillabel;
// 	char *headlabel; 
// 
// 	char *url;              /* if GVRENDER_DOES_MAPS */
// 	char *id;
// 	char *labelurl;
// 	char *tailurl;
// 	char *headurl; 
// 
// 	char *tooltip;          /* if GVRENDER_DOES_TOOLTIPS */
// 	char *labeltooltip;
// 	char *tailtooltip;
// 	char *headtooltip; 
// 
// 	char *target;           /* if GVRENDER_DOES_TARGETS */
// 	char *labeltarget;
// 	char *tailtarget;
// 	char *headtarget; 
// 
// 	int explicit_tooltip:1;
// 	int explicit_tailtooltip:1;
// 	int explicit_headtooltip:1;
// 	int explicit_labeltooltip:1;
// 	int explicit_tailtarget:1;
// 	int explicit_headtarget:1;
// 	int explicit_edgetarget:1;
// 	int explicit_tailurl:1;
// 	int explicit_headurl:1;
// 
// 	/* primary mapped region - node shape, edge labels */
// 	map_shape_t url_map_shape; 
// 	int url_map_n;                  /* number of points for url map if GVRENDER_DOES_MAPS */
// 	pointf *url_map_p;
// 
// 	/* additonal mapped regions for edges */
// 	int url_bsplinemap_poly_n;      /* number of polygons in url bspline map
// 					 if GVRENDER_DOES_MAPS && GVRENDER_DOES_MAP_BSPLINES */
// 	int *url_bsplinemap_n;          /* array of url_bsplinemap_poly_n ints 
// 					 of number of points in each polygon */
// 	pointf *url_bsplinemap_p;       /* all the polygon points */
// 
// 	int tailendurl_map_n;           /* tail end intersection with node */
// 	pointf *tailendurl_map_p;
// 
// 	int headendurl_map_n;           /* head end intersection with node */
// 	pointf *headendurl_map_p;
//     };