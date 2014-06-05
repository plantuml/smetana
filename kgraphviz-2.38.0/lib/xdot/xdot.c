#line 1 "graphviz-2.38.0\\lib\\xdot\\xdot.c" 1
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

#line 1 "graphviz-2.38.0\\lib\\xdot\\xdot.h" 1
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



#line 1 "graphviz-2.38.0\\lib\\xdot\\xdot.h" 1










typedef enum {
    xd_none,
    xd_linear,
    xd_radial
} xdot_grad_type;

typedef struct {
    float frac;
    char* color;
} xdot_color_stop;

typedef struct {
    double x0, y0;
    double x1, y1;
    int n_stops;
    xdot_color_stop* stops;
} xdot_linear_grad;

typedef struct {
    double x0, y0, r0;
    double x1, y1, r1;
    int n_stops;
    xdot_color_stop* stops;
} xdot_radial_grad;

typedef struct {
    xdot_grad_type type;
    union {
	char* clr;
	xdot_linear_grad ling;
	xdot_radial_grad ring;
    } u;
} xdot_color;

typedef enum {
    xd_left, xd_center, xd_right
} xdot_align;

typedef struct {
    double x, y, z;
} xdot_point;

typedef struct {
    double x, y, w, h;
} xdot_rect;

typedef struct {
    int cnt;
    xdot_point* pts;
} xdot_polyline;

typedef struct {
  double x, y;
  xdot_align align;
  double width;
  char* text;
} xdot_text;

typedef struct {
    xdot_rect pos;
    char* name;
} xdot_image;

typedef struct {
    double size;
    char* name;
} xdot_font;

typedef enum {
    xd_filled_ellipse, xd_unfilled_ellipse,
    xd_filled_polygon, xd_unfilled_polygon,
    xd_filled_bezier,  xd_unfilled_bezier,
    xd_polyline,       xd_text,
    xd_fill_color,     xd_pen_color, xd_font, xd_style, xd_image,
    xd_grad_fill_color,     xd_grad_pen_color,
    xd_fontchar
} xdot_kind; 
    
typedef enum {
    xop_ellipse,
    xop_polygon,
    xop_bezier,
    xop_polyline,       xop_text,
    xop_fill_color,     xop_pen_color, xop_font, xop_style, xop_image,
    xop_grad_color,
    xop_fontchar
} xop_kind; 
    
typedef struct _xdot_op xdot_op;
typedef void (*drawfunc_t)(xdot_op*, int);
typedef void (*freefunc_t)(xdot_op*);

struct _xdot_op {
    xdot_kind kind;
    union {
      xdot_rect ellipse;       /* xd_filled_ellipse, xd_unfilled_ellipse */
      xdot_polyline polygon;   /* xd_filled_polygon, xd_unfilled_polygon */
      xdot_polyline polyline;  /* xd_polyline */
      xdot_polyline bezier;    /* xd_filled_bezier,  xd_unfilled_bezier */
      xdot_text text;          /* xd_text */
      xdot_image image;        /* xd_image */
      char* color;             /* xd_fill_color, xd_pen_color */
      xdot_color grad_color;   /* xd_grad_fill_color, xd_grad_pen_color */
      xdot_font font;          /* xd_font */
      char* style;             /* xd_style */
      unsigned int fontchar;   /* xd_fontchar */
    } u;
    drawfunc_t drawfunc;
};



typedef struct {
    int cnt;  /* no. of xdot ops */
    int sz;   /* sizeof structure containing xdot_op as first field */
    xdot_op* ops;
    freefunc_t freefunc;
    int flags;
} xdot;

typedef struct {
    int cnt;  /* no. of xdot ops */
    int n_ellipse;
    int n_polygon;
    int n_polygon_pts;
    int n_polyline;
    int n_polyline_pts;
    int n_bezier;
    int n_bezier_pts;
    int n_text;
    int n_font;
    int n_style;
    int n_color;
    int n_image;
    int n_gradcolor;
    int n_fontchar;
} xdot_stats;

/* ops are indexed by xop_kind */
extern xdot* parseXDotF (char*, drawfunc_t opfns[], int sz);
extern xdot* parseXDotFOn (char*, drawfunc_t opfns[], int sz, xdot*);
extern xdot* parseXDot (char*);
extern char* sprintXDot (xdot*);
extern void fprintXDot (FILE*, xdot*);
extern void jsonXDot (FILE*, xdot*);
extern void freeXDot (xdot*);
extern int statXDot (xdot*, xdot_stats*);
extern xdot_grad_type colorTypeXDot (char*);
extern char* parseXDotColor (char* cp, xdot_color* clr);
extern void freeXDotColor (xdot_color*);





