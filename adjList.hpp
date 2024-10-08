//
// Created by Ethan on 9/25/2024.
//

#ifndef CS415_PROJECT1_F24_ADJLIST_HPP
#define CS415_PROJECT1_F24_ADJLIST_HPP

#include <iostream>
#include <vector>
#include <queue>
#include "Vertex.hpp"

class adjList {
    private:
        std::vector< std::vector<int> > adjList;


    public:
        std::vector<Vertex> vertices;
        int addVertex(const Vertex& vertex);
        void addEdge(int v1, int v2);
        std::string getVertexWord(int index) const;
        void printGraph() const;

        int size() const;
        bool areWordsAdjacent(const std::string &word1, const std::string &word2);
        void findConnectedComponents();
        bool dfs(int current, int target, std::vector<std::string>& path);
        void resetVertices();
        void findAndPrintLongestLadder();
        bool bfs(int start, int target, std::vector<std::string>& path);
        std::pair<std::vector<int>, std::vector<int>> getDistancesAndParents(int start);
        int dfsCollectComponentWords(int v, std::vector<bool>& visited, std::vector<std::string>& componentWords);
};


#endif //CS415_PROJECT1_F24_ADJLIST_HPP
