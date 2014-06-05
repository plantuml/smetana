package h;
import core.*;
import core.annotation.*;

// clpjw996k49ieh47hl09lwwq1

@TranslatedBy("plantuml")
public class GVC_s extends Structure {
	public final GVCOMMON_t common = new GVCOMMON_t(this);

	public StarChar config_path;
	public boolean config_found;
	
		/* gvParseArgs */
	public StarStarChar input_filenames; /* null terminated array of input filenames */

	/* gvNextInputGraph() */
	public GVG_t gvgs;	/* linked list of graphs */
	public GVG_t gvg;	/* current graph */

	/* plugins */

	/* APIS expands to "+1 +1 ... +1" to give the number of APIs */
	public final gvplugin_available_t[] apis = new gvplugin_available_t[+1 +1 +1 +1 +1];
	public final gvplugin_available_t[] api = new gvplugin_available_t[+1 +1 +1 +1 +1];
	//gvplugin_available_t *apis[ +1 +1 +1 +1 +1 ]; /* array of linked-list of plugins per api */
	//gvplugin_available_t *api[ +1 +1 +1 +1 +1 ];  /* array of current plugins per api */

	public gvplugin_package_t packages;   /* list of available packages */

        /* externally provided write() displine */
	//size_t (*write_fn) (GVJ_t *job, const char *s, size_t len);

	/* fonts and textlayout */
	public final Dtdisc_t textfont_disc = new Dtdisc_t(this);
	public Dict_t textfont_dt;
	public final gvplugin_active_textlayout_t textlayout = new gvplugin_active_textlayout_t(); /* always use best avail for all jobs */
//	void (*free_layout) (void *layout);   /* function for freeing layouts (mostly used by pango) */
	
/* FIXME - everything below should probably move to GVG_t */

	/* gvrender_config() */
	public GVJ_t jobs;	/* linked list of jobs */
	public GVJ_t job;	/* current job */

	public graph_t g;      /* current graph */

	/* gvrender_begin_job() */
	public final gvplugin_active_layout_t layout = new gvplugin_active_layout_t();

	public StarChar graphname;	/* name from graph */
	public GVJ_t active_jobs;   /* linked list of active jobs */

	/* pagination */
	public StarChar pagedir;		/* pagination order */
	public final pointf margin = new pointf();		/* margins in graph units */
	public final pointf pad = new pointf();		/* pad in graph units */
	public final pointf pageSize = new pointf();	/* pageSize in graph units, not including margins */
	public final point pb = new point();		/* page size - including margins (inches) */
	public final boxf bb = new boxf();		/* graph bb in graph units, not including margins */
	public int rotation;		/* rotation - 0 = portrait, 90 = landscape */
	public boolean graph_sets_pad, graph_sets_margin, graph_sets_pageSize, graph_sets_rotation;

	/* layers */
	public StarChar layerDelims;	/* delimiters in layer names */
	public StarChar layerListDelims;	/* delimiters between layer ranges */ 
	public StarChar layers;		/* null delimited list of layer names */
	public StarStarChar layerIDs;	/* array of layer names */
	public int numLayers;		/* number of layers */
	public StarInt layerlist;

	/* default font */
	public StarChar defaultfontname;
	public double defaultfontsize;

	/* default line style */
	public StarStarChar defaultlinestyle;

	/* render defaults set from graph */
	public final gvcolor_t bgcolor = new gvcolor_t();	/* background color */

	/* whether to mangle font names (at least in SVG), usually false */
	public int fontrenaming;
	
	public void reset() {
		common.reset();
		config_path = null;
		config_found = false;
		input_filenames = null;
		gvgs = null;
		gvg = null;
		packages = null;
		textfont_disc.reset();
		textfont_dt = null;
		textlayout.reset();
		jobs = null;
		job = null;
		g = null;
		layout.reset();
		graphname = null;
		active_jobs = null;
		pagedir = null;
		margin.reset();
		pad.reset();
		pageSize.reset();
		pb.reset();
		bb.reset();
		rotation = 0;
		graph_sets_pad=false; graph_sets_margin=false; graph_sets_pageSize=false; graph_sets_rotation=false;
		layerDelims = null;
		layerListDelims = null;
		layers = null;
		layerIDs = null;
		numLayers = 0;
		layerlist = null;;
		defaultfontname = null;;
		defaultfontsize = 0;
		defaultlinestyle = null;;
		bgcolor.reset();
		fontrenaming = 0;
	}
}

// struct GVC_s {
// 	GVCOMMON_t common;
// 
// 	char *config_path;
// 	boolean config_found;
// 
// 	/* gvParseArgs */
// 	char **input_filenames; /* null terminated array of input filenames */
// 
// 	/* gvNextInputGraph() */
// 	GVG_t *gvgs;	/* linked list of graphs */
// 	GVG_t *gvg;	/* current graph */
// 
// 	/* plugins */
// 
// 	/* APIS expands to "+1 +1 ... +1" to give the number of APIs */
// 	gvplugin_available_t *apis[ +1 +1 +1 +1 +1 ]; /* array of linked-list of plugins per api */
// 	gvplugin_available_t *api[ +1 +1 +1 +1 +1 ];  /* array of current plugins per api */
// 
// 	gvplugin_package_t *packages;   /* list of available packages */
// 
//         /* externally provided write() displine */
// 	size_t (*write_fn) (GVJ_t *job, const char *s, size_t len);
// 
// 	/* fonts and textlayout */
// 	Dtdisc_t textfont_disc;
// 	Dt_t *textfont_dt;
// 	gvplugin_active_textlayout_t textlayout; /* always use best avail for all jobs */
// //	void (*free_layout) (void *layout);   /* function for freeing layouts (mostly used by pango) */
// 	
// /* FIXME - everything below should probably move to GVG_t */
// 
// 	/* gvrender_config() */
// 	GVJ_t *jobs;	/* linked list of jobs */
// 	GVJ_t *job;	/* current job */
// 
// 	graph_t *g;      /* current graph */
// 
// 	/* gvrender_begin_job() */
// 	gvplugin_active_layout_t layout;
// 
// 	char *graphname;	/* name from graph */
// 	GVJ_t *active_jobs;   /* linked list of active jobs */
// 
// 	/* pagination */
// 	char *pagedir;		/* pagination order */
// 	pointf margin;		/* margins in graph units */
// 	pointf pad;		/* pad in graph units */
// 	pointf pageSize;	/* pageSize in graph units, not including margins */
// 	point pb;		/* page size - including margins (inches) */
// 	boxf bb;		/* graph bb in graph units, not including margins */
// 	int rotation;		/* rotation - 0 = portrait, 90 = landscape */
// 	boolean graph_sets_pad, graph_sets_margin, graph_sets_pageSize, graph_sets_rotation;
// 
// 	/* layers */
// 	char *layerDelims;	/* delimiters in layer names */
// 	char *layerListDelims;	/* delimiters between layer ranges */ 
// 	char *layers;		/* null delimited list of layer names */
// 	char **layerIDs;	/* array of layer names */
// 	int numLayers;		/* number of layers */
// 	int *layerlist;
// 
// 	/* default font */
// 	char *defaultfontname;
// 	double defaultfontsize;
// 
// 	/* default line style */
// 	char **defaultlinestyle;
// 
// 	/* render defaults set from graph */
// 	gvcolor_t bgcolor;	/* background color */
// 
// 	/* whether to mangle font names (at least in SVG), usually false */
// 	int fontrenaming;
//     };