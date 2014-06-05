package h;
import core.*;
import core.annotation.*;

// auqnjg0ue50hqpz0i9kv13uvs

public class PriorityQueue_struct {
}

// struct PriorityQueue_struct {
//   /* a simple priority queue structure: entries are all integers, gains are all integers in [0, gainmax], total n elements */
//   int count;/* how many entries are in?*/
// 
//   /* max index value of an entry */
//   int n;
// 
//   /* only ngain buckets are allowed */
//   int ngain;
// 
//   /* current highest gain */
//   int gain_max;
// 
//   /* the ngain buckets. Each bucket i holds all entries with gain = i.*/
//   DoubleLinkedList *buckets;
// 
//   /* a mapping which maps an entry's index to an element in a DoubleLinkedList */
//   DoubleLinkedList *where;
// 
//   /* the gain of entry i is gain[i] */
//   int *gain;
// };