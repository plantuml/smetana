package h;
import core.*;
import core.annotation.*;

// 71w78cxaan0929s365t8kncr6

public class port {
}

// typedef struct port {	/* internal edge endpoint specification */
// 	pointf p;		/* aiming point relative to node center */
// 	double theta;		/* slope in radians */
// 	boxf *bp;		/* if not null, points to bbox of 
// 				 * rectangular area that is port target
// 				 */
// 	boolean	defined;        /* if true, edge has port info at this end */
// 	boolean	constrained;    /* if true, constraints such as theta are set */
// 	boolean clip;           /* if true, clip end to node/port shape */
// 	boolean dyna;           /* if true, assign compass point dynamically */
// 	unsigned char order;	/* for mincross */
// 	unsigned char side;	/* if port is on perimeter of node, this
//                                  * contains the bitwise OR of the sides (TOP,
//                                  * BOTTOM, etc.) it is on. 
//                                  */
// 	char *name;		/* port name, if it was explicitly given, otherwise NULL */
//     } port;