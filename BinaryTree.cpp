#pragma once

#include "BinaryTree.h"
#include "Star.h"
#include <cmath>

using namespace std;

BinaryTree::BinaryTree() {
}


bool BinaryTree::SameFloat(float f1, float f2)
{
    return (abs(f1 - f2) < 0.0001); //using < 0.0001 for floating point math
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
    DepthFirstSearch(root->left, mass);
    if(SameFloat(root->star->getMass(), mass))
        return root;
    DepthFirstSearch(root->right, mass);
    return;
}


Node* BinaryTree::InsertStar(Node* root, Star* InsertedStar)
{
    if (root == nullptr) //Insert it in
        return new Node(InsertedStar);
    if (root->star->getMass() < InsertedStar->getMass())
        root->right = InsertStar(root->right, InsertedStar);
    else
        root->left = InsertStar(root->left, InsertedStar);
    return root;
}
/*
void BinaryTree::InsertStar(Node* root, Star* InsertedStar)
{
    // If no root in tree, insert it here
    if (this->Root == nullptr) 
        this->Root = root;
    // If new mass is greater, check to make sure right is null 
    if (root->star->getMass() < InsertedStar->getMass()) 
        // If right is nullptr, insert there
        if(root->right == nullptr)            
            root->right = new Node(InsertedStar);
        // If right is not nullptr, call recursion
        else
            InsertStar(root->right, InsertedStar);
    
    // If new mass is less than, check to make sure left is null 
    else if (root->star->getMass() > InsertedStar->getMass())
        // If left is nullptr, insert there
        if(root->left == nullptr)            
            root->left = new Node(InsertedStar);
        // If left is not nullptr, call recursion
        else
            InsertStar(root->left, InsertedStar);
    
    // If neither is true, masses are equal (don't insert)

}
*/

Node* BinaryTree::InsertStarVector(Node* root, vector<Star> InsertedStars)
{
    for(auto i : InsertedStars){
        InsertStar(root, i*);
    }
}
