#line 1 "graphviz-2.38.0\\plugin\\core\\gvplugin_core.c" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/

#line 1 "graphviz-2.38.0\\lib\\gvc\\gvplugin.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/

/* Header used by plugins */








#line 1 "graphviz-2.38.0\\lib\\gvc\\gvcext.h" 1

/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/

/* Common header used by both clients and plugins */








/*
 * Define an apis array of name strings using an enumerated api_t as index.
 * The enumerated type is defined here.  The apis array is
 * inititialized in gvplugin.c by redefining ELEM and reinvoking APIS.
 */


/*
 * Define api_t using names based on the plugin names with API_ prefixed.
 */

    typedef enum { API_render, API_layout, API_textlayout, API_device, API_loadimage, _DUMMY_ELEM_=0 } api_t; /* API_render, API_layout, ... */
    			/* Stupid but true: The sole purpose of "_DUMMY_ELEM_=0"
			 * is to avoid a "," after the last element of the enum
			 * because some compilers when using "-pedantic"
			 * generate an error for about the dangling ","
			 * but only if this header is used from a .cpp file!
			 * Setting it to 0 makes sure that the enumeration
			 * does not define an extra value.  (It does however
			 * define _DUMMY_ELEM_ as an enumeration symbol,
			 * but its value duplicates that of the first
			 * symbol in the enumeration - in this case "render".)
			 */

    			/* One could wonder why trailing "," in:
			 * 	int nums[]={1,2,3,};
			 * is OK, but in:
			 * 	typedef enum {a,b,c,} abc_t; 
			 * is not!!!
			 */


    typedef struct GVJ_s GVJ_t;
    typedef struct GVG_s GVG_t;
    typedef struct GVC_s GVC_t;

    typedef struct {
	const char *name;
	void* address;
    } lt_symlist_t;

    typedef struct gvplugin_available_s gvplugin_available_t;

/*visual studio*/








/*end visual studio*/




	


	extern lt_symlist_t lt_preloaded_symbols[];












#line 21 "graphviz-2.38.0\\lib\\gvc\\gvplugin.h" 2

/* 
 * Terminology:
 *
 *    package         - e.g. libgvplugin_cairo.so
 *       api	      - e.g. render
 *          type      - e.g. "png", "ps"
 */

    typedef struct {
	int id;         /* an id that is only unique within a package 
			of plugins of the same api.
			A renderer-type such as "png" in the cairo package
			has an id that is different from the "ps" type
			in the same package */
	const char *type;	/* a string name, such as "png" or "ps" that
			distinguishes different types withing the same
			 (renderer in this case) */
	int quality;    /* an arbitrary integer used for ordering plugins of
			the same type from different packages */
	void *engine;   /* pointer to the jump table for the plugin */
	void *features; /* pointer to the feature description 
				void* because type varies by api */
    } gvplugin_installed_t;

    typedef struct {
	api_t api;
	gvplugin_installed_t *types;
    } gvplugin_api_t;

    typedef struct {
	char *packagename;    /* used when this plugin is builtin and has
					no pathname */
	gvplugin_api_t *apis;
    } gvplugin_library_t;





#line 16 "graphviz-2.38.0\\plugin\\core\\gvplugin_core.c" 2

extern gvplugin_installed_t gvdevice_dot_types[];
extern gvplugin_installed_t gvdevice_fig_types[];
extern gvplugin_installed_t gvdevice_map_types[];
extern gvplugin_installed_t gvdevice_ps_types[];
extern gvplugin_installed_t gvdevice_svg_types[];
extern gvplugin_installed_t gvdevice_tk_types[];
extern gvplugin_installed_t gvdevice_vml_types[];
extern gvplugin_installed_t gvdevice_pic_types[];
extern gvplugin_installed_t gvdevice_pov_types[];

extern gvplugin_installed_t gvrender_dot_types[];
extern gvplugin_installed_t gvrender_fig_types[];
extern gvplugin_installed_t gvrender_map_types[];
extern gvplugin_installed_t gvrender_ps_types[];
extern gvplugin_installed_t gvrender_svg_types[];
extern gvplugin_installed_t gvrender_tk_types[];
extern gvplugin_installed_t gvrender_vml_types[];
extern gvplugin_installed_t gvrender_pic_types[];
extern gvplugin_installed_t gvrender_pov_types[];

extern gvplugin_installed_t gvloadimage_core_types[];




static gvplugin_api_t apis[] = {
    {API_device, gvdevice_dot_types},
    {API_device, gvdevice_fig_types},
    {API_device, gvdevice_map_types},
    {API_device, gvdevice_ps_types},
    {API_device, gvdevice_svg_types},
    {API_device, gvdevice_tk_types},
    {API_device, gvdevice_vml_types},
    {API_device, gvdevice_pic_types},
    {API_device, gvdevice_pov_types},

    {API_render, gvrender_dot_types},
    {API_render, gvrender_fig_types},
    {API_render, gvrender_map_types},
    {API_render, gvrender_ps_types},
    {API_render, gvrender_svg_types},
    {API_render, gvrender_tk_types},
    {API_render, gvrender_vml_types},
    {API_render, gvrender_pic_types},
    {API_render, gvrender_pov_types},

    {API_loadimage, gvloadimage_core_types},

    {(api_t)0, 0},
};















gvplugin_library_t gvplugin_core_LTX_library = { "core", apis };




