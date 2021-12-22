//
// Created by she on 22.12.2021.
//

#ifndef ALGORITHMS_MATRIXGRAPH_H
#define ALGORITHMS_MATRIXGRAPH_H

#include "IGraph.h"

class MatrixGraph : public IGraph {
public:
    explicit MatrixGraph(int size);
    explicit MatrixGraph(const IGraph &graph);
    ~MatrixGraph() override = default;

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<bool>> adjacencyMatrix;
};

#endif //ALGORITHMS_MATRIXGRAPH_H