#line 15 "graphviz-2.38.0\\lib\\xdot\\xdot.c" 2
#line 1 "graphviz-2.38.0\\lib\\xdot\\xdot.c" 1
#line 1 "graphviz-2.38.0\\lib\\xdot\\xdot.c" 1
#line 1 "graphviz-2.38.0\\lib\\xdot\\xdot.c" 1




typedef struct {
    unsigned char *buf;		/* start of buffer */
    unsigned char *ptr;		/* next place to write */
    unsigned char *eptr;	/* end of buffer */
    int dyna;			/* true if buffer is malloc'ed */
} agxbuf;





static void agxbinit(agxbuf * xb, unsigned int hint, unsigned char *init)
{
    if (init) {
	xb->buf = init;
	xb->dyna = 0;
    } else {
	if (hint == 0)
	    hint = BUFSIZ;
	xb->dyna = 1;
	xb->buf = (unsigned char*)calloc((hint), sizeof(unsigned char));
    }
    xb->eptr = xb->buf + hint;
    xb->ptr = xb->buf;
    *xb->ptr = '\0';
}
static int agxbmore(agxbuf * xb, unsigned int ssz)
{
    int cnt;			/* current no. of characters in buffer */
    int size;			/* current buffer size */
    int nsize;			/* new buffer size */
    unsigned char *nbuf;	/* new buffer */

    size = xb->eptr - xb->buf;
    nsize = 2 * size;
    if (size + ssz > nsize)
	nsize = size + ssz;
    cnt = xb->ptr - xb->buf;
    if (xb->dyna) {
	nbuf = realloc(xb->buf, nsize);
    } else {
	nbuf = (unsigned char*)calloc((nsize), sizeof(unsigned char));
	memcpy(nbuf, xb->buf, cnt);
	xb->dyna = 1;
    }
    xb->buf = nbuf;
    xb->ptr = xb->buf + cnt;
    xb->eptr = xb->buf + nsize;
    return 0;
}

static int agxbput(char *s, agxbuf * xb)
{
    unsigned int ssz = strlen(s);
    if (xb->ptr + ssz > xb->eptr)
	agxbmore(xb, ssz);
    memcpy(xb->ptr, s, ssz);
    xb->ptr += ssz;
    return ssz;
}

/* agxbfree:
 * Free any malloced resources.
 */
static void agxbfree(agxbuf * xb)
{
    if (xb->dyna)
	free(xb->buf);
}

/* the parse functions should return NULL on error */
static char *parseReal(char *s, double *fp)
{
    char *p;
    double d;

    d = strtod(s, &p);
    if (p == s) return 0;
	
    *fp = d;
    return (p);
}


static char *parseInt(char *s, int *ip)
{
    char* endp;


    
    
    


    *ip = (int)strtol (s, &endp, 10);
    if (s == endp)
	return 0;
    else
	return endp;
}

static char *parseUInt(char *s, unsigned int *ip)
{
    char* endp;

    *ip = (unsigned int)strtoul (s, &endp, 10);
    if (s == endp)
	return 0;
    else
	return endp;
}




    
    
    
    
    



static char *parseRect(char *s, xdot_rect * rp)
{
    char* endp;

    
    
	       
    
    


    rp->x = strtod (s, &endp);
    if (s == endp)
	return 0;
    else
	s = endp;

    rp->y = strtod (s, &endp);
    if (s == endp)
	return 0;
    else
	s = endp;

    rp->w = strtod (s, &endp);
    if (s == endp)
	return 0;
    else
	s = endp;

    rp->h = strtod (s, &endp);
    if (s == endp)
	return 0;
    else
	s = endp;

    return s;
}

static char *parsePolyline(char *s, xdot_polyline * pp)
{
    int i;
    xdot_point *pts;
    xdot_point *ps;
    char* endp;

    s = parseInt(s, &i);
    if (!s) return s;
    pts = ps = (xdot_point*)calloc((i), sizeof(xdot_point));
    pp->cnt = i;
    for (i = 0; i < pp->cnt; i++) {
	ps->x = strtod (s, &endp);
	if (s == endp) {
	    free (pts);
	    return 0;
	}
	else
	    s = endp;
	ps->y = strtod (s, &endp);
	if (s == endp) {
	    free (pts);
	    return 0;
	}
	else
	    s = endp;
	ps->z = 0;
	ps++;
    }
    pp->pts = pts;
    return s;
}

static char *parseString(char *s, char **sp)
{
    int i;
    char *c;
    char *p;
    s = parseInt(s, &i);
    if (!s || (i <= 0)) return 0;
    while (*s && (*s != '-')) s++;
    if (*s) s++;
    else {
	return 0;
    }
    c = (char*)calloc((i + 1), sizeof(char));
    p = c;
    while ((i > 0) && *s) {
	*p++ = *s++;
	i--;
    }
    if (i > 0) {
	free (c);
	return 0;
    }

    *p = '\0';
    *sp = c;
    return s;
}

