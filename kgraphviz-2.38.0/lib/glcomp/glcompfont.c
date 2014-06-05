#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompfont.c" 1
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





#line 16 "graphviz-2.38.0\\lib\\glcomp\\glcompfont.c" 2
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompset.h" 1
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

/*Open GL basic component set
  includes glPanel,glCompButton,glCompCustomButton,clCompLabel,glCompStyle
*/



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



















    
    
    
    
    
    
    
    
    


    

    
          
    
    
    
    
    





#line 20 "graphviz-2.38.0\\lib\\glcomp\\glcompset.h" 2
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcomptextpng.h" 1
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

unsigned char *glCompLoadPng (char *filename, int *imageWidth, int *imageHeight);
#line 21 "graphviz-2.38.0\\lib\\glcomp\\glcompset.h" 2





    extern void glCompInitCommon(glCompObj * childObj,
				 glCompObj * parentObj, GLfloat x,
				 GLfloat y);
    void glCompEmptyCommon(glCompCommon * c);
    extern glCompSet *glCompSetNew(int w, int h);
    extern void glCompSetClear(glCompSet * s);
    extern int glCompSetDraw(glCompSet * s);
    extern int glCompSetHide(glCompSet * s);
    extern int glCompSetShow(glCompSet * s);
    extern int glCompSetClick(glCompSet * s, int x, int y);
    extern int glCompSetRelease(glCompSet * s, int x, int y);
    extern void glcompsetUpdateBorder(glCompSet * s, int w, int h);
    extern int glcompsetNextGroupId(glCompSet * s);
    extern int glcompsetGetGroupId(glCompSet * s);
    extern void glCompDrawBegin(void);
    extern void glCompDrawEnd(void);
    extern void glCompSetAddObj(glCompSet * s, glCompObj * obj);
    glCompObj *glCompGetObjByMouse(glCompSet * s, glCompMouse * m,
				   int onlyClickable);
    extern void glCompGetObjectType(glCompObj * p);
/*
	change all components's fonts  in s 
	to sourcefont
*/
/* void change_fonts(glCompSet * s,const texFont_t* sourcefont); */





#line 17 "graphviz-2.38.0\\lib\\glcomp\\glcompfont.c" 2
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





#line 18 "graphviz-2.38.0\\lib\\glcomp\\glcompfont.c" 2
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























































































    
    
    
	    

    
	    
    
	    
    
	    
    
	    

    
    
	    

    
    
	    

    
    


    
    
				       
    
					     
					     
    
					   
    
					 
    
					  
    
					   
    
					 
    
					    
					    



    

	
	
	
	

	
	
	
	


    

    
	
	
    




    
	
    

    
	
    
    
	
	
	
    

    
	
	
	
	
	
	
    


    
	
	
	
    

    
	
	
	
	
	
	
	
	
	
    




    
	
	
	
	
	
	
	
	
	
	
	
    

    
	
	
	
	
	
	
	
	
	

    






    
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
    


    
	
	
	
	
	
	
    


    
	
	
	
	
	
	
    


    
	
	
	
	
	
    


    
	
	
	
	
	
	
	
	
	
	
	

    




    
	
	
	
	
	

	
	
	


	
	
	
	
	
	
	
	
	

    


    
	
	
	
	
    


    
	
	
    

    
	
	
	
	
	
	
	
	

	
	
	
	
	


    




    
	
	

	
	
	
	
	
	
	
	
	

	
	
	
    





#line 25 "graphviz-2.38.0\\lib\\glcomp\\glcomptexture.h" 2





    extern glCompTex *glCompSetAddNewTexImage(glCompSet * s, int width,
					      int height,
					      unsigned char *data,
					      int is2D);
    extern glCompTex *glCompSetAddNewTexLabel(glCompSet * s, char *def,
					      int fs, char *text,
					      int is2D);

    extern void glCompDeleteTexture(glCompTex * t);




#line 19 "graphviz-2.38.0\\lib\\glcomp\\glcompfont.c" 2
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glutils.h" 1
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






