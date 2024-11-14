// Author: Isabella Bonilla
#pragma once
#include <string>
#include <map>
#include <vector>
using namespace std;

class AdjacencyList {
public:
    struct Webpage {
        Webpage(string name);
        string name;
        int inDegree;
        int outDegree;
    };

    string PageRank(int powerIterations);
    void insertEdge(Webpage* from, Webpage* to);

private:
    map <Webpage*, vector<Webpage*>> graph; // adjacency list for graph
};

