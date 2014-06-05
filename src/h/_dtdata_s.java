package h;
import core.*;
import core.annotation.*;

// 2ncfjhm10yijctdn20pwnelos

@TranslatedBy("plantuml") 
public class _dtdata_s extends Structure {
	public int		type;	/* type of dictionary			*/
	public Dtlink_t	here;	/* finger to last search element	*/
	
	public static class hh extends Union {
		private StarStar<Dtlink_t>	_htab;
		private Dtlink_t	_head;
		public void _htab(StarStar<Dtlink_t> _htab) {
			this._htab = _htab;
		}
		public StarStar<Dtlink_t> _htab() {
			throw new UnsupportedOperationException();
		}
		public Dtlink_t _head() {
			throw new UnsupportedOperationException();
		}
		public void _head(Dtlink_t data) {
			this._head = data;
		}
		public void reset() {
		    _htab = null;
		    _head = null;
		}
	}
	final public hh hh = new hh();
	
	public int		ntab;	/* number of hash slots			*/
	public int		size;	/* number of objects			*/
	public int		loop;	/* number of nested loops		*/
	public int		minp;	/* min path before splay, always even	*/
				/* for hash dt, > 0: fixed table size 	*/
				
	public void reset() {
	    type = 0;
	    here = null;
	    hh.reset();
	    ntab = size = loop = minp = 0;
	}
}

// struct _dtdata_s
// {	int		type;	/* type of dictionary			*/
// 	Dtlink_t*	here;	/* finger to last search element	*/
// 	union
// 	{ Dtlink_t**	_htab;	/* hash table				*/
// 	  Dtlink_t*	_head;	/* linked list				*/
// 	} hh;
// 	int		ntab;	/* number of hash slots			*/
// 	int		size;	/* number of objects			*/
// 	int		loop;	/* number of nested loops		*/
// 	int		minp;	/* min path before splay, always even	*/
// 				/* for hash dt, > 0: fixed table size 	*/
// };