static char *parseAlign(char *s, xdot_align * ap)
{
    int i;
    s = parseInt(s, &i);

    if (i < 0)
	*ap = xd_left;
    else if (i > 0)
	*ap = xd_right;
    else
	*ap = xd_center;
    return s;
}



static char *parseOp(xdot_op * op, char *s, drawfunc_t ops[], int* error)
{
    char* cs;
    xdot_color clr;

    *error = 0;
    while (isspace(*s))
	s++;
    switch (*s++) {
    case 'E':
	op->kind = xd_filled_ellipse;
	s = parseRect(s, &op->u.ellipse);
	if(!s){*error=1;return 0;};
	if (ops)
	    op->drawfunc = ops[xop_ellipse];
	break;

    case 'e':
	op->kind = xd_unfilled_ellipse;
	s = parseRect(s, &op->u.ellipse);
	if(!s){*error=1;return 0;};
	if (ops)
	    op->drawfunc = ops[xop_ellipse];
	break;

    case 'P':
	op->kind = xd_filled_polygon;
	s = parsePolyline(s, &op->u.polygon);
	if(!s){*error=1;return 0;};
	if (ops)
	    op->drawfunc = ops[xop_polygon];
	break;

    case 'p':
	op->kind = xd_unfilled_polygon;
	s = parsePolyline(s, &op->u.polygon);
	if(!s){*error=1;return 0;};
	if (ops)
	    op->drawfunc = ops[xop_polygon];
	break;

    case 'b':
	op->kind = xd_filled_bezier;
	s = parsePolyline(s, &op->u.bezier);
	if(!s){*error=1;return 0;};
	if (ops)
	    op->drawfunc = ops[xop_bezier];
	break;

    case 'B':
	op->kind = xd_unfilled_bezier;
	s = parsePolyline(s, &op->u.bezier);
	if(!s){*error=1;return 0;};
	if (ops)
	    op->drawfunc = ops[xop_bezier];
	break;

    case 'c':
	s = parseString(s, &cs);
	if(!s){*error=1;return 0;};
	cs = parseXDotColor (cs, &clr);
	if(!cs){*error=1;return 0;};
	if (clr.type == xd_none) {
	    op->kind = xd_pen_color;
	    op->u.color = clr.u.clr;
	    if (ops)
		op->drawfunc = ops[xop_pen_color];
	}
	else {
	    op->kind = xd_grad_pen_color;
	    op->u.grad_color = clr;
	    if (ops)
		op->drawfunc = ops[xop_grad_color];
	}
	break;

    case 'C':
	s = parseString(s, &cs);
	if(!s){*error=1;return 0;};
	cs = parseXDotColor (cs, &clr);
	if(!cs){*error=1;return 0;};
	if (clr.type == xd_none) {
	    op->kind = xd_fill_color;
	    op->u.color = clr.u.clr;
	    if (ops)
		op->drawfunc = ops[xop_fill_color];
	}
	else {
	    op->kind = xd_grad_fill_color;
	    op->u.grad_color = clr;
	    if (ops)
		op->drawfunc = ops[xop_grad_color];
	}
	break;

    case 'L':
	op->kind = xd_polyline;
	s = parsePolyline(s, &op->u.polyline);
	if(!s){*error=1;return 0;};
	if (ops)
	    op->drawfunc = ops[xop_polyline];
	break;

    case 'T':
	op->kind = xd_text;
	s = parseReal(s, &op->u.text.x);
	if(!s){*error=1;return 0;};
	s = parseReal(s, &op->u.text.y);
	if(!s){*error=1;return 0;};
	s = parseAlign(s, &op->u.text.align);
	if(!s){*error=1;return 0;};
	s = parseReal(s, &op->u.text.width);
	if(!s){*error=1;return 0;};
	s = parseString(s, &op->u.text.text);
	if(!s){*error=1;return 0;};
	if (ops)
	    op->drawfunc = ops[xop_text];
	break;

    case 'F':
	op->kind = xd_font;
	s = parseReal(s, &op->u.font.size);
	if(!s){*error=1;return 0;};
	s = parseString(s, &op->u.font.name);
	if(!s){*error=1;return 0;};
	if (ops)
	    op->drawfunc = ops[xop_font];
	break;

    case 'S':
	op->kind = xd_style;
	s = parseString(s, &op->u.style);
	if(!s){*error=1;return 0;};
	if (ops)
	    op->drawfunc = ops[xop_style];
	break;

    case 'I':
	op->kind = xd_image;
	s = parseRect(s, &op->u.image.pos);
	if(!s){*error=1;return 0;};
	s = parseString(s, &op->u.image.name);
	if(!s){*error=1;return 0;};
	if (ops)
	    op->drawfunc = ops[xop_image];
	break;

    case 't':
	op->kind = xd_fontchar;
	s = parseUInt(s, &op->u.fontchar);
	if(!s){*error=1;return 0;};
	if (ops)
	    op->drawfunc = ops[xop_fontchar];
	break;


    case '\0':
	s = 0;
	break;

    default:
	*error = 1;
	s = 0;
	break;
    }
    return s;
}



