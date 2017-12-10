#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

fstream fin, fout;

class node
{
    friend class tree;
public:
    node(){};
    ~node(){};
    node(unsigned int,char,int);
    void operator= (node);
private:
    unsigned int id;
    bool dir;
    int x;
    int count;
    node* left;
    node* right;
};

node::node(unsigned int i, char c, int z)
{
    id = i;
    if (c=='L')
        dir = 1;
    else
        dir = 0;
    x = z;
    count = z;
    left = NULL;
    right = NULL;
}

void node::operator= (node n2)
{
    this->id = n2.id;
    this->dir = n2.dir;
    this->x = n2.x;
    this->count = n2.count;
    return;
}

class tree
{
public:
    tree(){root = NULL;};
    ~tree();
    void add(unsigned int,char,int);
    bool deleteR(unsigned int);
    bool deleteL(unsigned int);
    void drop(unsigned int);
    void show();
private:
    node* root;
    void del(node*);
    void traversal(node*);
};

tree::~tree()
{
    node* now;
    vector<node*> store;

    if(root!=NULL)
    {
        now = root;
        store.push_back(now);
        for (unsigned int i=0;i<store.size();++i)
        {
            now = store[i];
            if (now->right)
                store.push_back(now->right);
            if (now->left)
                store.push_back(now->left);
        }

        while(!store.empty())
        {
            now = store.back();
            store.pop_back();
            delete(now);
        }
    }
}

void tree::del(node* now)
{
    delete now;
    now = NULL;
    return;
}

void tree::traversal(node* now)
{
    if(now==NULL)
        return;
    tree::traversal(now->left);
    cout << now->id << " ";
    cout << now->dir << " ";
    cout << now->x << endl;
    tree::traversal(now->right);
    return;
}

void tree::add(unsigned int i, char c, int z)
{
    node* now;

    if (root==NULL)
    {
        root = new node(i,c,z);
        return;
    }

    now = root;
    while(1)
    {
        if (now->id == i)
        {
            if (c=='L')
                now->dir = true;
            else
                now->dir = false;
            now->x = z;
            break;
        }
        if (i < now->id)
        {
            if (now->left==NULL)
                now->left = new node(i,c,z);
            now = now->left;
        }
        if (i > now->id)
        {
            if (now->right==NULL)
                now->right = new node(i,c,z);
            now = now->right;
        }
    }

    return;
}

bool tree::deleteR (unsigned int i)
{
    node* now = root;
    node* pre = now;
    bool dirL = true;
    
    while(1)
    {
        if (now == NULL)
            return false;
        if (now->id == i)
        {
            if (now->right!=NULL)
            {
                node* tmp = now;
                pre = now;
                dirL = false;
                now = now->right;
                while(now->left)
                {
                    pre = now;
                    now = now->left;
                    dirL = true;
                }
                *tmp = *now;
            }
            else
            {
                if (dirL)
                    pre->left = now->left;
                else   
                    pre->right = now->left;
                del(now);
                return true;
            }
            break;
        }
        
        
        pre = now;
        if (i < now->id) 
        {
            dirL = true;
            now = now->left;
        }
        else if (i > now->id)
        {
            dirL = false;
            now = now->right;
        }
    }

    tree::del(now);
    if (dirL)
        pre->left = NULL;
    else
        pre->right = NULL;
    return true;
}

bool tree::deleteL(unsigned int i)
{
    node* now = root;
    node* pre = now;
    bool dirL = true;

    if (root==NULL)
        return false;
    
    while(1)
    {
        if (now == NULL)
            return false;
        if (now->id == i)
        {
            if (now->left!=NULL)
            {
                node* tmp = now;
                pre = now;
                now = now->left;
                dirL = true;
                while(now->right)
                {
                    pre = now;
                    now = now->right;
                    dirL = false;
                }
                *tmp = *now; 
            }
            else
            {
                if (dirL)
                    pre->left = now->right;
                else
                    pre->right = now->right;
                del(now);
                return true;
            }
            break;
        }

        pre = now;
        if (i < now->id)
        {
            now = now->left;
            dirL = true;
        }
        else if (i > now->id)
        {
            now = now->right;
            dirL = false;
        }
    }
    
    tree::del(now);
    if (dirL)
        pre->left = NULL;
    else 
        pre->right = NULL;
    return true;
}

void tree::drop (unsigned int n)
{
    bool dir;
    node* now;

    if (root==NULL)
    {
        fout << "Tree is empty." << endl;
        return ;
    }
    
    for (unsigned int i=1;i<=n;++i)
    {
        now = root;
        while(1)
        {
            if (now==NULL)
                break;
            dir = now->dir;
            if ((now->x))
            {
                --now->count;
                if(now->count==0)
                {
                    now->dir = !now->dir;
                    now->count = now->x; 
                }
            }
            if (i==n)
            {
                fout << now->id << " ";
            }
            if(dir)
                now = now->left;
            else
                now = now->right;
        }
    }
    fout << endl;
    return;
}

void tree::show()
{
    tree::traversal(root);
    return;
}

int main (int argc, char** argv)
{
    string s;
    tree bst;

    fin.open(argv[1],fstream::in);
    fout.open(argv[2],fstream::out);
    while(fin >> s)
    {
        if (s=="add")
        {
            int i, x;
            char c;
            fin >> i;
            fin >> c;
            fin >> x;
            bst.add(i,c,x);
        }
        else if (s=="deleteR")
        {
            int i;
            fin >> i;
            if(!(bst.deleteR(i)))
                fout << "Deletion failed." << endl;
        }
        else if (s=="deleteL")
        {
            int i;
            fin >> i;
            if(!(bst.deleteL(i)))
                fout << "Deletion failed." << endl;
        }
        else if (s=="drop")
        {
            int i;
            fin >> i;
            bst.drop(i);
        }
        else
            fout << "Error command." << endl;
        //cout << "****************** tree ******************" << endl;
        //bst.show();
        //cout << endl;
        //cout << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
