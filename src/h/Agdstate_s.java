package h;
import core.*;
import core.annotation.*;

// 87jmuxk6h1j3ep0k0s2qz7fsb

@TranslatedBy("plantuml") 
public class Agdstate_s extends Structure {
    public StarVoid mem;
    public StarVoid id;
    /* IO must be initialized and finalized outside Cgraph,
     * and channels (FILES) are passed as void* arguments. */
     
   public void reset() {
       mem = null;
       id = null;
   }
}

// struct Agdstate_s {
//     void *mem;
//     void *id;
//     /* IO must be initialized and finalized outside Cgraph,
//      * and channels (FILES) are passed as void* arguments. */
// };