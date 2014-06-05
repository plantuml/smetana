#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompset.c" 1
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





#line 16 "graphviz-2.38.0\\lib\\glcomp\\glcompset.c" 2
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







#line 17 "graphviz-2.38.0\\lib\\glcomp\\glcompset.c" 2
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcomppanel.h" 1
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























































































    
    
    
	    

    
	    
    
	    
    
	    
    
	    

    
    
	    

    
    
	    

    
    


    
    
				       
    
					     
					     
    
					   
    
					 
    
					  
    
					   
    
					 
    
					    
					    



    

	
	
	
	

	
	
	
	


    

    
	
	
    




    
	
    

    
	
    
    
	
	
	
    

    
	
	
	
	
	
	
    


    
	
	
	
    

    
	
	
	
	
	
	
	
	
	
    




    
	
	
	
	
	
	
	
	
	
	
	
    

    
	
	
	
	
	
	
	
	
	

    






    
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
    


    
	
	
	
	
	
	
    


    
	
	
	
	
	
	
    


    
	
	
	
	
	
    


    
	
	
	
	
	
	
	
	
	
	
	

    




    
	
	
	
	
	

	
	
	


	
	
	
	
	
	
	
	
	

    


    
	
	
	
	
    


    
	
	
    

    
	
	
	
	
	
	
	
	

	
	
	
	
	


    




    
	
	

	
	
	
	
	
	
	
	
	

	
	
	
    





#line 16 "graphviz-2.38.0\\lib\\glcomp\\glcomppanel.h" 2





    extern glCompPanel *glCompPanelNew(glCompObj * parentObj, GLfloat x,
				       GLfloat y, GLfloat w, GLfloat h);
    extern int glCompSetAddPanel(glCompSet * s, glCompPanel * p);
    extern int glCompSetRemovePanel(glCompSet * s, glCompPanel * p);
    extern int glCompPanelShow(glCompPanel * p);
    extern int glCompPanelHide(glCompPanel * p);
    extern void glCompSetPanelText(glCompPanel * p, char *t);

/*events*/
    extern int glCompPanelDraw(glCompObj * o);
    extern void glCompPanelClick(glCompObj * o, GLfloat x, GLfloat y,
				 glMouseButtonType t);
    extern void glCompPanelDoubleClick(glCompObj * obj, GLfloat x,
				       GLfloat y, glMouseButtonType t);
    extern void glCompPanelMouseDown(glCompObj * obj, GLfloat x, GLfloat y,
				     glMouseButtonType t);
    extern void glCompPanelMouseIn(glCompObj * obj, GLfloat x, GLfloat y);
    extern void glCompPanelMouseOut(glCompObj * obj, GLfloat x, GLfloat y);
    extern void glCompPanelMouseOver(glCompObj * obj, GLfloat x,
				     GLfloat y);
    extern void glCompPanelMouseUp(glCompObj * obj, GLfloat x, GLfloat y,
				   glMouseButtonType t);





#line 18 "graphviz-2.38.0\\lib\\glcomp\\glcompset.c" 2
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcomplabel.h" 1
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























































































    
    
    
	    

    
	    
    
	    
    
	    
    
	    

    
    
	    

    
    
	    

    
    


    
    
				       
    
					     
					     
    
					   
    
					 
    
					  
    
					   
    
					 
    
					    
					    



    

	
	
	
	

	
	
	
	


    

    
	
	
    




    
	
    

    
	
    
    
	
	
	
    

    
	
	
	
	
	
	
    


    
	
	
	
    

    
	
	
	
	
	
	
	
	
	
    




    
	
	
	
	
	
	
	
	
	
	
	
    

    
	
	
	
	
	
	
	
	
	

    






    
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
    


    
	
	
	
	
	
	
    


    
	
	
	
	
	
	
    


    
	
	
	
	
	
    


    
	
	
	
	
	
	
	
	
	
	
	

    




    
	
	
	
	
	

	
	
	


	
	
	
	
	
	
	
	
	

    


    
	
	
	
	
    


    
	
	
    

    
	
	
	
	
	
	
	
	

	
	
	
	
	


    




    
	
	

	
	
	
	
	
	
	
	
	

	
	
	
    





#line 16 "graphviz-2.38.0\\lib\\glcomp\\glcomplabel.h" 2





    extern glCompLabel *glCompLabelNew(glCompObj * par, GLfloat x,
				       GLfloat y, char *text);
    extern int glCompSetAddLabel(glCompSet * s, glCompLabel * p);
    extern int glCompSetRemoveLabel(glCompSet * s, glCompLabel * p);

