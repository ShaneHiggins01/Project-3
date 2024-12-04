#pragma once

#include "BinaryTree.h"
#include "Star.h"
#include <cmath>

using namespace std;

BinaryTree::BinaryTree() {
}

bool BinaryTree::SameFloat(float f1, float f2)
{
    return (abs(f1 - f2) < 0.0001) //using < 0.0001 for floating point math
}

//Don't know if this works yet
Node* BinaryTree::BreathFirstSearch(Node* root, float mass) //float mass is what we are looking for
{
    if (root == nullptr)
        return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop(); 
        if(SameFloat(root->star->getMass(), mass)) //If the mass is what we're looking for
            return node;
        if (node->left != nullptr)
            q.push(node->left);
        if (node->right != nullptr)
            q.push(node->right);
    }
    return;
}

//Don't know if this works yet
Node* BinaryTree::DepthFirstSearch(Node* root, float mass) //Literally just Inorder
{
    if (root == nullptr) 
        return;
    DepthFirstSearch(root->left);
    if(SameFloat(root->star->getMass(), mass))
        return node;
    DepthFirstSearch(root->right);
    return;
}

Node* BinaryTree::InsertStar(Node* root, Star* InsertedStar)
{
    if (root == nullptr)
        return;
    if (root->star->getMass() == InsertedStar->getMass)
        return root; //If it already exists
    
    if (root->star->getMass() < InsertedStar->getMass)
        root->right = insert(root->right, InsertedStar);
    else
        root->left = insert(root->left, InsertedStar);
    return root;
}
Node* BinaryTree::InsertStarVector(Node* root, vector<Star> InsertedStars)
{
    for(auto i : InsertedStars){
        InsertStar(root, i*);
    }
}
