package h;
import core.*;
import core.annotation.*;

// 6erg9dnjb8l3vavlty90aui6v

public class RTree {
}

// struct RTree {
//     Node_t *root;
// 
//     SplitQ_t split;
// 
//     /* balance criterion for node splitting */
//     int MinFill;
// 
//     /* times */
//     long ElapsedTime;
//     float UserTime, SystemTime;
// 
//     int Deleting;
// 
//     /* variables for statistics */
//     int StatFlag;		/* tells if we are counting or not */
//     /* counters affected only when StatFlag set */
//     int InsertCount;
//     int DeleteCount;
//     int ReInsertCount;
//     int InSplitCount;
//     int DeSplitCount;
//     int ElimCount;
//     int EvalCount;
//     int InTouchCount;
//     int DeTouchCount;
//     int SeTouchCount;
//     int CallCount;
//     float SplitMeritSum;
// 
//     /* counters used even when StatFlag not set */
//     int RectCount;
//     int NodeCount;
//     int LeafCount, NonLeafCount;
//     int EntryCount;
//     int SearchCount;
//     int HitCount;
// 
// };