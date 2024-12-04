#pragma once

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
    Node* TreeRoot;
    BinaryTree();
    bool SameFloat(float, float);
    Node* BreathFirstSearch(Node*, float);
    Node* DepthFirstSearch(Node*, float);
    Node* InsertStar(Node*, Star*);
    Node* InsertStarVector(Node*, vector<Star>);
};
