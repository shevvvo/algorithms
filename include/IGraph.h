//
// Created by she on 22.12.2021.
//

#ifndef ALGORITHMS_IGRAPH_H
#define ALGORITHMS_IGRAPH_H

#include <vector>
#include <cassert>
#include <unordered_set>
#include <iostream>

struct IGraph {
public:
    virtual ~IGraph() {}

    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const  = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};



#endif //ALGORITHMS_IGRAPH_H
