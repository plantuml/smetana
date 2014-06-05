#line 1 "graphviz-2.38.0\\lib\\glcomp\\glutils.c" 1
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





#line 16 "graphviz-2.38.0\\lib\\glcomp\\glutils.c" 2
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glutils.c" 1
#line 1 "graphviz-2.38.0\\lib\\glcomp\\glutils.c" 1
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























































































    
    
    
	    

    
	    
    
	    
    
	    
    
	    

    
    
	    

    
    
	    

    
    


    
    
				       
    
					     
					     
    
					   
    
					 
    
					  
    
					   
    
					 
    
					    
					    



    

	
	
	
	

	
	
	
	


    

    
	
	
    




    
	
    

    
	
    
    
	
	
	
    

    
	
	
	
	
	
	
    


    
	
	
	
    

    
	
	
	
	
	
	
	
	
	
    




    
	
	
	
	
	
	
	
	
	
	
	
    

    
	
	
	
	
	
	
	
	
	

    






    
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
    


    
	
	
	
	
	
	
    


    
	
	
	
	
	
	
    


    
	
	
	
	
	
    


    
	
	
	
	
	
	
	
	
	
	
	

    




    
	
	
	
	
	

	
	
	


	
	
	
	
	
	
	
	
	

    


    
	
	
	
	
    


    
	
	
    

    
	
	
	
	
	
	
	
	

	
	
	
	
	


    




    
	
	

	
	
	
	
	
	
	
	
	

	
	
	
    





#line 19 "graphviz-2.38.0\\lib\\glcomp\\glutils.c" 2
/* #include "glexpose.h" */

/* at given depth value, tranforms 2d Window location to 3d gl coords*/
int GetFixedOGLPos(int x, int y, float kts, GLfloat * X, GLfloat * Y,
		   GLfloat * Z)
{
    GLdouble wwinX;
    GLdouble wwinY;
    GLdouble wwinZ;

    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLfloat winX, winY;
    GLdouble posX, posY, posZ;

    glColor4f((GLfloat) 0, (GLfloat) 0, (GLfloat) 0, (GLfloat) 0.001);
    glBegin(GL_POINTS);
    glVertex3f((GLfloat) - 100.00, (GLfloat) - 100.00, (GLfloat) 1.00);
    glEnd();

    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);
    gluProject(-100.0, -100.0, 1.00, modelview, projection, viewport,
	       &wwinX, &wwinY, &wwinZ);

    winX = (float) x;
    winY = (float) viewport[3] - (float) y;
    gluUnProject(winX, winY, wwinZ, modelview, projection, viewport, &posX,
		 &posY, &posZ);
    *X = (GLfloat) posX;
    *Y = (GLfloat) posY;
    *Z = (GLfloat) posZ;

    return 1;

}

/*transforms 2d windows location to 3d gl coords but depth is calculated unlike the previous function*/
int GetOGLPosRef(int x, int y, float *X, float *Y, float *Z)
{

    GLdouble wwinX;
    GLdouble wwinY;
    GLdouble wwinZ;
    GLdouble posX, posY, posZ;


    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLfloat winX, winY;
    //glTranslatef (0.0,0.0,0.0);
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);

    //draw a point  to a not important location to get window coordinates
    glColor4f((GLfloat) 0, (GLfloat) 0, (GLfloat) 0, (GLfloat) 0.001);

    glBegin(GL_POINTS);
    glVertex3f(-100.00, -100.00, 0.00);
    glEnd();
    gluProject(-100.0, -100.0, 0.00, modelview, projection, viewport,
	       &wwinX, &wwinY, &wwinZ);
    winX = (float) x;
    winY = (float) viewport[3] - (float) y;
    gluUnProject(winX, winY, wwinZ, modelview, projection, viewport, &posX,
		 &posY, &posZ);

    *X = (float) posX;
    *Y = (float) posY;
    *Z = (float) posZ;
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//      printf("==>(%d,%d,%d) -> (%f,%f,%f)\n",x,y,wwinZ,*X,*Y,*Z);


    return 1;

}


