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

# forest
-	多顆tree
-	實做是以array的方式,arr[n] //n==node,arr[n]==parent
-	如果有n個Union，m個Find：find要花m^2

# hash function
overflow handling
-	一個hash table 上有兩個h（k）指到同一個slot，overflow
-	open addressing：
	+	linear probing：當h（k）不是空的，（h(k)+i）%2 找到下一個空的位置，如果不是空的，再多一次
	+	quadratic probing：當h（k）不是空的，（h(k)+(i^2)）%2找下一個空的位置，如果不是空的，再多一次

# sorting
-	interpolation search： comparing k with a[i]
- insertion sort：
	+	最好的情況：多加一個號碼，他是最大的，結束。
	+	最壞的情況：加多一個號碼，他是最小的，要把所有東西往後移一格，再insert，花費n //n=多少element
-	binary insertion sort
	+	以binary search 來找
-	linked insertion sort
	+	以link list 來做，只要找到位置，直接insert，不用移動其他的

# quick sort
-	低期望值
-	實做：
	+	一個array，以其中一個值當pivot
	+	當*it<pivot，it++
	+	當*it>pivot, end_it<pivot ,it<=end_it, end_it<=it;
	+	做完之後pivot放去中間
	+	再做<pivot的，和>pivot的
