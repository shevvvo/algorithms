//
// Created by she on 22.12.2021.
//

#ifndef ALGORITHMS_SETGRAPH_H
#define ALGORITHMS_SETGRAPH_H

#include "IGraph.h"

class SetGraph : public IGraph {
public:
    explicit SetGraph(int size);
    explicit SetGraph(const IGraph &graph);
    ~SetGraph() override = default;

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::unordered_set<int>> hastTable;
};

#endif //ALGORITHMS_SETGRAPH_H
