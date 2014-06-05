package h;
import core.*;
import core.annotation.*;

// 87jgefxbqnrx426i1quuhv9a1

@TranslatedBy("plantuml") 
public class Agrec_s extends Structure {
    public StarChar name;
    public Agrec_t next;
    /* following this would be any programmer-defined data */
	public Agrec_s(Object parentStructure) {
		super(parentStructure);
	}
	public Agrec_s() {
		super();
	}
	
	public void reset() {
	   name = null;
	   next = null;
	}
}

// struct Agrec_s {
//     char *name;
//     Agrec_t *next;
//     /* following this would be any programmer-defined data */
// };