float GetOGLDistance(int l)
{

    int x, y;
    GLdouble wwinX;
    GLdouble wwinY;
    GLdouble wwinZ;
    GLdouble posX, posY, posZ;
    GLdouble posXX, posYY, posZZ;



    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLfloat winX, winY;




    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);

    //draw a point  to a not important location to get window coordinates
    glColor4f((GLfloat) 0, (GLfloat) 0, (GLfloat) 0, (GLfloat) 0.001);

    glBegin(GL_POINTS);
    glVertex3f(10.00, 10.00, 1.00);
    glEnd();
    gluProject(10.0, 10.0, 1.00, modelview, projection, viewport, &wwinX,
	       &wwinY, &wwinZ);
    x = 50;
    y = 50;
    winX = (float) x;
    winY = (float) viewport[3] - (float) y;
    gluUnProject(winX, winY, wwinZ, modelview, projection, viewport, &posX,
		 &posY, &posZ);
    x = x + l;
    y = 50;
    winX = (float) x;
    winY = (float) viewport[3] - (float) y;
    gluUnProject(winX, winY, wwinZ, modelview, projection, viewport,
		 &posXX, &posYY, &posZZ);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    return ((float) (posXX - posX));

}

/*
	functions def: returns opengl coordinates of firt hit object by using screen coordinates
	x,y; 2D screen coordiantes (usually received from mouse events
	X,Y,Z; pointers to coordinates values to be calculated
	return value: no return value


*/

void to3D(int x, int y, GLfloat * X, GLfloat * Y, GLfloat * Z)
{

    int const WIDTH = 20;

    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLfloat winX, winY;
    GLfloat winZ[400];
    GLdouble posX, posY, posZ;
    int idx;
    static float comp;

    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);

    winX = (float) x;
    winY = (float) viewport[3] - (float) y;

    glReadPixels(x - WIDTH / 2, (int) winY - WIDTH / 2, WIDTH, WIDTH,
		 GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
    comp = -9999999;
    for (idx = 0; idx < WIDTH * WIDTH; idx++) {
//              printf ("Z value:%f ",winZ[idx]);
	if ((winZ[idx] > comp) && (winZ[idx] < 1))
	    comp = winZ[idx];
    }
//      printf ("\n");

    gluUnProject(winX, winY, comp, modelview, projection, viewport, &posX,
		 &posY, &posZ);

    *X = (GLfloat) posX;
    *Y = (GLfloat) posY;
    *Z = (GLfloat) posZ;
    return;





}


int GetFixedOGLPoslocal(int x, int y, GLfloat * X, GLfloat * Y,
			GLfloat * Z)
{
    GLdouble wwinX;
    GLdouble wwinY;
    GLdouble wwinZ;

    GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLfloat winX, winY;
    GLdouble posX, posY, posZ;

    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);



    glColor4f((GLfloat) 0, (GLfloat) 0, (GLfloat) 0, (GLfloat) 0.001);
    glBegin(GL_POINTS);
    glVertex3f(10.00, 10.00, 0.00);
    glEnd();

    gluProject(10.0, 10.0, 1.00, modelview, projection, viewport, &wwinX,
	       &wwinY, &wwinZ);

    winX = (float) x;
    winY = (float) viewport[3] - (float) y;
    gluUnProject(winX, winY, wwinZ, modelview, projection, viewport, &posX,
		 &posY, &posZ);
    *X = (GLfloat) posX;
    *Y = (GLfloat) posY;
    *Z = (GLfloat) posZ;

//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    return 1;

}


			 


    
    
    
    





    
    
	
		  
	
		 
    
	
		 
		 

    

    



#line 1 "graphviz-2.38.0\\lib\\glcomp\\glutils.c" 1






    
    
    
    



static glCompPoint sub(glCompPoint p, glCompPoint q)
{
    p.x -= q.x;
    p.y -= q.y;
    p.z -= q.z;
    return p;
}

static double dot(glCompPoint p, glCompPoint q)
{
    return (p.x * q.x + p.y * q.y + p.z * q.z);
}

static double len(glCompPoint p)
{
    return sqrt(dot(p, p));
}




    
    
    
    



static glCompPoint blend(glCompPoint p, glCompPoint q, float m)
{
    glCompPoint r;

    r.x = p.x + m * (q.x - p.x);
    r.y = p.y + m * (q.y - p.y);
    r.z = p.z + m * (q.z - p.z);
    return r;
}

static double dist(glCompPoint p, glCompPoint q)
{
    return (len(sub(p, q)));
}




    

    




    
    








    
    
    

    
    

    
    

    

    




/*
 * Given a line segment determined by two points a and b, and a 3rd point p,
 * return the distance between the point and the segment.
 * If the perpendicular from p to the line a-b is outside of the segment,
 * return the distance to the closer of a or b.
 */
