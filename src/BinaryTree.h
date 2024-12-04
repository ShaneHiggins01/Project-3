#pragma once

#include "Star.h"

struct Node {
    Star* star;
    Node* left, * right;

    Node(Star* data) {
        star = data;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
    
public:
    Node* root;
    BinaryTree();
    BinaryTree(Node* root);
    bool SameFloat(float, float);
    Node* BreadthFirstSearch(Node*, float);
    //Node* DepthFirstSearch(Node*, float);
    void DepthFirstSearch(Node*, float, vector<Node*>);
    void InsertStar(Node*, Star*);
    Node* InsertStarVector(Node*, vector<Star>);
};
