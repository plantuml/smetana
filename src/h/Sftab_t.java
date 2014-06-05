package h;
import core.*;
import core.annotation.*;

// 3i4iq9l3tefctu6xq8kqeu82l

public class Sftab_t {
}

// typedef struct _sftab_ {
// 	_ast_fltmax_t sf_pos10[6];	/* positive powers of 10        */
// 	_ast_fltmax_t sf_neg10[6];	/* negative powers of 10        */
// 	unsigned char sf_dec[200];	/* ascii reps of values < 100   */
// 	char *sf_digits;	/* digits for general bases     */
// 	int (*sf_cvinitf) (void);	/* initialization function      */
// 	int sf_cvinit;		/* initialization state         */
// 	Fmtpos_t *(*sf_fmtposf)
// 	    _ARG_((Sfio_t *, const char *, va_list, int));
// 	char *(*sf_fmtintf) _ARG_((const char *, int *));
// 	unsigned char sf_cv36[((unsigned char)(~0)) + 1];	/* conversion for base [2-36]   */
// 	unsigned char sf_cv64[((unsigned char)(~0)) + 1];	/* conversion for base [37-64]  */
// 	unsigned char sf_type[((unsigned char)(~0)) + 1];	/* conversion formats&types     */
//     } Sftab_t;