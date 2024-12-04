#pragma once

#include "BinaryTree.h"
#include "Star.h"
#include "iostream"
#include <cmath>

using namespace std;
BinaryTree::BinaryTree() {
    this->root = nullptr;
}


bool BinaryTree::SameFloat(float f1, float f2)
{
    return (abs(f1 - f2) < 0.0001); //using < 0.0001 for floating point math
}

Node* BinaryTree::BreadthFirstSearch(Node* root, float mass) //float mass is what we are looking for
{
    if (root == nullptr)
        return nullptr;
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
    return nullptr;
}

// An empty vector<Node*> list will be passed in, then push when found
void BinaryTree::BreadthFirstSearchList(Node* root, float mass, vector<Node*> nodeList)
{
    if (root != nullptr) 
    {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop(); 
            if(SameFloat(root->star->getMass(), mass)) //If the mass is what we're looking for
                nodeList.push_back(root);
            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
    }
}


Node* BinaryTree::DepthFirstSearch(Node* root, float mass) //Literally just Inorder
{
    if (root == nullptr) 
        return root;
    DepthFirstSearch(root->left, mass);
    if(SameFloat(root->star->getMass(), mass))
        return root;
    DepthFirstSearch(root->right, mass);
    return nullptr;
}

// An empty vector<Node*> list will be passed in, then push when found
void BinaryTree::DepthFirstSearchList(Node* root, float mass, vector<Node*> nodeList)
{
    // Perform inOrder traversal
    if (root != nullptr) 
    {
        DepthFirstSearchList(root->left, mass, nodeList);
        if(SameFloat(root->star->getMass(), mass))
            nodeList.push_back(root);
        DepthFirstSearchList(root->right, mass, nodeList);
        
    }
}

void BinaryTree::InsertStar(Node* root, Star* InsertedStar)
{
    // If no root in tree, insert it here
    if (this->root == nullptr) {
        root = new Node(InsertedStar);
        this->root = root;
    }
    // If new mass is greater, check to make sure right is null
    else if (root->star->getMass() < InsertedStar->getMass())
    {
        // If right is nullptr, insert there
        if(root->right == nullptr)
        {
            root->right = new Node(InsertedStar);
            cout << InsertedStar->getMass() << endl;
        }
        // If right is not nullptr, call recursion
        else
        {
            InsertStar(root->right, InsertedStar);
            cout << InsertedStar->getMass() << endl;
        }
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

//BROKEN
void BinaryTree::InsertStarVector(Node* root, vector<Star> InsertedStars)
{
    for(auto i : InsertedStars){
        InsertStar(this->root, &i); // this->root ensures the insertion starts at the root node in the tree
    }
}

void BinaryTree::PrintInorder(Node* root)
{
    //cout << "PrintInorder called" << endl;
    if(root != nullptr) {
        cout << root->star->getMass() << endl;
        PrintInorder(root->left);
        PrintInorder(root->right);
    }
}
