// topological sort

#include <iostream>
#include "graph.h"
#include <queue>

using namespace std;

// topological sort - Part 2
void Graph::topological_sort() {
  queue<Vertex> q;
  int counter = 0;
  while (!q.empty()) {
    q.pop();
  }
  
  for (Vertex v : vertices) {
    if(v.indegree == 0) {
      q.push(v);
    }
  }
  
  while (!q.empty()) {
    Vertex v = q.front();
    q.pop();
    v.top_num = ++counter; // Assign next number
    vertices.at(v.label-1).top_num = counter;

    for (int x : *adj_list.at(v.label)) {
      if( --vertices.at(x-1).indegree == 0 ) {
        q.push(vertices.at(x-1));
      }
    }
  }

  if( counter != vertices.size() ) {
    cout << "Cycle found" << endl;
    exit(2);
  }

}

// find indegree - Part 2
void Graph::compute_indegree() {
  int max = node_list.at(0).label;
  for (Vertex v : node_list) {
    if (v.label > max) max = v.label;
  }
  for (int i = 1; i <= max; ++i) {
    vertices.push_back(Vertex(i,0));
  }

  for (int i = 1; i < adj_list.size(); i++) {
    std::list<int>::iterator itl;
    for (itl = adj_list.at(i)->begin(); itl != adj_list.at(i)->end(); ++itl) {
      vertices.at(*itl-1).indegree++;
    }
  }

}

// print topological sort - Part 2
void Graph::print_top_sort() {
  cout << "Topological sort: " << endl;
  for (int i = 1; i <= vertices.size(); i++) {
    for (Vertex v : vertices) {
      if (v.top_num == i) cout << v.label << " ";
    }
  }
}

