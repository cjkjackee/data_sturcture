#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//************************** node **************************
class node
{
	public:
		node();
		~node();
	private:
		int weight;
		node *parent;

	friend class graph;
};

node::~node(){}
node::node ()
{
	weight = 0;
	parent = this;
}

//*********************** graph **************************
class graph
{
	public:
		graph();
		~graph();
		void insert(int);
		void Union (node* ,node*);
		node* find (int);
	private:
		map<int,node*> node_map;

	friend class node;
	friend class list;
};

graph::graph(){}
graph::~graph(){}
void graph::insert(int num)
{
	if (node_map[num]==NULL)
		node_map[num] = new node();
	else 
		return;
}

void graph::Union (node *num1, node *num2)
{
	num2->parent = num1;
}

node* graph::find (int num)
{
	node *now = node_map[num];
	while(now->parent!=now)
		now = now->parent;
	return now;
}

//*********************** link *************************
class link
{
	public:
		link();
		~link();
		link(int,int,int);
	private:
		int num1;
		int num2;
		int weight;

	friend class list;
};

link::link(){}
link::~link(){}
link::link(int now, int next, int w)
{
	num1 = now;
	num2 = next;
	weight = w;
}


//*********************************** list **********************************
class list
{
	public:
		list();
		~list();
		void insert(int,int,int);
		void print ();
		void sort();
		static bool sort_func(link*,link*);
		void min_spanning();
	private:
		vector<link*> edge; 
		vector<link*> ans;
		class graph graph;
};

list::list(){}
list::~list(){}

void list::insert(int num1, int num2, int w)
{
	edge.push_back(new link(num1,num2,w));
	graph.insert(num1);
	graph.insert(num2);
}

void list::print()
{
	int total=0;
	for (int i=0;i<ans.size();++i)
	{
		cout << ans[i]->num1 << " " << ans[i]->num2 << " " << ans[i]->weight << endl;
		total += ans[i]->weight;
	}
	cout << total << endl;
}

bool list::sort_func (link *l1, link *l2)
{
	return (l1->weight < l2->weight);
}

void list::sort ()
{
	std::sort(edge.begin(),edge.end(),list::sort_func);
}

void list::min_spanning()
{
	node *num1;
	node *num2;

	for (int i=0;i<edge.size();++i)
	{
		num1 = graph.find(edge[i]->num1);
		num2 = graph.find(edge[i]->num2);

		if (num1!=num2)
		{
			ans.push_back(edge[i]);
			graph.Union(num1,num2);
		}
	}
}