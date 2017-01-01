#include<iostream>
using namespace std;

class node{
public:
	node();
	node(int value);
	~node();
	friend void gothrough(node *p);

private:
	node *left, *right; // the left child and the right child pointer
	int number; // record the node's number
	int is_threadl, is_threadr; //the flag to record whether the pointer is a thread or not

	friend class op_tree_totum;//you could access all valuables in class op_tree_totum
};

//ctor
node::node(){
	left = right = NULL;
	is_threadl = 1;
	is_threadr = 1;
}

//ctor
node::node(int value){
	number = value;
	left = right = NULL;
	is_threadl = 1;
	is_threadr = 1;
}

//dtor
node::~node(){

}

class op_tree_totum{

public:
	op_tree_totum();
	~op_tree_totum();
	void insertion(int s);
	void deletion(int s);
	void inorder_run();
	void reverseorder_run();
	int size();

private:
	node *root, *head, *tail;
	int num;//caculate how many nodes in the totum
};

//ctor
op_tree_totum::op_tree_totum(){
	head = new node();
	tail = new node();
	head->right = tail; //initialize the head node to connect to the tail node
	tail->left = head;
	root = NULL;
	num = 0;
}

//dtor
op_tree_totum::~op_tree_totum(){
	node *p = root;
	if(p!=NULL)	gothrough(p);
	num = 0;
	if (head != NULL)delete head;
	if (tail != NULL)delete tail;
}

void gothrough(node *p){
	if (p->is_threadl==0 && p->left!= NULL) gothrough(p->left);
	if (p->is_threadr==0 && p->right!= NULL) gothrough(p->right);
	delete p;
}

void op_tree_totum::insertion(int s){
	//TODO: fill in the code to do the insertion of the node with number s
	node *new_node = new node(s);
	node *now = root;
	
	if (root==NULL)
	{
		root = new_node;
		root->left = head;
		root->right = tail;
		num += 1;
		return ;
	}
	
	while(1)
	{
		if (s<now->number && now->is_threadl==0)
			now = now->left;
		else if (s>now->number && now->is_threadr==0)
			now = now->right;
		else
			break;
	}

	if (s<now->number)
	{
		new_node->left = now->left;
		new_node->right = now;
		now->left = new_node;
		now->is_threadl = 0;
	}
	else 
	{
		new_node->right = now->right;
		new_node->left = now;
		now->right = new_node;
		now->is_threadr = 0;	
	}
	

	num += 1;
}

void op_tree_totum::deletion(int s){
	//TODO: fill in the code to do the deletion of the node with number s
	node *now = root;
	node *target , *parent;
	bool del = false;
	
	while (1)
	{  
		if (s == now->number)
		{
			target = now;
			del = true;
			break;
		}
		else if (s<now->number && now->is_threadl==0)
			now = now->left;
		else if (s>now->number && now->is_threadr==0)
			now = now->right;
		else
			break;
	}

	if (del)
	{
		while(1)
		{
			if (target->is_threadr==0 || target->is_threadl==0)
			{
				if (target->is_threadl==1)
				{
					now = now->right;
					while(now->is_threadl==0)
						now = now->left;
				}
				else 
				{
					now = target->left;
					while(now->is_threadr==0)
						now = now->right;
				}
				
				target->number = now->number;
				target = now;
			}
			else if (target->is_threadr==1 && target->is_threadl==1)
			{
				if (target->left == head)
				{
					parent = target->right;
					parent->left = head;
					parent->is_threadl = target->is_threadl;
				}
				else if (target->right == tail)
				{
					parent = target->left;
					parent->right = tail;
					parent->is_threadr = target->is_threadr;	
				}
				else 
				{
					if (target->left->right == target)
					{
						parent = target->left;

						parent->right = target->right;
						parent->is_threadr = target->is_threadr;
					}
					else if (target->right->left == target)
					{
						parent = target->right;

						parent->left = target->left;
						parent->is_threadl = target->is_threadl;
					}
				}
				break;
			}
		}

		num -= 1;
		delete target;
		return;
	}
}

void op_tree_totum::inorder_run(){
	//TODO: travel the tree from the head node to the tail node and output the values
	//You should NOT use stack or recurtion
	node *now = root;

	if (root==NULL)
		cout << "there has not tree" << endl;

	while (1)
	{
		if (now == tail)
			break;

		while (now->is_threadl == 0)
			now = now->left;

		while (1)
		{
			if (now == tail)
				break;
			cout << now->number << " ";
			if (now->is_threadr == 0)
			{
				now = now->right;
				break;
			}
			now = now->right;
		}
	}
}

void op_tree_totum::reverseorder_run(){
	//TODO: travel the tree from the tail node to the head node and output the values
	//You should NOT use stack or recurtion

	node *now = root;

	while (1)
	{
		if (now == head)
			break;

		while (now->is_threadr == 0)
			now = now->right;

		while (1)
		{
			if (now == head)
				break;
			cout << now->number << " ";
			if (now->is_threadl == 0)
			{
				now = now->left;
				break;
			}
			now = now->left;
		}
	}
}

int op_tree_totum::size(){
	return num;
}
