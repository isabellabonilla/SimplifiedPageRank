// Author: Isabella Bonilla
#include <iostream>
#include <sstream>
#include <iomanip>
#include "AdjacencyList.h"

using namespace std;

// prints the PageRank of all pages after powerIterations in ascending alphabetical order of webpages and rounding rank to two decimal places
string AdjacencyList::PageRank(int powerIterations){
    stringstream result; // output string
    int numWebpages = graph.size();

    map <string, double> ranks; // map for storing rank values for each webpage

    for(auto& page : graph) { // if powerIterations = 1: all websites' ranks are 1 / (number of unique webpages)
        ranks[page.first->name] = 1.0 / numWebpages;
    }

    for(int i = 1; i < powerIterations; i++) { // If power iterations > 1: see line 25
        map <string, double> newRanks;

        for(auto& page : graph) { // iterates through each webpage key in the graph
            double newRank = 0.0;

            for(auto& fromPage : page.second) { // iterates through each link corresponding to the webpage
                newRank += ranks[fromPage->name] / fromPage->outDegree; // rank of webpage = sum of fromPage rank / fromPage outdegree
            }

            newRanks[page.first->name] = newRank;
        }

        for(auto& page : graph) {
            ranks[page.first->name] = newRanks[page.first->name]; // update new ranks
        }
    }

    // referenced new project 2 breakdown - slide 22
    result << fixed << showpoint;
    result << setprecision(2);

    for(auto& pageRank : ranks) { // store the webpages and their corresponding ranks in result
        result << pageRank.first << ' ' << pageRank.second << "\n";
    }

    cout << result.str();
    return result.str();
}

void AdjacencyList::insertEdge(Webpage* fromPage, Webpage* toPage) {
    // reference: graph 1 lectures - video 7
    graph[toPage].push_back(fromPage); // store toPage and associated fromPage to graph

    fromPage->outDegree++; // increment fromPage's out degree
    toPage->inDegree++; // increment toPage's in degree

    if(graph.find(fromPage) == graph.end()) { // if the fromPage isn't already in the graph, add it
        graph[fromPage] = {};
    }
}

AdjacencyList::Webpage::Webpage(string name) {
    this->name = name;
    this->inDegree = 0;
    this->outDegree = 0;
}
