#ifndef ALGO_MAP
#define ALGO_MAP

#include <iostream>
#include <vector>
#include <string>
#include <utility> 
#include <unordered_map>
using namespace std;

struct vertex{
	// id + cost
	vector<pair<int,int>> neighbors; 
	string name;
	vertex(string s)
	{
		name=s;
	}
};

class directed_graph
{
public:
	directed_graph();
	void addVertex(const string&);
	bool addEdge(int, int, int);
	void print();

private:
	int numV;
	int numE;
	vector<vertex*> adjVec;
};


#endif