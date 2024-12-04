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
Node* BinaryTree::BreadthFirstSearch(Node* root, float mass) //float mass is what we are looking for
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

/*
//Don't know if this works yet
Node* BinaryTree::DepthFirstSearch(Node* root, float mass) //Literally just Inorder
{
    if (root == nullptr) 
        return root;
    DepthFirstSearch(root->left, mass);
    if(SameFloat(root->star->getMass(), mass))
        return root;
    DepthFirstSearch(root->right, mass);
    return;
}
*/

// An empty vector<Node*> list will be passed in, then push when found
void BinaryTree::DepthFirstSearch(Node* root, float mass, vector<Node*> nodeList) //Literally just Inorder
{
    // Perform inOrder traversal
    if (root != nullptr) 
    {
        DepthFirstSearch(root->left, mass, nodeList);
        if(SameFloat(root->star->getMass(), mass))
            nodeList.push_back(root);
        DepthFirstSearch(root->right, mass, nodeList);
        
    }
}


void BinaryTree::InsertStar(Node* root, Star* InsertedStar)
{
    // If no root in tree, insert it here
    if (this->root == nullptr) 
        this->root = root;
    // If new mass is greater, check to make sure right is null 
    if (root->star->getMass() < InsertedStar->getMass()) 
    {

        // If right is nullptr, insert there
        if(root->right == nullptr)            
            root->right = new Node(InsertedStar);
        // If right is not nullptr, call recursion
        else
            InsertStar(root->right, InsertedStar);
    }
    // If new mass is less than or equal to, check to make sure left is null 
    else
    {
        // If left is nullptr, insert there
        if(root->left == nullptr)            
            root->left = new Node(InsertedStar);
        // If left is not nullptr, call recursion
        else
            InsertStar(root->left, InsertedStar);
    }


}

Node* BinaryTree::InsertStarVector(Node* root, vector<Star> InsertedStars)
{
    for(auto i : InsertedStars){
        InsertStar(this->root, &i); // this->root ensures the insertion starts at the root node in the tree
    }
}
