//
// Created by Ethan on 9/25/2024.
//

#ifndef CS415_PROJECT1_F24_ADJLIST_HPP
#define CS415_PROJECT1_F24_ADJLIST_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include "Vertex.hpp"

class adjList {
    private:
        std::vector< std::vector<int> > adjList;
        std::vector<Vertex> vertices;

        //helper functions
        std::pair<std::vector<int>, std::vector<int>> longestLadderHelper(int start);
        int componentHelper(int v, std::vector<std::string>& componentWords);

    public:

        //initialization of adjlist
        int addVertex(const Vertex& vertex);
        void addEdge(int v1, int v2);

        //helpful methods
        std::string getVertexWord(int index) const;
        int size() const;
        void resetVertices();
        bool areWordsAdjacent(const std::string &word1, const std::string &word2);

        //just to check the graph looks okay
        void printGraph() const;

        //main methods for project
        void connectedComponents();
        bool dfs(int start, int target, std::vector<std::string>& path, int& numWords);
        bool bfs(int start, int target, std::vector<std::string>& path, int& numWords);
        void longestLadder();



};


#endif //CS415_PROJECT1_F24_ADJLIST_HPP
