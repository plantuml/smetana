package h;
import core.*;
import core.annotation.*;

// 7uiwhqnseej0oaqiv35vi47k1

@TranslatedBy("plantuml") 
public class _dtdisc_s extends Structure {
	public OFFSET	key;	/* where the key begins in an object	*/
	public size_t		size;	/* key size and type			*/
	public OFFSET	link;	/* offset to Dtlink_t field		*/
	public Dtmake_f	makef;	/* object constructor			*/
	public Dtfree_f	freef;	/* object destructor			*/
	public Dtcompar_f	comparf;/* to compare two objects		*/
	public Dthash_f	hashf;	/* to compute hash value of an object	*/
	public Dtmemory_f	memoryf;/* to allocate/free memory		*/
	public Dtevent_f	eventf;	/* to process events			*/
	
	public _dtdisc_s() {
	}
	public _dtdisc_s(Object parent) {
		super(parent);
	}
	public void reset() {
		key = null;
		size = null;
		link = null;
		makef = null;
		freef = null;
		comparf = null;
		hashf = null;
		memoryf = null;
		eventf = null;
	}
}

// struct _dtdisc_s
// {	int		key;	/* where the key begins in an object	*/
// 	int		size;	/* key size and type			*/
// 	int		link;	/* offset to Dtlink_t field		*/
// 	Dtmake_f	makef;	/* object constructor			*/
// 	Dtfree_f	freef;	/* object destructor			*/
// 	Dtcompar_f	comparf;/* to compare two objects		*/
// 	Dthash_f	hashf;	/* to compute hash value of an object	*/
// 	Dtmemory_f	memoryf;/* to allocate/free memory		*/
// 	Dtevent_f	eventf;	/* to process events			*/
// };