/*events*/
    extern int glCompLabelDraw(glCompLabel * p);
    extern void glCompLabelClick(glCompObj * o, GLfloat x, GLfloat y,
				 glMouseButtonType t);
    extern void glCompLabelDoubleClick(glCompObj * obj, GLfloat x,
				       GLfloat y, glMouseButtonType t);
    extern void glCompLabelMouseDown(glCompObj * obj, GLfloat x, GLfloat y,
				     glMouseButtonType t);
    extern void glCompLabelMouseIn(glCompObj * obj, GLfloat x, GLfloat y);
    extern void glCompLabelMouseOut(glCompObj * obj, GLfloat x, GLfloat y);
    extern void glCompLabelMouseOver(glCompObj * obj, GLfloat x,
				     GLfloat y);
    extern void glCompLabelMouseUp(glCompObj * obj, GLfloat x, GLfloat y,
				   glMouseButtonType t);

    extern void glCompLabelSetText(glCompLabel * p, char *text);
    extern void glCompLabelSetFontSize(glCompLabel * p, int size);
    extern void glCompLabelSetFontName(glCompLabel * p, char* fontName);





#line 19 "graphviz-2.38.0\\lib\\glcomp\\glcompset.c" 2
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompbutton.h" 1
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























































































    
    
    
	    

    
	    
    
	    
    
	    
    
	    

    
    
	    

    
    
	    

    
    


    
    
				       
    
					     
					     
    
					   
    
					 
    
					  
    
					   
    
					 
    
					    
					    



    

	
	
	
	

	
	
	
	


    

    
	
	
    




    
	
    

    
	
    
    
	
	
	
    

    
	
	
	
	
	
	
    


    
	
	
	
    

    
	
	
	
	
	
	
	
	
	
    




    
	
	
	
	
	
	
	
	
	
	
	
    

    
	
	
	
	
	
	
	
	
	

    






    
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
    


    
	
	
	
	
	
	
    


    
	
	
	
	
	
	
    


    
	
	
	
	
	
    


    
	
	
	
	
	
	
	
	
	
	
	

    




    
	
	
	
	
	

	
	
	


	
	
	
	
	
	
	
	
	

    


    
	
	
	
	
    


    
	
	
    

    
	
	
	
	
	
	
	
	

	
	
	
	
	


    




    
	
	

	
	
	
	
	
	
	
	
	

	
	
	
    





#line 16 "graphviz-2.38.0\\lib\\glcomp\\glcompbutton.h" 2





    extern glCompButton *glCompButtonNew(glCompObj * par, GLfloat x,
					 GLfloat y, GLfloat w, GLfloat h,
					 char *caption);
    extern int glCompSetRemoveButton(glCompSet * s, glCompButton * p);
    extern void glCompButtonDraw(glCompButton * p);
    extern void glCompButtonSetText(glCompButton * p, char *str);
    extern int glCompButtonAddPngGlyph(glCompButton * b, char *fileName);
    extern void glCompButtonClick(glCompObj * o, GLfloat x, GLfloat y,
				  glMouseButtonType t);
    extern void glCompButtonDoubleClick(glCompObj * o, GLfloat x,
					GLfloat y, glMouseButtonType t);
    extern void glCompButtonMouseDown(glCompObj * o, GLfloat x, GLfloat y,
				      glMouseButtonType t);
    extern void glCompButtonMouseIn(glCompObj * o, GLfloat x, GLfloat y);
    extern void glCompButtonMouseOut(glCompObj * o, GLfloat x, GLfloat y);
    extern void glCompButtonMouseOver(glCompObj * o, GLfloat x, GLfloat y);
    extern void glCompButtonMouseUp(glCompObj * o, GLfloat x, GLfloat y,
				    glMouseButtonType t);
    extern void glCompButtonHide(glCompButton * p);
    extern void glCompButtonShow(glCompButton * p);





