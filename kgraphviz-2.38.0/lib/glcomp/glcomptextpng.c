#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcomptextpng.c" 1
/* $Id$Revision: */
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

#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompfont.h" 1
/* $Id$Revision: */
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



#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompfont.h" 1
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompfont.h" 1




#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompfont.h" 1
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompfont.h" 1

#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompdefs.h" 1
/* $Id$Revision: */
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



#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompdefs.h" 1
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompdefs.h" 1
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompdefs.h" 1
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompdefs.h" 1
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompdefs.h" 1





#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompdefs.h" 1
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompdefs.h" 1
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompdefs.h" 1
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompdefs.h" 1
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompdefs.h" 1





































































    typedef enum { inverted_y, scientific_y } glCompOrientation;
    typedef enum { gluttext, pangotext } glCompFontType;
    typedef enum { glAlignNone, glAlignLeft, glAlignTop, glAlignBottom,
	    glAlignRight, glAlignParent, glAlignCenter } glCompAlignment;

    typedef enum { glFontVJustifyNone, glFontVJustifyTop,
	    glFontVJustifyBottom, glFontVJustifyCenter } glCompVJustify;
    typedef enum { glFontHJustifyNone, glFontHJustifyLeft,
	    glFontHJustifyRight, glFontHJustifyCenter } glCompHJustify;
    typedef enum { glButtonGlyphLeft, glButtonGlyphRight, glButtonGlyphTop,
	    glButtonGlyphBottom } glCompButtonGlyph;
    typedef enum { glBorderNone, glBorderSolid, glBorderBevel,
	    glBorderCustom } glCompBorderType;

    typedef enum { glMouseDown, glMouseUp } glCompMouseStatus;
    typedef enum { glMouseLeftButton, glMouseRightButton,
	    glMouseMiddleButton } glMouseButtonType;

    typedef enum { glTexImage, glTexLabel } glCompTexType;
    typedef enum { glPanelObj, glButtonObj, glLabelObj,
	    glImageObj } glObjType;

    typedef struct _glCompButton glCompButton;
    typedef struct _glCompObj glCompObj;

/*call backs for widgets*/
    typedef void (*glcompdrawfunc_t) (void *obj);
    typedef void (*glcompclickfunc_t) (glCompObj * obj, GLfloat x,
				       GLfloat y, glMouseButtonType t);
    typedef void (*glcompdoubleclickfunc_t) (glCompObj * obj, GLfloat x,
					     GLfloat y,
					     glMouseButtonType t);
    typedef void (*glcompmouseoverfunc_t) (glCompObj * obj, GLfloat x,
					   GLfloat y);
    typedef void (*glcompmouseinfunc_t) (glCompObj * obj, GLfloat x,
					 GLfloat y);
    typedef void (*glcompmouseoutfunc_t) (glCompObj * obj, GLfloat x,
					  GLfloat y);
    typedef void (*glcompmousedownfunc_t) (glCompObj * obj, GLfloat x,
					   GLfloat y, glMouseButtonType t);
    typedef void (*glcompmouseupfunc_t) (glCompObj * obj, GLfloat x,
					 GLfloat y, glMouseButtonType t);
    typedef void (*glcompmousedragfunct_t) (glCompObj * obj, GLfloat dx,
					    GLfloat dy,
					    glMouseButtonType t);



    typedef struct _glCompAnchor {

	int topAnchor;		/*anchor booleans */
	int leftAnchor;
	int rightAnchor;
	int bottomAnchor;

	GLfloat top;		/*anchor values */
	GLfloat left;
	GLfloat right;
	GLfloat bottom;


    } glCompAnchor;

    typedef struct _glCompJustify {
	glCompVJustify VJustify;
	glCompHJustify HJustify;
    } glCompJustify;




    typedef struct _glCompPoint {
	GLfloat x, y, z;
    } glCompPoint;

    typedef struct _glCompPointI {
	int x, y;
    } glCompPointI;
    typedef struct {
	int cnt;
	int hotKey;
	glCompPoint* pts;
    }glCompPoly;

    typedef struct {
	GLfloat R;
	GLfloat G;
	GLfloat B;
	GLfloat A;		//Alpha
	int tag;
	int test;
    } glCompColor;


    typedef struct _glCompRect {
	glCompPoint pos;
	GLfloat w;
	GLfloat h;
    } glCompRect;

    typedef struct _glCompTex {
	GLuint id;
	char *def;
	char *text;
	float width;
	float height;
	glCompTexType type;
	int userCount;
	int fontSize;
	unsigned char *data;	/*data */
    } glCompTex;



