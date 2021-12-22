//
// Created by she on 22.12.2021.
//

#include "SetGraph.h"

SetGraph::SetGraph(int size) : hastTable(size) {}

void SetGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < hastTable.size());
    assert(0 <= to && to < hastTable.size());
    hastTable[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return (int)hastTable.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < hastTable.size());
    std::vector<int> next;
    for (int i = 0; i < hastTable[vertex].size(); ++i) {
        auto it = hastTable[vertex].find(i);
        if (it != hastTable[vertex].end()) {
            next.push_back(*it);
        }
    }
    return next;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < hastTable.size());
    std::vector<int> prev;
    for (int i = 0; i < hastTable.size(); ++i) {
        if (hastTable[i].find(vertex) != hastTable[i].end()) {
            prev.push_back(i);
        }
    }
    return prev;
}

SetGraph::SetGraph(const IGraph &graph) : hastTable(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        auto next = graph.GetNextVertices(i);
        for (int j : next) {
            hastTable[i].insert(j);
        }
    }
}