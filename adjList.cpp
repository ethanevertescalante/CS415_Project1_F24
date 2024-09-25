//
// Created by Ethan on 9/25/2024.
//

#include "adjList.hpp"

int adjList::addVertex(const Vertex& vertex) {
    vertices.push_back(vertex);
    adjList.push_back(std::vector<int>());
}

void adjList::addEdge(int v1, int v2) {
    //you have to add both vertices to both adjLists
    if( v1 < adjList.size() && v2 < adjList.size()){
        adjList[v1].push_back(v2);
    }else{
        std::cout << "OOB indicies" << std::endl;
    }
}

void adjList::printGraph() const {
    for(int i = 0; i < vertices.size(); i++){
        std::cout << i << " (" << vertices[i].word << ")";
        for(int neighbor : adjList[i]){
            std::cout << neighbor << " (" << vertices[neighbor].word << ") ";
        }
        std::cout << std::endl;
    }
}

