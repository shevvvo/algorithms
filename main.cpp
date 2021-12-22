#include <iostream>
#include <functional>

#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

void DFS(const IGraph &graph, int vertex, std::vector<bool> &visited, const std::function<void(int)> &func)
{
    visited[vertex] = true;
    func(vertex);

    for (int nextVertex: graph.GetNextVertices(vertex))
    {
        if (!visited[nextVertex])
            DFS(graph, nextVertex, visited, func);
    }
}

void mainDFS(const IGraph &graph, const std::function<void(int)> &func)
{
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); i++)
    {
        if (!visited[i])
            DFS(graph, i, visited, func);
    }
}



int main() {

    ListGraph listGraph(7);
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 5);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(1, 5);
    listGraph.AddEdge(1, 6);
    listGraph.AddEdge(3, 2);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(3, 6);
    listGraph.AddEdge(5, 4);
    listGraph.AddEdge(5, 6);
    listGraph.AddEdge(6, 4);

    mainDFS(listGraph, [](int vertex){ std::cout << vertex << " ";});
    std::cout << std::endl;


    ListGraph listGraph2(listGraph);
    mainDFS(listGraph, [](int vertex){ std::cout << vertex << " ";});
    std::cout << std::endl;

    MatrixGraph matrixGraph(listGraph);
    mainDFS(matrixGraph, [](int vertex){ std::cout << vertex << " ";});
    std::cout << std::endl;

    SetGraph setGraph(listGraph);
    mainDFS(setGraph, [](int vertex){ std::cout << vertex << " ";});
    std::cout << std::endl;

    ArcGraph arcGraph(listGraph);
    mainDFS(arcGraph, [](int vertex){ std::cout << vertex << " ";});
    std::cout << std::endl;



    return 0;
}
