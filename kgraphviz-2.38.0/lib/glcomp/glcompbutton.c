#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompbutton.c" 1
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





#line 16 "graphviz-2.38.0\\lib\\glcomp\\glcompbutton.c" 2
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





#line 17 "graphviz-2.38.0\\lib\\glcomp\\glcompbutton.c" 2
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompimage.h" 1
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























































































    
    
    
	    

    
	    
    
	    
    
	    
    
	    

    
    
	    

    
    
	    

    
    


    
    
				       
    
					     
					     
    
					   
    
					 
    
					  
    
					   
    
					 
    
					    
					    



    

	
	
	
	

	
	
	
	


    

    
	
	
    




    
	
    

    
	
    
    
	
	
	
    

    
	
	
	
	
	
	
    


    
	
	
	
    

    
	
	
	
	
	
	
	
	
	
    




    
	
	
	
	
	
	
	
	
	
	
	
    

    
	
	
	
	
	
	
	
	
	

    






    
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
    


    
	
	
	
	
	
	
    


    
	
	
	
	
	
	
    


    
	
	
	
	
	
    


    
	
	
	
	
	
	
	
	
	
	
	

    




    
	
	
	
	
	

	
	
	


	
	
	
	
	
	
	
	
	

    


    
	
	
	
	
    


    
	
	
    

    
	
	
	
	
	
	
	
	

	
	
	
	
	


    




    
	
	

	
	
	
	
	
	
	
	
	

	
	
	
    





#line 16 "graphviz-2.38.0\\lib\\glcomp\\glcompimage.h" 2





    extern glCompImage *glCompImageNewFile(glCompObj * par, GLfloat x,
				       GLfloat y, char* imgfile, int is2D);
    extern glCompImage *glCompImageNew(glCompObj * par, GLfloat x,
				       GLfloat y);
    extern void glCompImageDelete(glCompImage * p);
    extern int glCompImageLoad(glCompImage * i, unsigned char *data,
			       int width, int height,int is2D);
    extern int glCompImageLoadPng(glCompImage * i, char *pngFile,int is2D);
    extern void glCompImageDraw(void *obj);
    extern void glCompImageClick(glCompObj * o, GLfloat x, GLfloat y,
				 glMouseButtonType t);
    extern void glCompImageDoubleClick(glCompObj * obj, GLfloat x,
				       GLfloat y, glMouseButtonType t);
    extern void glCompImageMouseDown(glCompObj * obj, GLfloat x, GLfloat y,
				     glMouseButtonType t);
    extern void glCompImageMouseIn(glCompObj * obj, GLfloat x, GLfloat y);
    extern void glCompImageMouseOut(glCompObj * obj, GLfloat x, GLfloat y);
    extern void glCompImageMouseOver(glCompObj * obj, GLfloat x,
				     GLfloat y);
    extern void glCompImageMouseUp(glCompObj * obj, GLfloat x, GLfloat y,
				   glMouseButtonType t);





#line 18 "graphviz-2.38.0\\lib\\glcomp\\glcompbutton.c" 2
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





#line 19 "graphviz-2.38.0\\lib\\glcomp\\glcompbutton.c" 2
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





#line 20 "graphviz-2.38.0\\lib\\glcomp\\glcompbutton.c" 2
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





#line 21 "graphviz-2.38.0\\lib\\glcomp\\glcompbutton.c" 2
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







#line 22 "graphviz-2.38.0\\lib\\glcomp\\glcompbutton.c" 2
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompbutton.c" 1
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glcompbutton.c" 1


glCompButton *glCompButtonNew(glCompObj * par, GLfloat x, GLfloat y,
			      GLfloat w, GLfloat h, char *caption)
{
    glCompButton *p;
//      glCompCommon* parent=&par->common;
    p = (glCompButton*)zmalloc(sizeof(glCompButton));
    glCompInitCommon((glCompObj *) p, par, x, y);
    p->objType = glButtonObj;
    /*customize button color */
    p->common.color.R = (GLfloat)0;
    p->common.color.G = (GLfloat)1;
    p->common.color.B = (GLfloat)0.3;
    p->common.color.A = (GLfloat)0.6;

    p->common.borderType = glBorderSolid;

    p->common.borderWidth = (GLfloat)5;

    p->common.width = w;
    p->common.height = h;
    p->status = 0;		//0 not pressed 1 pressed;
    p->groupid = 0;
    p->common.callbacks.click = '\0';
    p->customptr = '\0';
    /*set event functions */

    p->common.functions.draw = (glcompdrawfunc_t)glCompButtonDraw;

    p->common.functions.click = glCompButtonClick;
    p->common.functions.doubleclick = glCompButtonDoubleClick;
    p->common.functions.mousedown = glCompButtonMouseDown;
    p->common.functions.mousein = glCompButtonMouseIn;
    p->common.functions.mouseout = glCompButtonMouseOut;
    p->common.functions.mouseover = glCompButtonMouseOver;
    p->common.functions.mouseup = glCompButtonMouseUp;

    /*caption */
    p->common.font = glNewFontFromParent ((glCompObj *) p, NULL);
    p->label = glCompLabelNew((glCompObj *) p, 0, 0, caption);
    p->label->common.font->justify.VJustify = glFontVJustifyCenter;
    p->label->common.font->justify.HJustify = glFontHJustifyCenter;
    p->label->common.align = glAlignParent;
    /*image */
    p->image = (glCompImage *) 0;
    p->glyphPos = glButtonGlyphLeft;
    return p;
}

