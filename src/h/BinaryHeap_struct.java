package h;
import core.*;
import core.annotation.*;

// 6tvdpblndack247qipdqay8gj

public class BinaryHeap_struct {
}

// struct BinaryHeap_struct {
//   int max_len;/* storage allocated for the heap */
//   int len;/*number of elements in the heap so far. <= maxlen */
//   void **heap;
//   int *id_to_pos;/* this array store the position of an item with ID. For ID that was not in use,
// 		    i.e., no in pos_to_id[1:len],
// 		    id_to_pos[id] = -1
// 		  */
//   int *pos_to_id;/* this array stores the ID of item at position pos. 
// 		    pos_to_id[id_to_pos[i]] = i, for i not in the id_stack & i < length(id_stack)+len
// 		    id_to_pos[pos_to_id[i]] = i, 0 <= i < len
// 		 */
//   IntStack id_stack;/* a stack that store IDs that is no longer used, to
// 		       be assigned to newly inserted elements.
// 		       For sanity check, the union of items in
// 		       the id_stack, and that is pos_to_id[1:len],
// 		       should form a set of contiguous numbers 
// 		       {1, 2, ..., len, ...}
// 		    */
//   int (*cmp)(void*item1, void*item2);/* comparison function. Return 1,0,-1
// 				      if item1 >, =, < item2 */
// };