double point_to_lineseg_dist(glCompPoint p, glCompPoint a, glCompPoint b)
{
    float U;
    glCompPoint q;
    glCompPoint ba = sub(b, a);
    glCompPoint pa = sub(p, a);

    U = (float) (dot(pa, ba) / dot(ba, ba));

    if (U > 1)
	q = b;
    else if (U < 0)
	q = a;
    else
	q = blend(a, b, U);

    return dist(p, q);

}








    
    
    
    
	
	 


void replacestr(char *source, char **target)
{

    if (*target)
	free(*target);
    *target = strdup(source);
}











    
	
	
	
	    
		     
	    
	     
	    
	       
	
	    
		     
							
							
							 
	    
		   
	
	    
		     
	    
	     
						  
								      
								      
								      
								      
	    
	
    
	




void glCompSelectionBox(glCompSet * s)
{
    static GLfloat x, y, w, h;
/*	if (( h < 0)  || (w < 0))
	{
	    glEnable(GL_LINE_STIPPLE);
		glLineStipple(1, 15);
	}*/

    x = s->mouse.pos.x;
    y = s->mouse.pos.y;
    w = s->mouse.dragX;
    h = s->mouse.dragY;
    printf("%f %f  %f  %f \n", x, y, w, h);
    glColor4f(1, 1, 1, 1);
/*	glBegin(GL_POLYGON);
		glVertex2f(x,y);
		glVertex2f(x, y+h);
		glVertex2f(x-w, y+h);
		glVertex2f(x-w, y);
		glVertex2f(x-w, y);

	glEnd();*/

    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(250, 0);
    glVertex2f(250, 250);
    glVertex2f(0, 250);
    glVertex2f(0, 0);

    glEnd();


    glDisable(GL_LINE_STIPPLE);



}





void glCompCalcWidget(glCompCommon * parent, glCompCommon * child,
		      glCompCommon * ref)
{
    /*check alignments first , alignments overrides anchors */
    GLfloat borderWidth;
    ref->height = child->height;
    ref->width = child->width;
    if(!parent)
    {
	child->refPos.x = child->pos.x;
	child->refPos.y = child->pos.y;
	return;
    }
    if (parent->borderType == glBorderNone)
	borderWidth = 0;
    else
	borderWidth = parent->borderWidth;
    if (child->align != glAlignNone)	//if alignment, make sure width and height is no greater than parent
    {
	if (child->width > parent->width)
	    ref->width = parent->width - (float) 2.0 *borderWidth;
	if (child->height > parent->height)
	    ref->height = parent->height - (float) 2.0 *borderWidth;;

    }

    ref->pos.x = parent->refPos.x + ref->pos.x + borderWidth;
    ref->pos.y = parent->refPos.y + ref->pos.y + borderWidth;


    switch (child->align) {
    case glAlignLeft:
	ref->pos.x = parent->refPos.x + borderWidth;
	ref->pos.y = parent->refPos.y + borderWidth;
	ref->height = parent->height - 2 * borderWidth;
	break;
    case glAlignRight:
	ref->pos.x =
	    parent->refPos.x + parent->width - child->width - borderWidth;
	ref->pos.y = parent->refPos.y + borderWidth;
	ref->height = parent->height - 2 * borderWidth;
	break;

    case glAlignTop:
	ref->pos.y =
	    parent->refPos.y + parent->height - child->height -
	    borderWidth;
	ref->pos.x = parent->refPos.x;
	ref->width = parent->width - 2 * borderWidth;
	break;

    case glAlignBottom:
	ref->pos.y = parent->refPos.y + borderWidth;
	ref->pos.x = parent->refPos.x + borderWidth;
	ref->width = parent->width - 2 * borderWidth;
	break;
    case glAlignParent:
	ref->pos.y = parent->refPos.y + borderWidth;
	ref->pos.x = parent->refPos.x + borderWidth;;
	ref->width = parent->width - 2 * borderWidth;;
	ref->height = parent->height - 2 * borderWidth;
	break;
    case glAlignCenter:
    case glAlignNone:
	break;
    }
    if (child->align == glAlignNone)	// No alignment , chekc anchors
    {
	ref->pos.x = parent->refPos.x + child->pos.x + borderWidth;
	ref->pos.y = parent->refPos.y + child->pos.y + borderWidth;

	if (child->anchor.leftAnchor)
	    ref->pos.x =
		parent->refPos.x + child->anchor.left + borderWidth;
	if (child->anchor.bottomAnchor)
	    ref->pos.y =
		parent->refPos.y + child->anchor.bottom + borderWidth;

	if (child->anchor.topAnchor)
	    ref->height =
		parent->refPos.y + parent->height - ref->pos.y -
		child->anchor.top - borderWidth;
	if (child->anchor.rightAnchor)
	    ref->width =
		parent->refPos.x + parent->width - ref->pos.x -
		child->anchor.right - borderWidth;
    }
    child->refPos.x = ref->pos.x;
    child->refPos.y = ref->pos.y;
    child->width = ref->width;
    child->height = ref->height;
}






    



