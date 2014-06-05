package h;
import core.*;
import core.annotation.*;

// 9qqo4pt0x97lv7fp9yneflgkr

public class textlabel_t {
}

// typedef struct textlabel_t {
// 	char *text, *fontname, *fontcolor;
// 	int charset;
// 	double fontsize;
// 	pointf dimen; /* the diagonal size of the label (estimated by layout) */
// 	pointf space; /* the diagonal size of the space for the label */
// 		      /*   the rendered label is aligned in this box */
// 		      /*   space does not include pad or margin */
// 	pointf pos;   /* the center of the space for the label */
// 	union {
// 	    struct {
// 		textspan_t *span;
// 		short nspans;
// 	    } txt;
// 	    htmllabel_t *html;
// 	} u;
// 	char valign;  /* 't' 'c' 'b' */
// 	boolean set;  /* true if position is set */
// 	boolean html; /* true if html label */
//     } textlabel_t;