#line 20 "graphviz-2.38.0\\lib\\glcomp\\glcompset.c" 2
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompmouse.h" 1
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























































































    
    
    
	    

    
	    
    
	    
    
	    
    
	    

    
    
	    

    
    
	    

    
    


    
    
				       
    
					     
					     
    
					   
    
					 
    
					  
    
					   
    
					 
    
					    
					    



    

	
	
	
	

	
	
	
	


    

    
	
	
    




    
	
    

    
	
    
    
	
	
	
    

    
	
	
	
	
	
	
    


    
	
	
	
    

    
	
	
	
	
	
	
	
	
	
    




    
	
	
	
	
	
	
	
	
	
	
	
    

    
	
	
	
	
	
	
	
	
	

    






    
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
    


    
	
	
	
	
	
	
    


    
	
	
	
	
	
	
    


    
	
	
	
	
	
    


    
	
	
	
	
	
	
	
	
	
	
	

    




    
	
	
	
	
	

	
	
	


	
	
	
	
	
	
	
	
	

    


    
	
	
	
	
    


    
	
	
    

    
	
	
	
	
	
	
	
	

	
	
	
	
	


    




    
	
	

	
	
	
	
	
	
	
	
	

	
	
	
    





#line 16 "graphviz-2.38.0\\lib\\glcomp\\glcompmouse.h" 2





/*events*/
    extern void glCompMouseInit(glCompMouse * m);
    extern void glCompClick(glCompObj * o, GLfloat x, GLfloat y,
			    glMouseButtonType t);
    extern void glCompDoubleClick(glCompObj * obj, GLfloat x, GLfloat y,
				  glMouseButtonType t);
    extern void glCompMouseDown(glCompObj * obj, GLfloat x, GLfloat y,
				glMouseButtonType t);
    extern void glCompMouseIn(glCompObj * obj, GLfloat x, GLfloat y);
    extern void glCompMouseOut(glCompObj * obj, GLfloat x, GLfloat y);
    extern void glCompMouseOver(glCompObj * obj, GLfloat x, GLfloat y);
    extern void glCompMouseUp(glCompObj * obj, GLfloat x, GLfloat y,
			      glMouseButtonType t);
    extern void glCompMouseDrag(glCompObj * obj, GLfloat dx, GLfloat dy,
				glMouseButtonType t);





#line 21 "graphviz-2.38.0\\lib\\glcomp\\glcompset.c" 2

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





#line 23 "graphviz-2.38.0\\lib\\glcomp\\glcompset.c" 2
//typedef enum {glPanelObj,glbuttonObj,glLabelObj,glImageObj}glObjType;

static GLfloat startX, startY;



void glCompGetObjectType(glCompObj * p)
{
    switch (p->objType) {
    case glPanelObj:
	printf("Panel\n");
	break;
    case glButtonObj:
	printf("Button\n");
	break;
    case glImageObj:
	printf("Image\n");
	break;
    case glLabelObj:
	printf("Label\n");
	break;
    default:
	printf("undefined object\n");
	break;

    }

}

static int glCompPointInObject(glCompObj * p, float x, float y)
{
    return ((x > p->common.refPos.x)
	    && (x < p->common.refPos.x + p->common.width)
	    && (y > p->common.refPos.y)
	    && (y < p->common.refPos.y + p->common.height));
}

glCompObj *glCompGetObjByMouse(glCompSet * s, glCompMouse * m,
			       int onlyClickable)
{
    int ind;
    glCompObj *rv = NULL;
    if (!s || !m)
	return NULL;
    for (ind = 0; ind < s->objcnt; ind++) {
	if ((s->obj[ind]->common.visible)
	    && (glCompPointInObject(s->obj[ind], m->pos.x, m->pos.y))) {
	    if ((!rv) || (s->obj[ind]->common.layer >= rv->common.layer)) {
		if (((onlyClickable)
		     && (s->obj[ind]->common.functions.click))
		    || (!onlyClickable))
		    rv = s->obj[ind];
	    }
	}
    }

    return rv;
}


static void glCompMouseMove(void *obj, GLfloat x, GLfloat y)
{
    ((glCompSet *) obj)->mouse.pos.x = x;
    ((glCompSet *) obj)->mouse.pos.y =
	((glCompObj *) obj)->common.height - y;
    ((glCompSet *) obj)->mouse.pos.z = 0;
    ((glCompSet *) obj)->mouse.dragY =
	((glCompSet *) obj)->mouse.pos.y - startY;
    ((glCompSet *) obj)->mouse.dragX =
	((glCompSet *) obj)->mouse.pos.x - startX;
    if (((glCompSet *) obj)->common.callbacks.mouseover)
	((glCompSet *) obj)->common.callbacks.mouseover(obj, x, y);
/*	if (((glCompSet*)obj)->mouse.down)
		printf ("%f %f \n",((glCompSet*)obj)->mouse.dragX,((glCompSet*)obj)->mouse.dragX);*/
}



