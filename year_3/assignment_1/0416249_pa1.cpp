#include <fstream>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <sstream>
using namespace std;

int main(int argc,char* argv[])
{
	ifstream fin;
	ofstream fout;
	fin.open(argv[1]);
	fout.open(argv[2]);

	//start your program here
	vector<deque<string> > stack;
	queue<deque<string> > queue;
 	deque<string> deque1;
	deque<string> deque2;
	string str;
	char c = ' ';
	int use = 0;
	bool top = true;

	fin >> c;
	while(c!=35)
	{
		fin.putback(c);
		getline(fin,str);
		stringstream ss;
		ss << str;
		while(ss>>str)
			deque1.push_back(str);
		stack.push_back(deque1);
		deque1.clear();
		fin >> c;
	}

	while(stack.size()!=1)
	{
		fin >> use;
		use = stack.size() - use;
		deque1 = stack[use];
		fin >> use;
		use = stack.size() - use;
		deque2 = stack[use];

		while(!stack.empty())
		{
			deque<string> tmp = stack.back();
			stack.pop_back();
			if (tmp!=deque1 && tmp!=deque2)
				queue.push(tmp);
		}

		top = true;
		while(!deque2.empty())
		{
			string str1 = deque1.back();
			string str2 = deque2.back();
			deque2.pop_back();

			if (str2[0]==str1[0] || str2[1]==str1[1])
			{
				deque1.push_back(str2);
				top = true;
			}
			else
			{
				deque1.push_front(str2);
				top = false;
			}
		}

		if (!top)
		{
			while(!queue.empty())
			{
				stack.push_back(queue.front());
				queue.pop();
			}
			stack.push_back(deque1);
		}
		else
		{
			stack.push_back(deque1);
			while(!queue.empty())
			{
				stack.push_back(queue.front());
				queue.pop();
			}
		}
	}

	fout << stack[0].back();
	stack[0].pop_back();
	while(!stack[0].empty())
	{
		fout << " " << stack[0].back();
		stack[0].pop_back();
	}

	fin.close();
	fout.close();
	return 0;
}
