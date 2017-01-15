#include <iostream>
#include <fstream>
#include "kruskal.h"
using namespace std;

int main (int argv, char* argc[])
{
	fstream input;
	int now, next, weight;
	list list;

	input.open(argc[1]);
	while (input >> now)
	{
		input >> next;
		input >> weight;
		list.insert(now,next,weight);
	}
	input.close();

	list.sort();
	list.min_spanning();
	list.print();

	return 0;
}