/* parseXDotFOn:
 * Parse and append additional xops onto a given xdot object.
 * Return x.
 */ 
xdot *parseXDotFOn (char *s, drawfunc_t fns[], int sz, xdot* x)
{
    xdot_op op;
    char *ops;
    int oldsz, bufsz;
    int error;
    int initcnt;

    if (!s)
	return x;

    if (!x) {
	x = (xdot*)calloc(1, sizeof(xdot));
	if (sz <= sizeof(xdot_op))
	    sz = sizeof(xdot_op);

	/* cnt, freefunc, ops, flags zeroed by NEW */
	x->sz = sz;
    }
    initcnt = x->cnt;
    sz = x->sz;

    if (initcnt == 0) {
	bufsz = 100;
	ops = (char *) calloc(100, sz);
    }
    else {
	ops = (char*)(x->ops);
	bufsz = initcnt + 100;
	ops = (char *) realloc(ops, bufsz * sz);
	memset(ops + (initcnt*sz), '\0', (bufsz - initcnt)*sz);
    }

    while ((s = parseOp(&op, s, fns, &error))) {
	if (x->cnt == bufsz) {
	    oldsz = bufsz;
	    bufsz *= 2;
	    ops = (char *) realloc(ops, bufsz * sz);
	    memset(ops + (oldsz*sz), '\0', (bufsz - oldsz)*sz);
	}
	*(xdot_op *) (ops + (x->cnt * sz)) = op;
	x->cnt++;
    }
    if (error)
	x->flags |= 1;
    if (x->cnt) {
	x->ops = (xdot_op *) realloc(ops, x->cnt * sz);
    }
    else {
	free (ops);
	free (x);
	x = NULL;
    }

    return x;

}

xdot *parseXDotF(char *s, drawfunc_t fns[], int sz)
{
    return parseXDotFOn (s, fns, sz, NULL);
}

xdot *parseXDot(char *s)
{
    return parseXDotF(s, 0, 0);
}

typedef void (*pf) (char *, void *);

/* trim:
 * Trailing zeros are removed and decimal point, if possible.
 */
static void trim (char* buf)
{
    char* dotp;
    char* p;

    if ((dotp = strchr (buf,'.'))) {
        p = dotp+1;
        while (*p) p++;  // find end of string
        p--;
        while (*p == '0') *p-- = '\0';
        if (*p == '.')        // If all decimals were zeros, remove ".".
            *p = '\0';
        else
            p++;
    }
}

static void printRect(xdot_rect * r, pf print, void *info)
{
    char buf[128];

    sprintf(buf, " %.02f", r->x);
    trim(buf);
    print(buf, info);
    sprintf(buf, " %.02f", r->y);
    trim(buf);
    print(buf, info);
    sprintf(buf, " %.02f", r->w);
    trim(buf);
    print(buf, info);
    sprintf(buf, " %.02f", r->h);
    trim(buf);
    print(buf, info);
}

static void printPolyline(xdot_polyline * p, pf print, void *info)
{
    int i;
    char buf[512];

    sprintf(buf, " %d", p->cnt);
    print(buf, info);
    for (i = 0; i < p->cnt; i++) {
	sprintf(buf, " %.02f", p->pts[i].x);
	trim(buf);
	print(buf, info);
	sprintf(buf, " %.02f", p->pts[i].y);
	trim(buf);
	print(buf, info);
    }
}

static void printString(char *p, pf print, void *info)
{
    char buf[30];

    sprintf(buf, " %d -", (int) strlen(p));
    print(buf, info);
    print(p, info);
}

static void printInt(int i, pf print, void *info)
{
    char buf[30];

    sprintf(buf, " %d", i);
    print(buf, info);
}

static void printFloat(float f, pf print, void *info, int space)
{
    char buf[128];

    if (space)
	sprintf(buf, " %.02f", f);
    else
	sprintf(buf, "%.02f", f);
    trim (buf);
    print(buf, info);
}

