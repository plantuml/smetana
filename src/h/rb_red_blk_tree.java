package h;
import core.*;
import core.annotation.*;

// bpl55k01fgzu59sv4vqwfpbcg

public class rb_red_blk_tree {
}

// typedef struct rb_red_blk_tree {
//   int (*Compare)(const void* a, const void* b); 
//   void (*DestroyKey)(void* a);
//   void (*DestroyInfo)(void* a);
//   void (*PrintKey)(const void* a);
//   void (*PrintInfo)(void* a);
//   /*  A sentinel is used for root and for nil.  These sentinels are */
//   /*  created when RBTreeCreate is caled.  root->left should always */
//   /*  point to the node which is the root of the tree.  nil points to a */
//   /*  node which should always be black but has aribtrary children and */
//   /*  parent and no key or info.  The point of using these sentinels is so */
//   /*  that the root and nil nodes do not require special cases in the code */
//   rb_red_blk_node* root;             
//   rb_red_blk_node* nil;              
// } rb_red_blk_tree;