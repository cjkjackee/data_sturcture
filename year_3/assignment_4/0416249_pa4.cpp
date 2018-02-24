#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <stdlib.h>
#include <limits.h>
using namespace std;

#define max 0xFFFFFFF

vector<map<int,int> > graph;
vector<int> shortest;
vector<int> parent;

int main (int argc, char** argv)
{
    fstream fin, fout;
    int T;
    char c;
    int start, end;
    map<int,int> tmp;

    if (argc != 3)
    {
        cout << "Usage: ./a.out <INPUT> <OUTPUT>" << endl;
        exit(1);
    }

    fin.open(argv[1]);
    fout.open(argv[2],fstream::out);

    fin >> T;
    tmp.clear();
    for (int i=0;i<T;++i)
        graph.push_back(tmp);

    while(fin >> c)
    {
        if (c == '#')
            break;
        
        int index;
        int next;
        int distence;

        fin.putback(c);       
        fin >> index;
        fin >> next;
        fin >> distence;
        
        graph[index-1][next-1] = distence;
    }
    
    while(fin >> start)
    {
        --start;
        fin >> end;
        --end;
        shortest.assign(T,max);
        parent.assign(T,-1);
        shortest[start] = 0;
        for (int x=0;x<T;++x)
        {
            for (int i=0;i<T;++i)
            {
                for (map<int,int>::iterator it=graph[i].begin();it!=graph[i].end();++it)
                {
                    
                    if (it->second + shortest[i] < shortest[it->first])
                    {
                        if (x==T-1)
                        {
                            fout << "Negative cycle" << endl;
                            return 0;
                        }
                        shortest[it->first] = it->second + shortest[i];
                        parent[it->first] = i;
                    }
                }
            }
        }

        if (shortest[end]==max)
            fout << "No path" << endl;
        else 
        {
            int i = parent[end];
            vector<int> stack;

            fout << shortest[end] << " ";
            while (i!=-1)
            {
                stack.push_back(i);
                i = parent[i];
            }
            while(!stack.empty())
            {
                fout << stack.back()+1 << " ";
                stack.pop_back();
            }
            fout << end + 1 << endl;
        }
    }

    return 0;
}