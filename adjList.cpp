//
// Created by Ethan on 9/25/2024.
//

#include "adjList.hpp"


bool adjList::areWordsAdjacent(const std::string &word1, const std::string &word2) {
    int differenceCount = 0;
    for (int i = 0; i < word1.length(); ++i) {
        if (word1[i] != word2[i]) {
            ++differenceCount;
            if (differenceCount > 1) {
                return false;
            }
        }
    }
    return differenceCount == 1;
}

std::string adjList::getVertexWord(int index) const {
    return vertices[index].word;  // Return the word at the given vertex index
}


int adjList::addVertex(const Vertex& vertex) {
    vertices.push_back(vertex);
    adjList.push_back(std::vector<int>());
}

void adjList::addEdge(int v1, int v2) {
    adjList[v1].push_back(v2);
    adjList[v2].push_back(v1);
}

void adjList::printGraph() const {
    for(int i = 0; i < adjList.size(); i++){
        std::cout << i << ": ";
        for(int neighbor : adjList[i]){
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

int adjList::size() const{
    return adjList.size();
}

