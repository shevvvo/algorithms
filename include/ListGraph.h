//
// Created by she on 22.12.2021.
//

#ifndef ALGORITHMS_LISTGRAPH_H
#define ALGORITHMS_LISTGRAPH_H

#include <vector>

#include "IGraph.h"

class ListGraph : public IGraph {
public:
    explicit ListGraph(int size);
    explicit ListGraph(const IGraph &graph);
    ~ListGraph() override = default;

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> adjacencyLists;
};

#endif //ALGORITHMS_LISTGRAPH_H
