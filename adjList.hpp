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
        std::vector< std::vector<int> > adjList;
        std::vector<Vertex> vertices;

    public:
        int addVertex(const Vertex& vertex);
        void addEdge(int v1, int v2);
        std::string getVertexWord(int index) const;
        void printGraph() const;

        int size() const;
        bool areWordsAdjacent(const std::string &word1, const std::string &word2);

};


#endif //CS415_PROJECT1_F24_ADJLIST_HPP