static void glCompSetMouseClick(void *obj, GLfloat x, GLfloat y,
				glMouseButtonType t)
{
    if (((glCompSet *) obj)->common.callbacks.click)
	((glCompSet *) obj)->common.callbacks.click(obj, x, y, t);


}
static void glCompSetMouseDown(void *obj, GLfloat x, GLfloat y,
			       glMouseButtonType t)
{
    ((glCompSet *) obj)->mouse.t = t;
    if (t == glMouseLeftButton) {
	((glCompSet *) obj)->mouse.pos.x = x;
	((glCompSet *) obj)->mouse.pos.y =
	    ((glCompObj *) obj)->common.height - y;
	((glCompSet *) obj)->mouse.pos.z = 0;
	((glCompSet *) obj)->mouse.clickedObj =
	    glCompGetObjByMouse(((glCompObj *) obj)->common.compset,
				&((glCompSet *) (((glCompObj *) obj)->
						 common.compset))->mouse,
				1);
	if (((glCompSet *) obj)->mouse.clickedObj)
	    if (((glCompSet *) obj)->mouse.clickedObj->common.functions.
		mousedown)
		((glCompSet *) obj)->mouse.clickedObj->common.functions.
		    mousedown(((glCompSet *) obj)->mouse.clickedObj, x, y,
			      t);
    }
    ((glCompSet *) obj)->mouse.down = 1;
    startX = x;
    startY = ((glCompObj *) obj)->common.height - y;
    if (((glCompSet *) obj)->common.callbacks.mousedown)
	((glCompSet *) obj)->common.callbacks.mousedown(obj, x, y, t);




}
static void glCompSetMouseUp(void *obj, GLfloat x, GLfloat y,
			     glMouseButtonType t)
{

    static GLfloat tempX, tempY;
    tempX = x;
    tempY = ((glCompObj *) obj)->common.height - y;

    ((glCompSet *) obj)->mouse.down = 0;
    if (t == glMouseLeftButton) {
	glCompObj *o = NULL;
	glCompObj *o_clicked = ((glCompSet *) obj)->mouse.clickedObj;
	((glCompSet *) obj)->mouse.pos.x = tempX;
	((glCompSet *) obj)->mouse.pos.y = tempY;
	((glCompSet *) obj)->mouse.pos.z = 0;
	if (o_clicked)
	    o = glCompGetObjByMouse((glCompSet *) obj,
				    &((glCompSet *) obj)->mouse, 1);
	if (!o)
	    return;
	if (o == o_clicked)
	    o->common.functions.click(o, x, y, t);
    }
    if (((glCompSet *) obj)->common.callbacks.mouseup)
	((glCompSet *) obj)->common.callbacks.mouseup(obj, x, y, t);
    /*check if mouse is clicked or dragged */
    if ((startX == (int) tempX) && (startY == tempY))
	glCompSetMouseClick(obj, x, y, t);



}



void glCompInitCommon(glCompObj * childObj, glCompObj * parentObj,
			     GLfloat x, GLfloat y)
{
    glCompCommon *c;
    glCompCommon *parent;
    c = &childObj->common;
    c->align = glAlignNone;
    c->anchor.bottom = 0;
    c->anchor.left = 0;
    c->anchor.top = 0;
    c->anchor.right = 0;
    c->anchor.leftAnchor = 0;
    c->anchor.rightAnchor = 0;
    c->anchor.topAnchor = 0;
    c->anchor.bottomAnchor = 0;
    c->data = 0;
    c->enabled = 1;
    c->height = (GLfloat)10;;
    c->width = (GLfloat)10;
    c->visible = 1;
    c->pos.x = x;
    c->pos.y = y;
    c->borderType = glBorderSolid;
    c->borderWidth = (GLfloat)2;

    /*NULL function pointers */
    childObj->common.callbacks.click = NULL;
    childObj->common.callbacks.doubleclick = NULL;
    childObj->common.callbacks.draw = NULL;
    childObj->common.callbacks.mousedown = NULL;
    childObj->common.callbacks.mousein = NULL;
    childObj->common.callbacks.mouseout = NULL;
    childObj->common.callbacks.mouseover = NULL;
    childObj->common.callbacks.mouseup = NULL;

    childObj->common.functions.click = NULL;
    childObj->common.functions.doubleclick = NULL;
    childObj->common.functions.draw = NULL;
    childObj->common.functions.mousedown = NULL;
    childObj->common.functions.mousein = NULL;
    childObj->common.functions.mouseout = NULL;
    childObj->common.functions.mouseover = NULL;
    childObj->common.functions.mouseup = NULL;



    if (parentObj) {
	c->parent = &parentObj->common;
	parent = &parentObj->common;
	copy_glcomp_color(&parent->color, &c->color);
	c->layer = parent->layer + 1;
	c->pos.z = parent->pos.z;
	glCompSetAddObj((glCompSet *) parent->compset, childObj);
    } else {
	c->parent = NULL;
	c->color.R = (GLfloat)0.16;
	c->color.G = (GLfloat)0.44;
	c->color.B = (GLfloat)0.87;
	c->color.A = (GLfloat)0.5;
	c->layer = 0;
	c->pos.z = 0;
    }
    c->font = glNewFontFromParent(childObj, NULL);
}