#line 1 "graphviz-2.38.0\\lib\\glcomp\\glutils.h" 1
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glutils.h" 1
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























































































    
    
    
	    

    
	    
    
	    
    
	    
    
	    

    
    
	    

    
    
	    

    
    


    
    
				       
    
					     
					     
    
					   
    
					 
    
					  
    
					   
    
					 
    
					    
					    



    

	
	
	
	

	
	
	
	


    

    
	
	
    




    
	
    

    
	
    
    
	
	
	
    

    
	
	
	
	
	
	
    


    
	
	
	
    

    
	
	
	
	
	
	
	
	
	
    




    
	
	
	
	
	
	
	
	
	
	
	
    

    
	
	
	
	
	
	
	
	
	

    






    
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
    


    
	
	
	
	
	
	
    


    
	
	
	
	
	
	
    


    
	
	
	
	
	
    


    
	
	
	
	
	
	
	
	
	
	
	

    




    
	
	
	
	
	

	
	
	


	
	
	
	
	
	
	
	
	

    


    
	
	
	
	
    


    
	
	
    

    
	
	
	
	
	
	
	
	

	
	
	
	
	


    




    
	
	

	
	
	
	
	
	
	
	
	

	
	
	
    





#line 20 "graphviz-2.38.0\\lib\\glcomp\\glutils.h" 2





    typedef struct {
	glCompPoint u, v;
    } line;
    typedef struct {
	glCompPoint N;		/* normal */
	double d;		/* offset */
    } plane;


    int GetFixedOGLPos(int, int, float, GLfloat *, GLfloat *, GLfloat * Z);
    int GetOGLPosRef(int x, int y, float *X, float *Y, float *Z);
    float GetOGLDistance(int l);
    int GetFixedOGLPoslocal(int x, int y, GLfloat * X, GLfloat * Y,
			    GLfloat * Z);
    void to3D(int x, int y, GLfloat * X, GLfloat * Y, GLfloat * Z);
    double point_to_lineseg_dist(glCompPoint p, glCompPoint a, glCompPoint b);

    
    
    
    
    

    void replacestr(char *source, char **target);
    extern void glCompCalcWidget(glCompCommon * parent,
				 glCompCommon * child, glCompCommon * ref);
    extern void glCompDrawRectangle(glCompRect * r);
    extern void glCompDrawRectPrism(glCompPoint * p, GLfloat w, GLfloat h,
				    GLfloat b, GLfloat d, glCompColor * c,
				    int bumped);
    extern void copy_glcomp_color(glCompColor * source,
				  glCompColor * target);
    extern void glCompSetColor(glCompColor * c);

    void glCompSelectionBox(glCompSet * s);
    extern GLfloat distBetweenPts(glCompPoint A,glCompPoint B,float R);
    extern int is_point_in_rectangle(float X, float Y, float RX, float RY, float RW,float RH);





#line 20 "graphviz-2.38.0\\lib\\glcomp\\glcompfont.c" 2
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







#line 21 "graphviz-2.38.0\\lib\\glcomp\\glcompfont.c" 2
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompfont.c" 1

static void print_bitmap_string(void *font, char *s)
{
    if (s && strlen(s)) {
	while (*s) {
	    glutBitmapCharacter(font, *s);
//         glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *s);
	    s++;
	}
    }
}






















































void glprintfglut(void *font, GLfloat xpos, GLfloat ypos, GLfloat zpos,
		  char *bf)
{
    glRasterPos3f(xpos, ypos, zpos + 0.001);
    print_bitmap_string(font, bf);


}




	 






    
    
    
	
    
	
	
    





	 

    




	  

    




    
    
	
	    
    
    




    
    
	
	    
    
    





    
    
    
    
    























    



void glDeleteFont(glCompFont * f)
{
    if (f->fontdesc)
	free(f->fontdesc);
    if (f->tex)
	glCompDeleteTexture(f->tex);
    free(f);

}

glCompFont *glNewFont (glCompSet * s, char *text, glCompColor * c,glCompFontType type, char *fontdesc, int fs,int is2D)
{
    glCompFont *font = (glCompFont*) malloc(sizeof(glCompFont));
    font->reference = 0;
    font->color.R = c->R;
    font->color.G = c->G;
    font->color.B = c->B;
    font->color.A = c->A;
    font->justify.VJustify = 0;
    font->justify.HJustify = 0;
    font->type=type;
    font->is2D=is2D;

    if (font->type == gluttext)
	font->glutfont = GLUT_BITMAP_HELVETICA_12;
    else
	font->glutfont = (void *) 0;

    font->fontdesc = strdup(fontdesc);
    font->size = fs;
    font->transparent = 1;
    font->optimize = 1;
    if (text)
	font->tex =
	    glCompSetAddNewTexLabel(s, font->fontdesc, font->size, text,
				    is2D);
    return font;

}



