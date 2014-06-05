package h;
import core.*;
import core.annotation.*;

// 366ph8t7jvjosq0zlqhb1g26x

@TranslatedBy("plantuml")
public class Agmemdisc_s extends Structure {		/* memory allocator */
    static public interface open extends FP {
        StarVoid function(Agdisc_t arg1);
    }
    public open open;
    
    static public interface alloc extends FP {
        StarVoid function(StarVoid state, size_t req);
    }
    public alloc alloc;
    
    static public interface resize extends FP {
        StarVoid function(StarVoid state, StarVoid ptr, size_t old, size_t req);
    }
    public resize resize;
    
    static public interface free extends FP {
        void function(StarVoid state, StarVoid ptr);
    }
    public free free;
    
    static public interface close extends FP {
        void function(StarVoid state);
    }
    public close close;
    
}

// struct Agmemdisc_s {		/* memory allocator */
//     void *(*open) (Agdisc_t*);	/* independent of other resources */
//     void *(*alloc) (void *state, size_t req);
//     void *(*resize) (void *state, void *ptr, size_t old, size_t req);
//     void (*free) (void *state, void *ptr);
//     void (*close) (void *state);
// };