void glCompEmptyCommon(glCompCommon * c)
{
    glDeleteFont(c->font);
}
glCompSet *glCompSetNew(int w, int h)
{

    glCompSet *s = (glCompSet*)zmalloc(sizeof(glCompSet));
    glCompInitCommon((glCompObj *) s, NULL, (GLfloat) 0, (GLfloat) 0);
    s->common.width = (GLfloat) w;
    s->common.height = (GLfloat) h;
    s->groupCount = 0;
    s->objcnt = 0;
    s->obj = (glCompObj **) 0;
    s->textureCount = 0;
    s->textures = (glCompTex **) 0;
    s->common.font = glNewFontFromParent((glCompObj *) s, NULL);
    s->common.compset = (glCompSet *) s;
    s->common.functions.mouseover = (glcompmouseoverfunc_t)glCompMouseMove;
    s->common.functions.mousedown = (glcompmousedownfunc_t)glCompSetMouseDown;
    s->common.functions.mouseup = (glcompmouseupfunc_t)glCompSetMouseUp;
    glCompMouseInit(&s->mouse);
    return s;
}



void glCompSetAddObj(glCompSet * s, glCompObj * obj)
{
    s->objcnt++;
    s->obj = realloc(s->obj, sizeof(glCompObj *) * s->objcnt);
    s->obj[s->objcnt - 1] = obj;
    obj->common.compset = s;
}







    
    
    
    


    
    
    
    
    
    
    

    
    
    
    
    
	       
    
    
    
		 

    
    
    



void glCompDrawBegin(void)	//pushes a gl stack 
{
    int vPort[4];

    glGetIntegerv(GL_VIEWPORT, vPort);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();


    glOrtho(0, vPort[2], 0, vPort[3], -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_BLEND);

    glPushMatrix();
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);

}

void glCompDrawEnd(void)	//pops the gl stack 
{
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glEnable(GL_DEPTH_TEST);


}

void glCompSetClear(glCompSet * s)
{
/*    int ind = 0;
    for (ind = 0; ind < s->buttoncount; ind++) {
	glCompSetRemoveButton(s, s->buttons[ind]);
    }
    free(s->buttons);
    for (ind = 0; ind < s->labelcount; ind++) {
	free(s->labels[ind]->text);
	free(s->labels[ind]);
    }
    free(s->labels);
    for (ind = 0; ind < s->panelcount; ind++) {
	free(s->panels[ind]);
    }
    free(s->panels);
    free(s);*/
}



int glCompSetDraw(glCompSet * s)
{
    int ind = 0;
    glCompDrawBegin();
    for (; ind < s->objcnt; ind++) {
	s->obj[ind]->common.functions.draw((void *) s->obj[ind]);
    }
    glCompDrawEnd();
    return 1;
}

void glcompsetUpdateBorder(glCompSet * s, int w, int h)
{
    if (w > 0 && h > 0) {
	s->common.width = (GLfloat) w;
	s->common.height = (GLfloat) h;
    }
}
extern int glcompsetGetGroupId(glCompSet * s)
{
    return s->groupCount;
}
extern int glcompsetNextGroupId(glCompSet * s)
{
    int rv = s->groupCount;
    s->groupCount++;
    return rv;
}







    

    
	
    
    
	

    
    
	
    