glCompFont *glNewFontFromParent(glCompObj * o, char *text)
{
    glCompCommon *parent;
    glCompFont *font = (glCompFont*)zmalloc(sizeof(glCompFont));
    parent = o->common.parent;
    if (parent) {
	parent = o->common.parent;
	font->reference = 1;
	font->color.R = parent->font->color.R;
	font->color.G = parent->font->color.G;
	font->color.B = parent->font->color.B;
	font->color.A = parent->font->color.A;

	font->type = parent->font->type;
	font->glutfont = parent->font->glutfont;
	font->fontdesc = strdup(parent->font->fontdesc);
	font->size = parent->font->size;
	font->transparent = parent->font->transparent;
	font->justify.VJustify = parent->font->justify.VJustify;
	font->justify.HJustify = parent->font->justify.HJustify;
	font->optimize = parent->font->optimize;
	font->is2D=parent->font->is2D;
	if (text) {
	    if (strlen(text))
		font->tex =
		    glCompSetAddNewTexLabel(parent->compset,
					    font->fontdesc, font->size,
					    text, parent->font->is2D);
	}
    } else {			/*no parent */

	glCompColor c;
	c.R = (GLfloat)0;
	c.G = (GLfloat)0;
	c.B = (GLfloat)0;
	c.A = (GLfloat)1;
	font =
	    glNewFont (o->common.compset, text, &c, pangotext,
		     "Times Italic", (GLfloat)14,1);
    }
    return font;
}









    
    
    

    

    
    

    
    







    
    
    
	
	    
	
	
	
	
	
    
	





    
    

    
    
	
	
	    
	    
	



















    

    




    
    

	
		
	

	
	
    
    

    
	

    
	
    





    
    
    
    



/*texture base 3d text rendering*/
void glCompDrawText3D(glCompFont * f,GLfloat x,GLfloat y,GLfloat z,GLfloat w,GLfloat h)
{
	glEnable(GL_BLEND);		// Turn Blending On
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D,f->tex->id);
	glBegin(GL_QUADS);
		glTexCoord2d(0.0f, 1.0f);glVertex3d(x,y,z);
		glTexCoord2d(1.0f, 1.0f);glVertex3d(x+w,y,z);
		glTexCoord2d(1.0f, 0.0f);glVertex3d(x+w,y+h,z);
		glTexCoord2d(0.0f, 0.0f);glVertex3d(x,y+h,z);
	glEnd();

	glDisable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);

}




    
    
    
    
	
	
	    
	    
	    
	    
	
    



void glCompDrawText(glCompFont * f,GLfloat x,GLfloat y)
{
//    change_fontC(f->tex->data,f->tex->width,f->tex->height,&f->color);
    glRasterPos2f(x, y);
    glDrawPixels(f->tex->width, f->tex->height, GL_RGBA, GL_UNSIGNED_BYTE,  f->tex->data);
}

/*text rendering functions, depends on a globject to retrieve stats*/
void glCompRenderText(glCompFont * f, glCompObj * parentObj)
{
    static glCompCommon ref;
    GLfloat x, y, z, w, h;
    if (!f->tex)
	return;
    x = 0;
    y = 0;
    w = f->tex->width;
    h = f->tex->height;
    ref = parentObj->common;
    z = ref.pos.z;
    switch (f->justify.HJustify) 
    {
    case glFontHJustifyNone:
    case glFontHJustifyLeft:
	x = ref.refPos.x;
	break;
    case glFontHJustifyRight:
	x = ref.refPos.x + (ref.width - f->tex->width);
	break;
    case glFontHJustifyCenter:
	x = ref.refPos.x + (ref.width - f->tex->width) / (GLfloat) 2.0;
	break;
    }
    switch (f->justify.VJustify) {
    case glFontVJustifyNone:
    case glFontVJustifyBottom:
	y = ref.pos.y;
	break;
    case glFontVJustifyTop:
	x = ref.refPos.y + (ref.height - f->tex->height);
	break;
    case glFontVJustifyCenter:
	y = ref.refPos.y + (ref.height - f->tex->height) / (GLfloat) 2.0;
	break;
    }
	z=ref.refPos.z;

    glCompSetColor(&f->color);
		glCompDrawText(f,x,y);

}










    
    


    

    
    


















    
    
	

    
    
    
    
    
    
    
    
    


    
		 


    

    


