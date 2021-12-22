//
// Created by she on 22.12.2021.
//

#ifndef ALGORITHMS_ARCGRAPH_H
#define ALGORITHMS_ARCGRAPH_H

#include "IGraph.h"

class ArcGraph : public IGraph {
public:
    explicit ArcGraph(int size);
    explicit ArcGraph(const IGraph &graph);
    ~ArcGraph() override = default;

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::pair<int, int>> pairs;
    int count;
};

#endif //ALGORITHMS_ARCGRAPH_H
