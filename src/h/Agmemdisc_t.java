package h;
import core.*;
import core.annotation.*;

// e2u8m7bby3ay236un81y217mm

@TranslatedBy("plantuml")
public class Agmemdisc_t extends Agmemdisc_s {
	public Agmemdisc_t(Agmemdisc_s.open open, Agmemdisc_s.alloc alloc, Agmemdisc_s.resize resize,
			Agmemdisc_s.free free, Agmemdisc_s.close close) {
		this.open = open;
		this.alloc = alloc;
		this.resize = resize;
		this.free = free;
		this.close = close;
	}
}

// typedef struct Agmemdisc_s Agmemdisc_t;