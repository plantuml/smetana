package h;
import core.*;
import core.annotation.*;

// 3l1snmqye6yezms5y7jmq9a45

public class Exstate_t {
}

// typedef struct Exstate_s		/* ex global state		*/
// {
// 	Exid_t*		id;		/* current declaration id	*/
// 	int		declare;	/* current declaration type	*/
// 	Exref_t*	lastref;	/* last in . reference list	*/
// 	int		nolabel;	/* <id>':' not a label		*/
// 	Exinput_t	null;		/* null input			*/
// 	Expr_t*		program;	/* current program		*/
// 	Exnode_t*	procedure;	/* current procedure		*/
// 	Exref_t*	refs;		/* . reference list		*/
// 	int		assigned;	/* declaration assignment	*/
// 	int		instatic;	/* static declaration		*/
// 	int		statics;	/* static used			*/
// 	Switch_t*	swstate;	/* switch parse state		*/
// 	char		nullstring[1];	/* ""				*/
// } Exstate_t;