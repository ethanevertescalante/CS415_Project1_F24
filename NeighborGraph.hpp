//
// Created by Ethan on 9/25/2024.
//

#ifndef CS415_PROJECT1_F24_NEIGHBORGRAPH_HPP
#define CS415_PROJECT1_F24_NEIGHBORGRAPH_HPP

#include "Vertex.hpp"
#include <iostream>
#include <vector>

class NeighborGraph {
    public:
        NeighborGraph(const std::vector<std::string> &words); //class constructor

        int numConnectedComponents();
        int sizeOfConnectedComponents(int i);
        int size(); //number of verticies

        bool latterExists(const std::string &startWord, const std::string &targetWord);

        void dfsPathFromTo(const std::string &startWord, const std::string &targetWord, std::vector<std::string> &ladder); //depth first search
        int bfsPathFromTo(const std::string &startWord, const std::string &targetWord, std::vector<std::string> &ladder); //breadth first search

    private:


};


#endif //CS415_PROJECT1_F24_NEIGHBORGRAPH_HPP
