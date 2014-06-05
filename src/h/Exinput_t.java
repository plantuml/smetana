package h;
import core.*;
import core.annotation.*;

// 14id6z10en9ycx0xswln7g7l3

public class Exinput_t {
}

// typedef struct Exinput_s		/* input stack			*/
// {
// 	struct Exinput_s*next;		/* next in stack		*/
// 	int		close;		/* close fp on pop		*/
// 	char*		file;		/* previous file		*/
// 	Sfio_t*		fp;		/* expression file pointer	*/
// 	int		line;		/* previous line		*/
// 	int		nesting;	/* expression nesting level	*/
// 	int		peek;		/* 1 char peek			*/
// 	int		unit;		/* first frame in parse unit	*/
// 	char*		pushback;	/* pushback buffer		*/
// 	char*		bp;		/* expression string base	*/
// 	char*		pp;		/* pushback pointer		*/
// 	char*		sp;		/* expression string pointer	*/
// } Exinput_t;