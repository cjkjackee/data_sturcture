 data_sturcture

link list
+	circular list
	*	current->link==first
	*	用一個head node 來表示head

struct - default public
class - default private

equivalence classes
+	convex
	*	在polygon中任意兩點都被polygon包圍
+	simple
	*	polygon的邊界不交錯

# tree
+	以G表示graph
+	tree是graph的特例
+	degree：有多少subtree
+	degree of tree ：max（degree in tree）
+	height: determine search cost

binary tree  
+	maximum number of nodes
	*	2^(i-1), i=level
	*	2^(k-1), k=depth
	*	只要是height是log function 就是balance

threaded binary tree
+	https://en.wikipedia.org/wiki/Threaded_binary_tree
+	insertion cost
	-	if (next node == null), cost: delta(1)
	-	else, cost: O(h)
# Heap
類似tree，但是以array實做，不用考慮pointer
