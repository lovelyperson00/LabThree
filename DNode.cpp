/* By: Adam Higazi & Nicole Kinsella */

#ifndef DNODE_HPP_
#define DNODE_HPP_
#include <stdlib.h>
using namespace std;
#include "DNode.hpp"
// #include "Song.cpp"

DNode::DNode(){
    Song song = NULL;
    DNode prev = NULL;
    DNode next = NULL;
    };

DNode::DNode(string s, string a, int lenmin, int lensec){
    Song song = new Song(s,a,lenmin,lensec);
    DNode prev = NULL;
    DNode next = NULL;
}

#endif /* DNODE_HPP_ */