/*opengl font*/
    typedef struct {
	char *fontdesc;		//font description , only used with pango fonts
	glCompColor color;
	glCompFontType type;
	void *glutfont;		/*glut font pointer if used */
	int transparent;
	glCompTex *tex;		/* texture, if type is pangotext */
	int size;
	int reference;		/*if font has references to parent */
	glCompJustify justify;
	int is2D;
	int optimize;
    } glCompFont;

    typedef struct _glCompCallBacks {
	glcompdrawfunc_t draw;
	glcompclickfunc_t click;
	glcompdoubleclickfunc_t doubleclick;
	glcompmouseoverfunc_t mouseover;
	glcompmouseinfunc_t mousein;
	glcompmouseoutfunc_t mouseout;
	glcompmousedownfunc_t mousedown;
	glcompmouseupfunc_t mouseup;
	glcompmousedragfunct_t mousedrag;

    } glCompCallBacks;


/*
	common widget properties
	also each widget has pointer to its parents common
*/
    typedef struct _glCompCommon {
	glCompPoint pos;
	glCompPoint refPos;	/*calculated pos after anchors and aligns */
	GLfloat width, height;
	GLfloat borderWidth;
	glCompBorderType borderType;
	glCompColor color;
	int enabled;
	int visible;
	void *compset;		// compset
	void *parent;		/*parent widget */
	int data;
	glCompFont *font;	//pointer to font to use
	glCompAlignment align;
	glCompAnchor anchor;
	int layer;		/*keep track of object order, what to draw on top */
	glCompCallBacks callbacks;
	glCompCallBacks functions;
	glCompJustify justify;
    } glCompCommon;

/*generic image*/
    typedef struct _glCompImage {
	glObjType objType;	/*always keep this here for each drawable object */
	glCompCommon common;
	glCompTex *texture;
	GLfloat width, height;  /* width and height in world coords */
	/* char *pngFile; */
	int stretch;
    } glCompImage;

/*generic panel*/
    typedef struct _glCompPanel {
	glObjType objType;	/*always keep this here for each drawable object */
	glCompCommon common;
	GLfloat shadowwidth;
	glCompColor shadowcolor;
	char *text;
	glCompImage *image;
    } glCompPanel;

/*label*/
    typedef struct _glCompLabel {
	glObjType objType;	/*always keep this here for each drawable object */
	glCompCommon common;
	int autosize;		/*if 1 label sized is calculated from font */
	char *text;
	int transparent;
    } glCompLabel;

/*buttons*/
    struct _glCompButton {
	glObjType objType;	/*always keep this here for each drawable object */
	glCompCommon common;
	GLfloat width, height;
	glCompLabel *label;
	int status;		//0 not pressed 1 pressed;
	int refStatus;		//0 not pressed 1 pressed;
	int groupid;
	glCompImage *image;	/*glyph */
	glCompButtonGlyph glyphPos;
	void *customptr;	//general purpose void pointer to pass to call back
	int data;

    };

/*texture based image*/

/*track bar*/
    typedef struct _glCompTrackBar {
	glObjType objType;	/*always keep this here for each drawable object */
	GLfloat width, height;
	glCompPanel *outerpanel;
	glCompPanel *trackline;
	glCompPanel *indicator;

	GLfloat bevel;
	glCompColor color;
	glCompColor shadowcolor;


	float value;
	float maxvalue;
	float minvalue;
	int enabled;
	int visible;
	void *parentset;	//parent compset
	int data;
	glCompFont *font;	//pointer to font to use
	glCompOrientation orientation;

    } glCompTrackBar;