static void printAlign(xdot_align a, pf print, void *info)
{
    switch (a) {
    case xd_left:
	print(" -1", info);
	break;
    case xd_right:
	print(" 1", info);
	break;
    case xd_center:
	print(" 0", info);
	break;
    }
}

static void
gradprint (char* s, void* v)
{
    agxbput(s, (agxbuf*)v);
}

static void
toGradString (agxbuf* xb, xdot_color* cp)
{
    int i, n_stops;
    xdot_color_stop* stops;

    if (cp->type == xd_linear) {
	((((xb)->ptr >= (xb)->eptr) ? agxbmore(xb,1) : 0), (int)(*(xb)->ptr++ = ((unsigned char)'[')));
	printFloat (cp->u.ling.x0, gradprint, xb, 0);
	printFloat (cp->u.ling.y0, gradprint, xb, 1);
	printFloat (cp->u.ling.x1, gradprint, xb, 1);
	printFloat (cp->u.ling.y1, gradprint, xb, 1);
	n_stops = cp->u.ling.n_stops;
	stops = cp->u.ling.stops;
    }
    else {
	((((xb)->ptr >= (xb)->eptr) ? agxbmore(xb,1) : 0), (int)(*(xb)->ptr++ = ((unsigned char)'(')));
	printFloat (cp->u.ring.x0, gradprint, xb, 0);
	printFloat (cp->u.ring.y0, gradprint, xb, 1);
	printFloat (cp->u.ring.r0, gradprint, xb, 1);
	printFloat (cp->u.ring.x1, gradprint, xb, 1);
	printFloat (cp->u.ring.y1, gradprint, xb, 1);
	printFloat (cp->u.ring.r1, gradprint, xb, 1);
	n_stops = cp->u.ring.n_stops;
	stops = cp->u.ring.stops;
    }
    printInt (n_stops, gradprint, xb);
    for (i = 0; i < n_stops; i++) {
	printFloat (stops[i].frac, gradprint, xb, 1);
	printString (stops[i].color, gradprint, xb);
    }

    if (cp->type == xd_linear)
	((((xb)->ptr >= (xb)->eptr) ? agxbmore(xb,1) : 0), (int)(*(xb)->ptr++ = ((unsigned char)']')));
    else
	((((xb)->ptr >= (xb)->eptr) ? agxbmore(xb,1) : 0), (int)(*(xb)->ptr++ = ((unsigned char)')')));
}

typedef void (*print_op)(xdot_op * op, pf print, void *info, int more);

static void printXDot_Op(xdot_op * op, pf print, void *info, int more)
{
    agxbuf xb;
    unsigned char buf[BUFSIZ];

    agxbinit (&xb, BUFSIZ, buf);
    switch (op->kind) {
    case xd_filled_ellipse:
	print("E", info);
	printRect(&op->u.ellipse, print, info);
	break;
    case xd_unfilled_ellipse:
	print("e", info);
	printRect(&op->u.ellipse, print, info);
	break;
    case xd_filled_polygon:
	print("P", info);
	printPolyline(&op->u.polygon, print, info);
	break;
    case xd_unfilled_polygon:
	print("p", info);
	printPolyline(&op->u.polygon, print, info);
	break;
    case xd_filled_bezier:
	print("b", info);
	printPolyline(&op->u.bezier, print, info);
	break;
    case xd_unfilled_bezier:
	print("B", info);
	printPolyline(&op->u.bezier, print, info);
	break;
    case xd_pen_color:
	print("c", info);
	printString(op->u.color, print, info);
	break;
    case xd_grad_pen_color:
	print("c", info);
	toGradString (&xb, &op->u.grad_color);
	printString((((((&xb)->ptr >= (&xb)->eptr) ? agxbmore(&xb,1) : 0), (int)(*(&xb)->ptr++ = ((unsigned char)'\0'))),(char*)((&xb)->ptr = (&xb)->buf)), print, info);
	break;
    case xd_fill_color:
	print("C", info);
	printString(op->u.color, print, info);
	break;
    case xd_grad_fill_color:
	print("C", info);
	toGradString (&xb, &op->u.grad_color);
	printString((((((&xb)->ptr >= (&xb)->eptr) ? agxbmore(&xb,1) : 0), (int)(*(&xb)->ptr++ = ((unsigned char)'\0'))),(char*)((&xb)->ptr = (&xb)->buf)), print, info);
	break;
    case xd_polyline:
	print("L", info);
	printPolyline(&op->u.polyline, print, info);
	break;
    case xd_text:
	print("T", info);
	printInt(op->u.text.x, print, info);
	printInt(op->u.text.y, print, info);
	printAlign(op->u.text.align, print, info);
	printInt(op->u.text.width, print, info);
	printString(op->u.text.text, print, info);
	break;
    case xd_font:
	print("F", info);
	printFloat(op->u.font.size, print, info, 1);
	printString(op->u.font.name, print, info);
	break;
    case xd_fontchar:
	print("t", info);
	printInt(op->u.fontchar, print, info);
	break;
    case xd_style:
	print("S", info);
	printString(op->u.style, print, info);
	break;
    case xd_image:
	print("I", info);
	printRect(&op->u.image.pos, print, info);
	printString(op->u.image.name, print, info);
	break;
    }
    if (more)
	print(" ", info);
    agxbfree (&xb);
}