static void glCompQuadVertex(glCompPoint * p0, glCompPoint * p1,
			     glCompPoint * p2, glCompPoint * p3)
{
    glVertex3f(p0->x, p0->y, p0->z);
    glVertex3f(p1->x, p1->y, p1->z);
    glVertex3f(p2->x, p2->y, p2->z);
    glVertex3f(p3->x, p3->y, p3->z);
}

void glCompSetColor(glCompColor * c)
{
    glColor4f(c->R, c->G, c->B, c->A);
}

void glCompDrawRectangle(glCompRect * r)
{
    glBegin(GL_QUADS);
    glVertex3f(r->pos.x, r->pos.y, r->pos.z);
    glVertex3f(r->pos.x + r->w, r->pos.y, r->pos.z);
    glVertex3f(r->pos.x + r->w, r->pos.y + r->h, r->pos.z);
    glVertex3f(r->pos.x, r->pos.y + r->h, r->pos.z);
    glEnd();
}
void glCompDrawRectPrism(glCompPoint * p, GLfloat w, GLfloat h, GLfloat b,
			 GLfloat d, glCompColor * c, int bumped)
{
    static GLfloat color_fac;
    static glCompPoint A, B, C, D, E, F, G, H;
    GLfloat dim = 1.00;
    if (!bumped) {
	color_fac = (GLfloat) 1.3;
	b = b - 2;
	dim = 0.5;
    } else
	color_fac = (GLfloat) 1 / (GLfloat) 1.3;


    A.x = p->x;
    A.y = p->y;
    A.z = p->z;
    B.x = p->x + w;
    B.y = p->y;
    B.z = p->z;
    C.x = p->x + w;
    C.y = p->y + h;
    C.z = p->z;
    D.x = p->x;
    D.y = p->y + h;
    D.z = p->z;
    G.x = p->x + b;
    G.y = p->y + b;
    G.z = p->z + d;
    H.x = p->x + w - b;
    H.y = p->y + b;
    H.z = p->z + d;
    E.x = p->x + b;
    E.y = p->y + h - b;
    E.z = p->z + d;
    F.x = p->x + w - b;
    F.y = p->y + h - b;
    F.z = p->z + d;
    glBegin(GL_QUADS);
    glColor4f(c->R * dim, c->G * dim, c->B * dim, c->A);
    glCompQuadVertex(&G, &H, &F, &E);

    glColor4f(c->R * color_fac * dim, c->G * color_fac * dim,
	      c->B * color_fac * dim, c->A);
    glCompQuadVertex(&A, &B, &H, &G);
    glCompQuadVertex(&B, &H, &F, &C);

    glColor4f(c->R / color_fac * dim, c->G / color_fac * dim,
	      c->B / color_fac * dim, c->A);
    glCompQuadVertex(&A, &G, &E, &D);
    glCompQuadVertex(&E, &F, &C, &D);
    glEnd();

}

void copy_glcomp_color(glCompColor * source, glCompColor * target)
{
    target->R = source->R;
    target->G = source->G;
    target->B = source->B;
    target->A = source->A;

}




    

    
        
    





    
    
    
    




  


GLfloat distBetweenPts(glCompPoint A,glCompPoint B,float R)
{
    GLfloat rv=0;	
    rv=(A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) +(A.z-B.z)*(A.z-B.z);
    rv=sqrt(rv);
    if (rv <=R)
	return 0;
    return rv;
}

int is_point_in_rectangle(float X, float Y, float RX, float RY, float RW,float RH)
{
    if ((X >= RX) && (X <= (RX + RW)) && (Y >= RY) && (Y <= (RY + RH)))
	return 1;
    else
	return 0;
}






