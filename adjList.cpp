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
    return vertices[index].word;
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


bool adjList::dfs(int start, int target, std::vector<std::string>& path, int& numWords) {
    //assuming that current and target are NOT the same
    path.push_back(vertices[start].word);

    vertices[start].hadVisited = true;
    vertices[start].onPath = true;

    for (int neighbor : adjList[start]) {
        if (!vertices[neighbor].hadVisited) {

            if (neighbor == target) {
                vertices[neighbor].onPath = true;
                numWords = path.size();
                return true;  // Path found
            }
            //check if neighbor of current vertex is true
            if (dfs(neighbor, target, path, numWords)) {
                return true;
            }

        }
    }

    vertices[start].onPath = false;
    path.pop_back();
    return false;
}


bool adjList::bfs(int start, int target, std::vector<std::string>& path, int& numWords) {
    std::queue<std::vector<int>> q;

    vertices[start].hadVisited = true;
    q.push({start});


    while (!q.empty()) {
        std::vector<int> currentPath = q.front();
        q.pop();

        int last = currentPath.back();

        if (last == target) {
            path.clear();
            for (int idx : currentPath) {
                path.push_back(vertices[idx].word);
            }
            numWords = path.size();
            return true;
        }


        for (int neighbor : adjList[last]) {
            if (!vertices[neighbor].hadVisited) {
                vertices[neighbor].hadVisited = true;
                //create new path for next iteration
                std::vector<int> newPath = currentPath;
                newPath.push_back(neighbor);
                q.push(newPath);
            }
        }

    }

    return false;
}


void adjList::longestLadder() {
    std::vector<std::string> longestLadderPath;


    for (int i = 0; i < vertices.size(); ++i) {
        std::pair<std::vector<int>, std::vector<int>> result = longestLadderHelper(i);
        std::vector<int> distances = result.first;
        std::vector<int> parents = result.second;

        int maxDistance = 0;
        int furthestVertex = i;

        for (int j = 0; j < distances.size(); ++j) {
            if (distances[j] > maxDistance) {
                maxDistance = distances[j];
                furthestVertex = j;
            }
        }

        std::vector<std::string> currladderPath;
        while (furthestVertex != -1) { //stop when no more parents are available
            //putting words into the ladder for output
            currladderPath.insert(currladderPath.begin(), vertices[furthestVertex].word);
            furthestVertex = parents[furthestVertex];
        }

        if (currladderPath.size() > longestLadderPath.size()) {
            longestLadderPath = currladderPath;
        }
    }

    std::ofstream longLadder("longest_Ladder.txt");
    longLadder << longestLadderPath.size() << std::endl << std::endl;
    for (const std::string& word : longestLadderPath) {
        longLadder << word << std::endl;
    }

}



std::pair<std::vector<int>, std::vector<int>> adjList::longestLadderHelper(int start) {
    std::vector<int> distances(vertices.size(), -1);
    std::vector<int> parents(vertices.size(), -1);
    std::queue<int> queue;

    distances[start] = 0;
    queue.push(start);
    vertices[start].hadVisited = true;

    while (!queue.empty()) {
        int front = queue.front();
        queue.pop();

        for (int neighbor : adjList[front]) {
            if (!vertices[neighbor].hadVisited) {
                vertices[neighbor].hadVisited = true;
                distances[neighbor] = distances[front] + 1;
                parents[neighbor] = front;
                queue.push(neighbor);
            }
        }
    }

    resetVertices();

    return std::make_pair(distances, parents);
}






void adjList::connectedComponents() {
    int numComponents = 0;

    for (int i = 0; i < vertices.size(); ++i) {
        if (!vertices[i].hadVisited) {

            ++numComponents;
            std::vector<std::string> component;
            componentHelper(i, component);
            std::cout << "Component " << numComponents << " contains " << component.size() << " words." << std::endl;

        }
    }

    std::cout << "Total number of connected components: " << numComponents << std::endl;
}



int adjList::componentHelper(int v, std::vector<std::string>& component) {
    vertices[v].hadVisited = true;
    component.push_back(vertices[v].word);

    for (int neighbor : adjList[v]) {
        if (!vertices[neighbor].hadVisited) {
            componentHelper(neighbor, component);
        }
    }

}