static void jsonRect(xdot_rect * r, pf print, void *info)
{
    char buf[128];

    sprintf(buf, "[%.06f,%.06f,%.06f,%.06f]", r->x, r->y, r->w, r->h);
    print(buf, info);
}

static void jsonPolyline(xdot_polyline * p, pf print, void *info)
{
    int i;
    char buf[128];

    print("[", info);
    for (i = 0; i < p->cnt; i++) {
	sprintf(buf, "%.06f,%.06f", p->pts[i].x, p->pts[i].y);
	print(buf, info);
	if (i < p->cnt-1) print(",", info);
    }
    print("]", info);
}

static void jsonString(char *p, pf print, void *info)
{
    unsigned char c, buf[BUFSIZ];
    agxbuf xb;

    agxbinit(&xb, BUFSIZ, buf);
    ((((&xb)->ptr >= (&xb)->eptr) ? agxbmore(&xb,1) : 0), (int)(*(&xb)->ptr++ = ((unsigned char)'"')));
    while ((c = *p++)) {
	if (c == '"') agxbput("\\\"", &xb);
	else if (c == '\\') agxbput("\\\\", &xb);
	/* else if (c > 127) handle UTF-8 */
	else ((((&xb)->ptr >= (&xb)->eptr) ? agxbmore(&xb,1) : 0), (int)(*(&xb)->ptr++ = ((unsigned char)c)));
    }
    ((((&xb)->ptr >= (&xb)->eptr) ? agxbmore(&xb,1) : 0), (int)(*(&xb)->ptr++ = ((unsigned char)'"')));
    print((((((&xb)->ptr >= (&xb)->eptr) ? agxbmore(&xb,1) : 0), (int)(*(&xb)->ptr++ = ((unsigned char)'\0'))),(char*)((&xb)->ptr = (&xb)->buf)), info);
    agxbfree(&xb);
}

static void jsonXDot_Op(xdot_op * op, pf print, void *info, int more)
{
    agxbuf xb;
    unsigned char buf[BUFSIZ];

    agxbinit (&xb, BUFSIZ, buf);
    switch (op->kind) {
    case xd_filled_ellipse:
	print("{E : ", info);
	jsonRect(&op->u.ellipse, print, info);
	break;
    case xd_unfilled_ellipse:
	print("{e : ", info);
	jsonRect(&op->u.ellipse, print, info);
	break;
    case xd_filled_polygon:
	print("{P : ", info);
	jsonPolyline(&op->u.polygon, print, info);
	break;
    case xd_unfilled_polygon:
	print("{p : ", info);
	jsonPolyline(&op->u.polygon, print, info);
	break;
    case xd_filled_bezier:
	print("{b : ", info);
	jsonPolyline(&op->u.bezier, print, info);
	break;
    case xd_unfilled_bezier:
	print("{B : ", info);
	jsonPolyline(&op->u.bezier, print, info);
	break;
    case xd_pen_color:
	print("{c : ", info);
	jsonString(op->u.color, print, info);
	break;
    case xd_grad_pen_color:
	print("{c : ", info);
	toGradString (&xb, &op->u.grad_color);
	jsonString((((((&xb)->ptr >= (&xb)->eptr) ? agxbmore(&xb,1) : 0), (int)(*(&xb)->ptr++ = ((unsigned char)'\0'))),(char*)((&xb)->ptr = (&xb)->buf)), print, info);
	break;
    case xd_fill_color:
	print("{C : ", info);
	jsonString(op->u.color, print, info);
	break;
    case xd_grad_fill_color:
	print("{C : ", info);
	toGradString (&xb, &op->u.grad_color);
	jsonString((((((&xb)->ptr >= (&xb)->eptr) ? agxbmore(&xb,1) : 0), (int)(*(&xb)->ptr++ = ((unsigned char)'\0'))),(char*)((&xb)->ptr = (&xb)->buf)), print, info);
	break;
    case xd_polyline:
	print("{L :", info);
	jsonPolyline(&op->u.polyline, print, info);
	break;
    case xd_text:
	print("{T : [", info);
	printInt(op->u.text.x, print, info);
	print(",", info);
	printInt(op->u.text.y, print, info);
	print(",", info);
	printAlign(op->u.text.align, print, info);
	print(",", info);
	printInt(op->u.text.width, print, info);
	print(",", info);
	jsonString(op->u.text.text, print, info);
	print("]", info);
	break;
    case xd_font:
	print("{F : [", info);
	op->kind = xd_font;
	printFloat(op->u.font.size, print, info, 1);
	print(",", info);
	jsonString(op->u.font.name, print, info);
	print("]", info);
	break;
    case xd_fontchar:
	print("{t : ", info);
	printInt(op->u.fontchar, print, info);
	break;
    case xd_style:
	print("{S : ", info);
	jsonString(op->u.style, print, info);
	break;
    case xd_image:
	print("{I : [", info);
	jsonRect(&op->u.image.pos, print, info);
	print(",", info);
	jsonString(op->u.image.name, print, info);
	print("]", info);
	break;
    }
    if (more)
	print("},\n", info);
    else
	print("}\n", info);
    agxbfree (&xb);
}

