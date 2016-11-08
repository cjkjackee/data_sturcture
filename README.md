# data_sturcture

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

binary search tree
-	left subtree < root
-	right subtree > root
-	search by key value：
	1.	對比root的value
	2.	> root 去right subtree; < root 去 left subtree
	3.	重復直到找到要search的值或null
	+	cost： O(h)
-	insertion:
	1.	give a value;
	2.	search the value;
	3.	insert
	+	cost:O(h) + O(1)
-	deletion
	+	當child node爲null或刪除後整個還是binary search tree
	1.	give a value;
	2.	search
	3.	delete
	+	當root被delete，可把right subtree裏最小的號碼放去root，因爲，right subtree中最小的號碼一定大於left subtree，小於right subtree;或可以選擇left subtree中最大的號碼，原理同上。

forest
-	實做是以array的方式,arr[n]:n=node,arr[n]=parent

equivalence classes
-	實做
	+	有n個polygons，m個relation
	+	開個n的array;
	+	根據每個relation，如：0=4，更換arr[0]=4 or arr[4]=0 (把其中一人的root更改)
	+	cost：m×cost（find）

# Heap
類似tree，但是以array實做，不用考慮pointer

max heap
-	以tree來想，root一定大於他的child的tree，跟這個tree相似的heap就是max heap
-	insertion：
	1.	增加在array最後一格
	2.	跟parent比較
	3.	大於parent，兩個交換位置
	4.	重復直到小於parent
-	隨機給一個int array，弄成max heap：
	1.	找出leaf（他們一定是max heap）
	2.	然後找到不是leaf的部分，跟child比較
	3.	找出最大的號碼放在parent。
	4.	重復直到root
-	適用於需要管理權限的東西（根據權限做max heap）

