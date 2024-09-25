//
// Created by Ethan on 9/25/2024.
//

#ifndef CS415_PROJECT1_F24_ADJLIST_HPP
#define CS415_PROJECT1_F24_ADJLIST_HPP

#include <iostream>
#include <vector>
#include "Vertex.hpp"

class adjList {
    private:
        std::vector<Vertex> vertices; //vector of vertices
        std::vector< std::vector<int> > adjList;

    public:
        int addVertex(const Vertex& vertex);
        void addEdge(int v1, int v2);
        void printGraph() const;



};


#endif //CS415_PROJECT1_F24_ADJLIST_HPP
