//
// Created by Ali A. Kooshesh on 2020-01-20, modified on 2020-09-15
//

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<tuple>
/*
void readStartTargetWords(const std::string &inputFileName, std::vector<std::tuple<std::string, std::string>> &startTargetVector ) {
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
*/

#include "Vertex.hpp"
#include "adjList.hpp"



void readWords(std::fstream &inStream, std::vector<std::string> & words, adjList &adjList) {
    // inStream is an open stream. This function reads a series of words 
    // from the stream and stores them in "words".

    std::string word;
    while( inStream >> word ) {
        Vertex vertex(word);
        adjList.addVertex(vertex);
        //words.push_back(word);
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
    readWords(wordStream, dictionary, adjacencyList);

    adjacencyList.printGraph();

/*
    std::vector<std::tuple<std::string, std::string>> startTargetVector;
    readStartTargetWords( argv[2], startTargetVector );
    for( const auto& [start, target]: startTargetVector )
	std::cout << start << " " << target << std::endl;
*/
    return 0;
}
