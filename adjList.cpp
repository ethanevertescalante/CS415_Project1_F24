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
        std::cout << i << " (" << vertices[i].word << ") " << ": ";
        for(int neighbor : adjList[i]){
            std::cout << neighbor << " " <<  "("<< vertices[neighbor].word << ") ";
        }
        std::cout << std::endl;
    }
}

int adjList::size() const{
    return adjList.size();
}

void adjList:: resetVertices() {
    for (auto &vertex : vertices) {
        vertex.hadVisited = false;
        vertex.onPath = false;
    }
}


void adjList::printDFSPath() {
    std::cout << "DFS Path: ";
    for (int i = 0; i < vertices.size(); ++i) {
        if (vertices[i].onPath) {  // Check if the vertex is on the path
            std::cout << vertices[i].word << " ";  // Print the word
        }
    }
    std::cout << std::endl;
}



bool adjList::dfs(int current, int target, std::vector<std::string>& path) {
    //assuming that current and target are NOT the same

    path.push_back(vertices[current].word);

    vertices[current].hadVisited = true;
    vertices[current].onPath = true;

    for (int neighbor : adjList[current]) {
        if (!vertices[neighbor].hadVisited) {


            if (neighbor == target) {
                vertices[neighbor].onPath = true;  // Mark the target on the path
                return true;  // Path found, return true
            }

            // Recursive DFS call for unvisited neighbors
            if (!vertices[neighbor].hadVisited) {
                if (dfs(neighbor, target, path)) {
                    return true;  // Return true if a path is found
                }
            }
        }
    }

    vertices[current].onPath = false;
    path.pop_back();
    return false;
}

int adjList::findLongestShortestLadder() {
    int maxLadderLength = 0;

    for (int i = 0; i < vertices.size(); ++i) {
        for (int j = i + 1; j < vertices.size(); ++j) {
            std::vector<int> path = bfs(i, j);
            if (!path.empty()) {
                maxLadderLength = std::max(maxLadderLength, (int)path.size());
            }
        }
    }

    return maxLadderLength - 1;  // Subtract 1 because ladder length is path size - 1
}


std::vector<int> adjList::bfs(int start, int target) {
    resetVertices();  // Ensure the vertices are reset before BFS
    std::queue<std::vector<int>> q;

    q.push({start});
    vertices[start].hadVisited = true;

    while (!q.empty()) {
        std::vector<int> path = q.front();
        q.pop();

        int last = path.back();

        if (last == target) return path;    // Return path if we reach the target

        for (int neighbor : adjList[last]) {
            if (!vertices[neighbor].hadVisited) {
                vertices[neighbor].hadVisited = true;
                std::vector<int> newPath = path;
                newPath.push_back(neighbor);  // Extend the path
                q.push(newPath);
            }
        }
    }

    return {}; // Return empty path if no path found
}







// DFS utility to explore a component and set flags
int adjList::dfsCollectComponentWords(int v, std::vector<bool>& visited, std::vector<std::string>& componentWords) {
    visited[v] = true; // Mark the current vertex as visited
    componentWords.push_back(vertices[v].word); // Add the word of this vertex to the component

    // Explore all the neighbors of the current vertex
    for (int neighbor : adjList[v]) {
        if (!visited[neighbor]) {
            dfsCollectComponentWords(neighbor, visited, componentWords); // Recursively visit neighbors
        }
    }

}

// Function to find and print connected components
void adjList::findConnectedComponents() {
    std::vector<bool> visited(vertices.size(), false); // Track visited vertices
    int numComponents = 0; // Counter for the number of connected components

    // Iterate over all vertices
    for (int i = 0; i < vertices.size(); ++i) {
        if (!visited[i]) {
            ++numComponents; // Increment the number of connected components
            std::vector<std::string> componentWords; // Store the words of this component

            // Explore the component and collect its words
            dfsCollectComponentWords(i, visited, componentWords);

            // Print the words of this component
            std::cout << "Component " << numComponents << " has " << componentWords.size() << " words: ";
            for (const std::string& word : componentWords) {
                std::cout << word << " ";
            }
            std::cout << std::endl;
        }
    }

    std::cout << "Total number of connected components: " << numComponents << std::endl;
}

