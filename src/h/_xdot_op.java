package h;
import core.*;
import core.annotation.*;

// 8n228pyy8v750bhs0ubxnx0l9

public class _xdot_op {
}

// struct _xdot_op {
//     xdot_kind kind;
//     union {
//       xdot_rect ellipse;       /* xd_filled_ellipse, xd_unfilled_ellipse */
//       xdot_polyline polygon;   /* xd_filled_polygon, xd_unfilled_polygon */
//       xdot_polyline polyline;  /* xd_polyline */
//       xdot_polyline bezier;    /* xd_filled_bezier,  xd_unfilled_bezier */
//       xdot_text text;          /* xd_text */
//       xdot_image image;        /* xd_image */
//       char* color;             /* xd_fill_color, xd_pen_color */
//       xdot_color grad_color;   /* xd_grad_fill_color, xd_grad_pen_color */
//       xdot_font font;          /* xd_font */
//       char* style;             /* xd_style */
//       unsigned int fontchar;   /* xd_fontchar */
//     } u;
//     drawfunc_t drawfunc;
// };