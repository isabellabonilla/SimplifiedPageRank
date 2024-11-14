// Author: Isabella Bonilla
#include <iostream>
#include "AdjacencyList.h"

using namespace std;

int main() {
    int no_of_lines, power_iterations;
    string from, to;
    cin >> no_of_lines; // read first number of lines
    cin >> power_iterations; // read second number of power iterations

    AdjacencyList graph; // create graph object
    map<string, AdjacencyList::Webpage*> webpages; // keeps track of all webpages

    for (int i = 0; i < no_of_lines; i++) {
        cin >> from;
        cin >> to;

        if(webpages.find(from) == webpages.end()) { // if new webpage, add to map and create Webpage object
            AdjacencyList::Webpage* fromPage = new AdjacencyList::Webpage(from);
            webpages[from] = fromPage;
        }
        if(webpages.find(to) == webpages.end()) { // if new webpage, add to map and create Webpage object
            AdjacencyList::Webpage* toPage = new AdjacencyList::Webpage(to);
            webpages[to] = toPage;
        }

        graph.insertEdge(webpages[from], webpages[to]); // insert edge
    }

    graph.PageRank(power_iterations); // print PageRank

    for(auto& page : webpages) { // delete all Webpage objects
        delete page.second;
    }
}
