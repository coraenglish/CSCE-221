#include "graph.h"
#include <iostream>

using namespace std;

// to be implemented

Graph::~Graph() {
    for (list<int>* list : adj_list) {
        delete list;
    }
}

// build a graph
void Graph::buildGraph(ifstream &input) {
    
    // read in all ints from file including -1 in order to know when line is over
    int i;
    input >> i;
    while (!input.eof()) {
        node_list.push_back(Vertex(i));
        input >> i;
    }

    int count = 0;
    adj_list.push_back(new list<int>);  // add a dummy list in order for index to match in vector to match vertex label
    while (count < node_list.size()) {
        int idx = node_list.at(count).label;
        adj_list.push_back(new list<int>);
        count++;
        if (count == node_list.size()) break;
        while (true) {
            if (node_list.at(count).label == -1) {
                count++;
                break;  // exit loop when end of line is reached, else pushback contents into list
            }
            int curr_label = node_list.at(count).label;
            adj_list.at(idx)->push_back(curr_label);
            count++;

        }
    }
}

// display the graph
void Graph::displayGraph() {
    cout << "Adjacency list: " << endl;
    for (int i = 1; i < adj_list.size(); i++) { // adj list will have one extra element bc of the dummy list at index 0
        std::list<int>::iterator it;
        cout << i << " : ";    
        for (it = adj_list.at(i)->begin(); it != adj_list.at(i)->end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << endl;
}


