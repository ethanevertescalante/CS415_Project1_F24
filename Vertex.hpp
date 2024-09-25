//
// Created by Ethan on 9/25/2024.
//

#ifndef CS415_PROJECT1_F24_VERTEX_HPP
#define CS415_PROJECT1_F24_VERTEX_HPP

#include <iostream>


//user defined type
class Vertex {
    //each vertex will have these attributes
    public:
        std::string word;
        bool onPath;
        bool hadVisited;
        int componentId; //-1 means uninitialized, I will start at 1 to avoid confusion

        Vertex(std::string word) : word(word), onPath(false), hadVisited(false), componentId(-1) {} //initialization (constructor)
};


#endif //CS415_PROJECT1_F24_VERTEX_HPP
