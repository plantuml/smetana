package h;
import core.*;
import core.annotation.*;

// 2bekj2zvyfhxfmaqcq9g4iguv

public class Switch_t {
}

// typedef struct Switch_s			/* switch parse state		*/
// {
// 	struct Switch_s*prev;		/* previous switch state	*/
// 	Exnode_t*	firstcase;	/* first case block		*/
// 	Exnode_t*	lastcase;	/* last case block		*/
// 	Exnode_t*	defcase;	/* default case block		*/
// 	Extype_t**	base;		/* label base pointer		*/
// 	Extype_t**	cur;		/* current label pointer	*/
// 	Extype_t**	last;		/* last label pointer		*/
// 	int		def;		/* default label hit		*/
// 	int		type;		/* switch test type		*/
// } Switch_t;