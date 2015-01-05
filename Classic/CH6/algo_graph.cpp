#include "algo_graph.h"
#include <time.h>
#include <stdlib.h>


directed_graph::directed_graph(){
	numV = 0;
	numE = 0;
}

void directed_graph::addVertex(const string& name){
	vertex* v = new vertex(name);
	adjVec.push_back(v);
	numE++;
}

bool directed_graph::addEdge(int from, int to, int cost){
	if(from<numE&&from>=0&&to<numE&&from>=0){
		vertex* fromNode = adjVec[from];
		for(auto p: fromNode->neighbors){
			if(p.first==to){
				p.second = cost;
				return true;
			}
		}
		pair<int, int> p;
		p = make_pair(to,cost);
		fromNode->neighbors.push_back(p);
		return true;
	} else {
		cout<<"the vertex id does not exit, please add it first"<<endl;
		return false;
	}
}


void directed_graph::print(){
	for(auto i: adjVec){
		for(auto j: i->neighbors){
			cout<<i->name<<"->"<<adjVec[j.first]->name<<": cost->"<<j.second<<endl;
		}
	}
}
 

int main(int argc, char const *argv[])
{
	directed_graph* graph = new directed_graph();

	int numNode = 10;
	int numEdge = 20;
	int i = 0;
	while(i<numNode){
		graph->addVertex(to_string(i));
		i++;
	}

	i = 0;

	srand(time(NULL));

	while(i<numEdge){
		int cost = rand()%10+1;
		int from = rand()%10;
		int to = rand()%10;
		if(from==to)
			continue;
		else{
			graph->addEdge(from,to,cost);
			i++;
		}
	}

	graph->print();


	return 0;
}
