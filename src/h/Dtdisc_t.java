package h;
import core.*;
import core.annotation.*;

// 3n3lg4dzicyo9pzjj6bv0krf5

@TranslatedBy("plantuml") 
public class Dtdisc_t extends _dtdisc_s {
	public Dtdisc_t(OFFSET key, size_t size, OFFSET link, Dtmake_f makef, Dtfree_f freef, Dtcompar_f comparf, Dthash_f hashf,
			Dtmemory_f memoryf, Dtevent_f eventf) {
		this.key = key;
		this.size = size;
		this.link = link;
		this.makef = makef;
		this.freef = freef;
		this.comparf = comparf;
		this.hashf = hashf;
		this.memoryf = memoryf;
		this.eventf = eventf;
	}
	
	public Dtdisc_t(OFFSET key, size_t size, OFFSET link, Dtmake_f makef, Dtfree_f freef, Dtcompar_f comparf, Dthash_f hashf) {
		this.key = key;
		this.size = size;
		this.link = link;
		this.makef = makef;
		this.freef = freef;
		this.comparf = comparf;
		this.hashf = hashf;
	}
	
	public Dtdisc_t() {
	}
	public Dtdisc_t(Object parent) {
		super(parent);
	}
}

// typedef struct _dtdisc_s	Dtdisc_t;