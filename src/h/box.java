package h;
import core.*;
import core.annotation.*;

// ecciois6ttiu20v5ds6ne801k

@TranslatedBy("plantuml")
public class box extends Structure {
	final point LL = new point();
	final point UR = new point();
	
	public void reset() {
	    LL.reset();
	    UR.reset();
	}
}


// typedef struct { point LL, UR; } box;