int glCompButtonAddPngGlyph(glCompButton * b, char *fileName)
{
    int rv;
    /*delete if there is an existing image */
    if (b->image)
	glCompImageDelete(b->image);
    /*image on left for now */
    b->image = glCompImageNew((glCompObj *) b, 0, 0);

    rv = glCompImageLoadPng(b->image, fileName,1);
    if (rv) {
	b->image->common.anchor.leftAnchor = 1;
	b->image->common.anchor.left = 0;

	b->image->common.anchor.topAnchor = 1;
	b->image->common.anchor.top = 0;

	b->image->common.anchor.bottomAnchor = 1;
	b->image->common.anchor.bottom = 0;

	b->label->common.anchor.leftAnchor = 1;
	b->label->common.anchor.left = b->image->common.width;
	b->label->common.anchor.rightAnchor = 1;
	b->label->common.anchor.right = 0;

	b->label->common.anchor.topAnchor = 1;
	b->label->common.anchor.top = 0;

	b->label->common.anchor.bottomAnchor = 1;
	b->label->common.anchor.bottom = 0;

	b->label->common.align = glAlignNone;
    }
    return rv;
}

void glCompButtonHide(glCompButton * p)
{
    p->common.visible = 0;
    if (p->label)
	p->label->common.visible = 0;
    if (p->image)
	p->image->common.visible = 0;
}

void glCompButtonShow(glCompButton * p)
{
    p->common.visible = 1;
    if (p->label)
	p->label->common.visible = 1;
    if (p->image)
	p->image->common.visible = 1;
}

void glCompButtonDraw(glCompButton * p)
{

    glCompCommon ref;
    ref = p->common;
    glCompCalcWidget((glCompCommon *) p->common.parent, &p->common, &ref);
    if (!p->common.visible)
	return;
    /*draw panel */
    glCompDrawRectPrism(&(ref.pos), ref.width, ref.height,
			p->common.borderWidth, 0.01, &(ref.color),
			!p->status);
    if (p->label)
	p->label->common.functions.draw((void *) p->label);
    if (p->image)
	p->image->common.functions.draw((void *) p->image);
    if (p->common.callbacks.draw)
	p->common.callbacks.draw((void *) p);	/*user defined drawing routines are called here. */
}

void glCompButtonClick(glCompObj * o, GLfloat x, GLfloat y,
		       glMouseButtonType t)
{
    glCompButton *p = (glCompButton *) o;
    glCompObj *obj;
    glCompSet *s = o->common.compset;
    int ind = 0;
    ((glCompButton *) o)->status=((glCompButton *) o)->refStatus ;
    if (p->groupid > 0) 
    {
	for (; ind < s->objcnt; ind++) {
	    obj = s->obj[ind];
	    if ((obj->objType == glButtonObj)&&(obj!=o)) {
		if (((glCompButton *) obj)->groupid == p->groupid)
		    ((glCompButton *) obj)->status = 0;
	    }
	}
	p->status = 1;
    }
    else {
	if (p->groupid == -1) {
	    if (p->status == 0)
		p->status = 1;
	    else
		p->status = 0;
	} else
	    p->status = 0;
    }
    if (p->common.callbacks.click)
	p->common.callbacks.click((glCompObj *) p, x, y, t);
}

void glCompButtonDoubleClick(glCompObj * obj, GLfloat x, GLfloat y,
			     glMouseButtonType t)
{
    /*Put your internal code here */
    if (((glCompButton *) obj)->common.callbacks.doubleclick)
	((glCompButton *) obj)->common.callbacks.doubleclick(obj, x, y, t);
}

void glCompButtonMouseDown(glCompObj * obj, GLfloat x, GLfloat y,
			   glMouseButtonType t)
{
    /*Put your internal code here */

    
    ((glCompButton *) obj)->refStatus = ((glCompButton *) obj)->status;
    ((glCompButton *) obj)->status = 1;
    if (((glCompButton *) obj)->common.callbacks.mousedown)
	((glCompButton *) obj)->common.callbacks.mousedown(obj, x, y, t);
}

void glCompButtonMouseIn(glCompObj * obj, GLfloat x, GLfloat y)
{
    /*Put your internal code here */
    if (((glCompButton *) obj)->common.callbacks.mousein)
	((glCompButton *) obj)->common.callbacks.mousein(obj, x, y);
}

void glCompButtonMouseOut(glCompObj * obj, GLfloat x, GLfloat y)
{
    /*Put your internal code here */
    if (((glCompButton *) obj)->common.callbacks.mouseout)
	((glCompButton *) obj)->common.callbacks.mouseout(obj, x, y);
}

void glCompButtonMouseOver(glCompObj * obj, GLfloat x, GLfloat y)
{
    /*Put your internal code here */
    if (((glCompButton *) obj)->common.callbacks.mouseover)
	((glCompButton *) obj)->common.callbacks.mouseover(obj, x, y);
}

void glCompButtonMouseUp(glCompObj * obj, GLfloat x, GLfloat y,
			 glMouseButtonType t)
{
    /*Put your internal code here */

    if (((glCompButton *) obj)->common.callbacks.mouseup)
	((glCompButton *) obj)->common.callbacks.mouseup(obj, x, y, t);
}




void glCompButtonSetText(glCompButton * p, char *str)
{
//    replacestr(str, &p->text);
}
