//
// Created by she on 22.12.2021.
//

#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int size) : adjacencyMatrix(size, std::vector<bool>(size, false)) {}

void MatrixGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < adjacencyMatrix.size());
    assert(0 <= to && to < adjacencyMatrix.size());
    adjacencyMatrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return (int)adjacencyMatrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencyMatrix.size());
    std::vector<int> next;
    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        if (adjacencyMatrix[vertex][i]) {
            next.push_back(i);
        }
    }
    return next;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencyMatrix.size());
    std::vector<int> prev;
    for (int i = 0; i < adjacencyMatrix.size(); ++i) {
        if (adjacencyMatrix[i][vertex]) {
            prev.push_back(i);
        }
    }
    return prev;
}

MatrixGraph::MatrixGraph(const IGraph &graph)
    : adjacencyMatrix(graph.VerticesCount(),std::vector<bool>(graph.VerticesCount(),false)) {

    for (int i = 0; i < graph.VerticesCount(); ++i) {
        auto next = graph.GetNextVertices(i);
        for (int j : next) {
            adjacencyMatrix[i][j] = true;
        }
    }

}
