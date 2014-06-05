#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcomptexture.c" 1
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

#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcomptexture.h" 1
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

/*Open GL texture handling and storing mechanism
  includes glPanel,glCompButton,glCompCustomButton,clCompLabel,glCompStyle
*/







#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcomptexture.h" 1
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcomptexture.h" 1
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcomptexture.h" 1
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





#line 25 "graphviz-2.38.0\\lib\\glcomp\\glcomptexture.h" 2





    extern glCompTex *glCompSetAddNewTexImage(glCompSet * s, int width,
					      int height,
					      unsigned char *data,
					      int is2D);
    extern glCompTex *glCompSetAddNewTexLabel(glCompSet * s, char *def,
					      int fs, char *text,
					      int is2D);

    extern void glCompDeleteTexture(glCompTex * t);




#line 16 "graphviz-2.38.0\\lib\\glcomp\\glcomptexture.c" 2
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glpangofont.h" 1
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



#line 1 "graphviz-2.38.0\\lib\\glcomp\\glpangofont.h" 1
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glpangofont.h" 1
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glpangofont.h" 1





//creates a font file with given name and font description
//returns non-zero if fails
    unsigned char *glCompCreatePangoTexture(char *fontdescription,
					int fontsize, char *txt,
					cairo_surface_t * surface, int *w,
					int *h);
    int glCompCreateFontFile(char *fontdescription, int fs, char *fontfile,
			 float gw, float gh);





#line 17 "graphviz-2.38.0\\lib\\glcomp\\glcomptexture.c" 2

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







#line 19 "graphviz-2.38.0\\lib\\glcomp\\glcomptexture.c" 2







static glCompTex *glCompSetAddNewTexture(glCompSet * s, int width,
					 int height, unsigned char *data,
					 int is2D,int fs)
{
    int Er, offset, ind;
    glCompTex *t;
    unsigned char *tarData;
    unsigned char *srcData;

    if (!data)
	return NULL;

    Er = 0;
    t = (glCompTex*)zmalloc(sizeof(glCompTex));
    if (!is2D) {		/*use opengl texture */
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glGenTextures(1, &t->id);	//get next id
	if (t->id < 0)		/*for some opengl based error , texture couldnt be created */
	    Er = 1;
	else {
	    glBindTexture(GL_TEXTURE_2D, t->id);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
			    GL_NEAREST);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
			    GL_NEAREST);
	    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
			 GL_RGBA, GL_UNSIGNED_BYTE, data);
	    glDisable(GL_TEXTURE_2D);
	}
    }
    if (is2D && !Er) {
	t->data = (unsigned char*)zmalloc((4 * width * height)*sizeof(unsigned char));
	offset = 4;		//RGBA  mod,TO DO implement other modes 
	/*data upside down because of pango gl coord system */
	for (ind = 0; ind < height; ind++) {
	    srcData = data + (height - 1 - ind) * offset * width;
	    tarData = t->data + ind * offset * width;
	    memcpy(tarData, srcData, 4 * width);
	}
    }

    if (Er) {
	free(data);
	free(t);
	return NULL;
    }
    t->userCount = 1;
    t->width = (GLfloat) width;
    t->height = (GLfloat) height;
    if(s)
    {
	s->textureCount++;
	s->textures =
	realloc(s->textures, s->textureCount * sizeof(glCompTex *));
	s->textures[s->textureCount - 1] = t;
    }
    return t;


}

glCompTex *glCompSetAddNewTexImage(glCompSet * s, int width, int height,
				   unsigned char *data, int is2D)
{

    glCompTex *t;
    if (!data)
	return NULL;
    t = glCompSetAddNewTexture(s, width, height, data, is2D,-1);
    if (!t)
	return NULL;
    t->type = glTexImage;
    return t;

}




glCompTex *glCompSetAddNewTexLabel(glCompSet * s, char *def, int fs,
				   char *text, int is2D)
{
    int ind, Er, width, height;
//      int ind2=0;
    glCompTex *t;
    cairo_surface_t *surface = NULL;
    unsigned char *data;
    data = (unsigned char *) 0;
    Er = 0;
    if (!def)
	return NULL;
    /*first check if the same label with same font def created before
       if it was , return its id
     */
    for (ind = 0; ind < s->textureCount; ind++) {
	if (s->textures[ind]->type == glTexLabel) {
	    if ((strcmp(def, s->textures[ind]->def) == 0)
		&& (s->textures[ind]->type == glTexLabel)
		&& (strcmp(text, s->textures[ind]->text) == 0)
		&& (s->textures[ind]->fontSize==fs)) {
		s->textures[ind]->userCount++;
		return s->textures[ind];
	    }
	}
    }


    data = glCompCreatePangoTexture(def, fs, text, surface, &width, &height);
    if (!data)			/*pango error , */
	Er = 1;
    t = glCompSetAddNewTexture(s, width, height, data, is2D,fs);
    if (!t)
	Er = 1;
    cairo_surface_destroy(surface);

    if (Er) {
	free(data);
	free(t);
	return NULL;
    }

    t->def = strdup(def);
    t->text = strdup(text);
    t->type = glTexLabel;
    return t;
}

void glCompDeleteTexture(glCompTex * t)
{
    if (!t)
	return;
    t->userCount--;
    if (!t->userCount) {
	if (t->data)
	    free(t->data);
	if (t->def)
	    free(t->def);
	if (t->text)
	    free(t->text);
	free(t);
    }
}