static void _printXDot(xdot * x, pf print, void *info, print_op ofn)
{
    int i;
    xdot_op *op;
    char *base = (char *) (x->ops);
    for (i = 0; i < x->cnt; i++) {
	op = (xdot_op *) (base + i * x->sz);
	ofn(op, print, info, (i < x->cnt - 1));
    }
}

char *sprintXDot(xdot * x)
{
    char *s;
    unsigned char buf[BUFSIZ];
    agxbuf xb;
    agxbinit(&xb, BUFSIZ, buf);
    _printXDot(x, (pf) agxbput, &xb, printXDot_Op);
    s = strdup((((((&xb)->ptr >= (&xb)->eptr) ? agxbmore(&xb,1) : 0), (int)(*(&xb)->ptr++ = ((unsigned char)'\0'))),(char*)((&xb)->ptr = (&xb)->buf)));
    agxbfree(&xb);

    return s;
}

void fprintXDot(FILE * fp, xdot * x)
{
    _printXDot(x, (pf) fputs, fp, printXDot_Op);
}

void jsonXDot(FILE * fp, xdot * x)
{
    fputs ("[\n", fp);
    _printXDot(x, (pf) fputs, fp, jsonXDot_Op);
    fputs ("]\n", fp);
}

static void freeXOpData(xdot_op * x)
{
    switch (x->kind) {
    case xd_filled_polygon:
    case xd_unfilled_polygon:
	free(x->u.polyline.pts);
	break;
    case xd_filled_bezier:
    case xd_unfilled_bezier:
	free(x->u.polyline.pts);
	break;
    case xd_polyline:
	free(x->u.polyline.pts);
	break;
    case xd_text:
	free(x->u.text.text);
	break;
    case xd_fill_color:
    case xd_pen_color:
	free(x->u.color);
	break;
    case xd_grad_fill_color:
    case xd_grad_pen_color:
	freeXDotColor (&x->u.grad_color);
	break;
    case xd_font:
	free(x->u.font.name);
	break;
    case xd_style:
	free(x->u.style);
	break;
    case xd_image:
	free(x->u.image.name);
	break;
    default:
	break;
    }
}

void freeXDot (xdot * x)
{
    int i;
    xdot_op *op;
    char *base;
    freefunc_t ff = x->freefunc;

    if (!x) return;
    base = (char *) (x->ops);
    for (i = 0; i < x->cnt; i++) {
	op = (xdot_op *) (base + i * x->sz);
	if (ff) ff (op);
	freeXOpData(op);
    }
    free(base);
    free(x);
}

int statXDot (xdot* x, xdot_stats* sp)
{
    int i;
    xdot_op *op;
    char *base;

    if (!x || !sp) return 1;
    memset(sp, 0, sizeof(xdot_stats));
    sp->cnt = x->cnt;
    base = (char *) (x->ops);
    for (i = 0; i < x->cnt; i++) {
	op = (xdot_op *) (base + i * x->sz);
 	switch (op->kind) {
	case xd_filled_ellipse:
	case xd_unfilled_ellipse:
	    sp->n_ellipse++;
	    break;
	case xd_filled_polygon:
	case xd_unfilled_polygon:
	    sp->n_polygon++;
	    sp->n_polygon_pts += op->u.polygon.cnt;
	    break;
	case xd_filled_bezier:
	case xd_unfilled_bezier:
	    sp->n_bezier++;
	    sp->n_bezier_pts += op->u.bezier.cnt;
	    break;
	case xd_polyline:
	    sp->n_polyline++;
	    sp->n_polyline_pts += op->u.polyline.cnt;
	    break;
	case xd_text:
	    sp->n_text++;
	    break;
	case xd_image:
	    sp->n_image++;
	    break;
	case xd_fill_color:
	case xd_pen_color:
	    sp->n_color++;
	    break;
	case xd_grad_fill_color:
	case xd_grad_pen_color:
	    sp->n_gradcolor++;
	    break;
        case xd_font:
	    sp->n_font++;
	    break;
        case xd_fontchar:
	    sp->n_fontchar++;
	    break;
	case xd_style:
	    sp->n_style++;
	    break;
	default :
	    break;
	}
    }
    
    return 0;
}