/*glCompFont container class*/
    typedef struct {
	glCompFont **fonts;
	int count;
	int activefont;
	char *font_directory;	//location where the glfont files are stored
    } fontset_t;

/*object prototype*/
    struct _glCompObj {
	glObjType objType;
	glCompCommon common;
    };

    typedef struct _glCompMouse {
	glCompMouseStatus status;
	glMouseButtonType t;
	glCompPoint initPos; /*current mouse pos,*/
	glCompPoint pos; /*current mouse pos,*/
	glCompPoint finalPos; /*current mouse pos,*/
	glCompPoint GLpos;/*3d converted opengl position*/
	glCompPoint GLinitPos;/*mouse button down pos*/
	glCompPoint GLfinalPos;/*mouse button up pos*/

	GLfloat dragX, dragY;/*GLpos - GLinitpos*/
	glCompObj *clickedObj;
	glCompCallBacks callbacks;
	glCompCallBacks functions;
	int down;


    } glCompMouse;



/*main widget set manager*/
    typedef struct {
	glObjType objType;	/*always keep this here for each drawable object */
	glCompCommon common;

	glCompObj **obj;
	int objcnt;
	glCompPanel **panels;
	glCompButton **buttons;
	glCompLabel **labels;
	int groupCount;		/*group id counter */
	int active;		//0 dont draw, 1 draw
	int enabled;		//0 disabled 1 enabled(allow mouse interaction)
	GLfloat clickedX, clickedY;

	int textureCount;
	glCompTex **textures;
	glCompMouse mouse;
    } glCompSet;





#line 22 "graphviz-2.38.0\\lib\\glcomp\\glcompfont.h" 2
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompfont.h" 1





    
    
    
    
    
    
    
    
    


    void glprintfglut(void *font, GLfloat xpos, GLfloat ypos, GLfloat zpos, char *bf);

    glCompFont *glNewFont(glCompSet * s, char *text, glCompColor * c,
          glCompFontType type, char *fontdesc, int fs,int is2D);
    glCompFont *glNewFontFromParent(glCompObj * o, char *text);
    void glDeleteFont(glCompFont * f);
    void glCompDrawText(glCompFont * f,GLfloat x,GLfloat y);
    void glCompRenderText(glCompFont * f, glCompObj * parentObj);
    void glCompDrawText3D(glCompFont * f,GLfloat x,GLfloat y,GLfloat z,GLfloat w,GLfloat h);





#line 16 "graphviz-2.38.0\\lib\\glcomp\\glcomptextpng.c" 2
#line 1 "graphviz-2.38.0\\lib\\common\\memory.h" 1
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




#line 1 "graphviz-2.38.0\\lib\\common\\memory.h" 1






































    extern void *zmalloc(size_t);
    extern void *zrealloc(void *, size_t, size_t, size_t);
    extern void *gmalloc(size_t);
	extern void *grealloc(void *, size_t);







#line 17 "graphviz-2.38.0\\lib\\glcomp\\glcomptextpng.c" 2
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcomptextpng.c" 1
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcomptextpng.c" 1

unsigned char *glCompLoadPng (char *filename, int *imageWidth, int *imageHeight)
{
    cairo_surface_t *surface;
    cairo_format_t format;
    int w, h;
    unsigned char *d;
    surface = NULL;

    surface = cairo_image_surface_create_from_png(filename);
    if (!surface) return 0;
    w = cairo_image_surface_get_width(surface);
    h = cairo_image_surface_get_height(surface);
    *imageWidth = w;
    *imageHeight = h;
    format = cairo_image_surface_get_format(surface);
    d = cairo_image_surface_get_data(surface);
    return d;
}





    
    
    
    
    
    
    
    
    



			 

    
    
    
    
    
    
    
    
    
    
    
	
    
    
    
    
	
	
	
    

    
	
    
	
	
	
    

    
    
	
				
	
	
	
    

    
    
	
	
	
	
    


    

    
    

    
			      
    
    
    
    
    
    
    

    
    
    
    

    
	
	     
	    
	    
		
		
		
		    
		
		
		
		
	    
	    
	
    
    
    
    

    
    




