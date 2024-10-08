//
// Created by Ali A. Kooshesh on 2020-01-20, modified on 2020-09-15
//

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<tuple>

void readStartTargetWords(const std::string &inputFileName, std::vector<std::pair<std::string, std::string>> &startTargetVector ) {
    std::ifstream pairStream;
    pairStream.open(inputFileName, std::ios_base::in);
    if( ! pairStream.is_open()) {
        std::cout << "Unable to open the input file ->" << inputFileName << "<- that contains pairs of words.\n";
        exit(2);
    }
    std::cout << "Successfully opened " << inputFileName << std::endl;

    std::string start, target;
    while( pairStream >> start && pairStream >> target ) {
	startTargetVector.emplace_back(start, target);
    }
}


#include "Vertex.hpp"
#include "adjList.hpp"
void readWords(std::fstream &inStream, adjList &adjList) {
    // inStream is an open stream. This function reads a series of words 
    // from the stream and stores them in "words".

    std::string word;
    while( inStream >> word ) {
        Vertex vertex(word);
        adjList.addVertex(vertex);
    }

    for (int i = 0; i < adjList.size(); ++i) {
        for (int j = i + 1; j < adjList.size(); ++j) {
            if (adjList.areWordsAdjacent(adjList.getVertexWord(i), adjList.getVertexWord(j))) {
                adjList.addEdge(i, j);
            }
        }
    }
}



int main(int argc, char *argv[]) { // the main function.
    if( argc != 3 ) {
        std::cout << "usage: " << argv[0] << " inputFileNameThatContainsDictionary inputFileNameThatContainsPairsOfWords\n";
        exit(1);
    }

    std::fstream wordStream;
    wordStream.open(argv[1], std::ios_base::in);
    if( ! wordStream.is_open()) {
        std::cout << "Unable to open input file ->" << argv[1] << "<-\n";
        exit(2);
    }
    std::cout << "Successfully opened " << argv[1] << std::endl;

    adjList adjacencyList;
    std::vector<std::string> dictionary;

    readWords(wordStream, adjacencyList);

    //adjacencyList.printGraph();
    std::cout << std::endl;

    adjacencyList.findConnectedComponents();

    adjacencyList.resetVertices();


    std::vector<std::pair<std::string, std::string>> startTargetVector;
    readStartTargetWords( argv[2], startTargetVector );



    for( const auto& pair : startTargetVector ) {
         std::string start = pair.first;
         std::string target = pair.second;

        int startIdx = -1, targetIdx = -1;

        //assuming that the start and target words ARE in the dictionary
        // Find indices for the start and target words in the adjacency list
        for (int i = 0; i < adjacencyList.size(); ++i) {
            if (adjacencyList.getVertexWord(i) == start) startIdx = i;
            if (adjacencyList.getVertexWord(i) == target) targetIdx = i;
        }


        std::vector<std::string> path;

        if (adjacencyList.dfs(startIdx, targetIdx, path)) {
            std::string dfsFileTemp = start + "_" + target +"_" + "dfs";
            std::ofstream dfsFile(dfsFileTemp);
            dfsFile << "The ladder between words " << start << " and " << target << " is: " << std::endl;
            for (const auto& word : path) {
                dfsFile << word << std::endl;
            }
            dfsFile << target << std::endl;
        } else {
            std::cout << "No ladder found between " << start << " and " << target << "." << std::endl;
        }


        if (adjacencyList.bfs(startIdx, targetIdx, path)) {
            std::string bfsFileTemp = start + "_" + target +"_" + "bfs";
            std::ofstream bfsFile(bfsFileTemp);
            bfsFile << "The ladder between words " << start << " and " << target << " is: " << std::endl;
            for (const auto& word : path) {
                bfsFile << word << std::endl;
            }
            //std::cout << target << std::endl;
        } else {
            std::cout << "No ladder found between " << start << " and " << target << "." << std::endl;
        }

        adjacencyList.resetVertices();

    }

    adjacencyList.findAndPrintLongestLadder();


    return 0;
}
