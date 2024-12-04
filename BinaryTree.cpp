#include "Star.h"
#include <cmath>

using namespace std;

struct Node {
    Star* star;
    Node* left, * right;

    Node(Star* data) {
        star = data;
        left = nullptr;
        right = nullptr;
    }
};

//Don't know if this works yet
Node* BinaryTree::BreathFirstSearch(Star* root, float mass) //float mass is what we are looking for
{
    if (root == nullptr)
        return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop(); 
        if(abs(node->star.getMass() - mass < 0.0001)) //If the mass is what we're looking for, using < 0.0001 for floating point math
            return node;
        if (node->left != nullptr)
            q.push(node->left);
        if (node->right != nullptr)
            q.push(node->right);
    }
    return;
}

//Don't know if this works yet
Node* BinaryTree::DepthFirstSearch(Star* root, float mass) //Literally just Inorder
{
    if (root == nullptr) 
        return;
    DepthFirstSearch(root->left);
    if(abs(root->star.getMass() - mass < 0.0001))
        return node;
    DepthFirstSearch(root->right);
    return;
}