xdot_grad_type 
colorType (char* cp)
{
    xdot_grad_type rv;

    switch (*cp) {
    case '[' :
	rv = xd_linear;
	break;
    case '(' :
	rv = xd_radial;
	break;
    default :
	rv = xd_none;
	break;
    }
    return rv;
}



/* radGradient:
 * Parse radial gradient spec
 * Return NULL on failure.
 */
static char*
radGradient (char* cp, xdot_color* clr)
{
    char* s = cp;
    int i;
    double d;
    xdot_color_stop* stops = NULL;

    clr->type = xd_radial;
    s = parseReal(s, &clr->u.ring.x0);
    if(!s){free(stops);return NULL;};
    s = parseReal(s, &clr->u.ring.y0);
    if(!s){free(stops);return NULL;};
    s = parseReal(s, &clr->u.ring.r0);
    if(!s){free(stops);return NULL;};
    s = parseReal(s, &clr->u.ring.x1);
    if(!s){free(stops);return NULL;};
    s = parseReal(s, &clr->u.ring.y1);
    if(!s){free(stops);return NULL;};
    s = parseReal(s, &clr->u.ring.r1);
    if(!s){free(stops);return NULL;};
    s = parseInt(s, &clr->u.ring.n_stops);
    if(!s){free(stops);return NULL;};

    stops = (xdot_color_stop*)calloc((clr->u.ring.n_stops), sizeof(xdot_color_stop));
    for (i = 0; i < clr->u.ring.n_stops; i++) {
	s = parseReal(s, &d);
	if(!s){free(stops);return NULL;};
	stops[i].frac = d;
	s = parseString(s, &stops[i].color);
	if(!s){free(stops);return NULL;};
    }
    clr->u.ring.stops = stops;

    return cp;
}

/* linGradient:
 * Parse linear gradient spec
 * Return NULL on failure.
 */
static char*
linGradient (char* cp, xdot_color* clr)
{
    char* s = cp;
    int i;
    double d;
    xdot_color_stop* stops = NULL;

    clr->type = xd_linear;
    s = parseReal(s, &clr->u.ling.x0);
    if(!s){free(stops);return NULL;};
    s = parseReal(s, &clr->u.ling.y0);
    if(!s){free(stops);return NULL;};
    s = parseReal(s, &clr->u.ling.x1);
    if(!s){free(stops);return NULL;};
    s = parseReal(s, &clr->u.ling.y1);
    if(!s){free(stops);return NULL;};
    s = parseInt(s, &clr->u.ling.n_stops);
    if(!s){free(stops);return NULL;};

    stops = (xdot_color_stop*)calloc((clr->u.ling.n_stops), sizeof(xdot_color_stop));
    for (i = 0; i < clr->u.ling.n_stops; i++) {
	s = parseReal(s, &d);
	if(!s){free(stops);return NULL;};
	stops[i].frac = d;
	s = parseString(s, &stops[i].color);
	if(!s){free(stops);return NULL;};
    }
    clr->u.ling.stops = stops;

    return cp;
}

/* parseXDotColor:
 * Parse xdot color spec: ordinary or gradient
 * The result is stored in clr.
 * Return NULL on failure.
 */
char*
parseXDotColor (char* cp, xdot_color* clr)
{
    char c = *cp;

    switch (c) {
    case '[' :
	return linGradient (cp+1, clr);
	break;
    case '(' :
	return radGradient (cp+1, clr);
	break;
    case '#' :
    case '/' :
	clr->type = xd_none; 
	clr->u.clr = cp;
	return cp;
	break;
    default :
	if (isalnum(c)) {
	    clr->type = xd_none; 
	    clr->u.clr = cp;
	    return cp;
	}
	else
	    return NULL;
    }
}

void freeXDotColor (xdot_color* cp)
{
    int i;

    if (cp->type == xd_linear) {
	for (i = 0; i < cp->u.ling.n_stops; i++) {
	    free (cp->u.ling.stops[i].color);
	}
	free (cp->u.ling.stops);
    }
    else if (cp->type == xd_radial) {
	for (i = 0; i < cp->u.ring.n_stops; i++) {
	    free (cp->u.ring.stops[i].color);
	}
	free (cp->u.ring.stops);
    }
}




    


