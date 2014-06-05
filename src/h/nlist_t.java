package h;
import core.*;
import core.annotation.*;

// 21yt3x3ukjw41rbx7gc4w7ebj

@TranslatedBy("plantuml")
public class nlist_t extends Structure {
	public StarStar<node_t> list;
	public int size;
	
	public void reset() {
		list = null;
		size = 0;
	}
}

// typedef struct nlist_t {
// 	node_t **list;
// 	int size;
//     } nlist_t;