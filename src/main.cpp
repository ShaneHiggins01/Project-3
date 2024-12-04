#pragma once

#include "Star.h"
#include "BinaryTree.h"
#include "printStar.h"
#include "GenerateData.h"

#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <cmath>
using namespace std;


void invalidInput() {
    cout << "Invalid input" << endl;
}

bool checkIntInput(string input) {
    if(all_of(input.begin(), input.end(), ::isdigit)) {
        return true;
    } else {
        return false;
    }
}

bool checkFloatInput(string input) {
    if(all_of(input.begin(), input.end(), ::isdigit)) {
        return true;
    } else {
        for(int i = 0; i < input.size(); i++) {
            if(!isdigit(input[i]) && input[i] != '.') {
                return false;
            }
        }
        return true;

    }
}

void preGenData(vector<Star> &stars, BinaryTree &tree) {
    string input;
    bool selected = false;
    while(!selected) {

        cout << "How many Stars would you like to generate (up to 1,000,000)" << endl;
        cin >> input;

        //input = "10"; //DELETE
        if(checkIntInput(input)) {
            if(stoi(input) < 0 || stoi(input) > 10000000) {
                invalidInput();
            } else {
                stars = generateData(stoi(input));
                for(auto i : stars)
                {
                    tree.InsertStar(tree.root, i);
                }
                //cout << "Print Preorder" << endl;
                //tree.PrintInorder(tree.root);
                selected = true;
            }
        } else {
            invalidInput();
        }
    }


}

void preInsertCustom(vector<Star> &stars, BinaryTree &tree) {
    string input;
    bool selected = false;
    string newName;
    float newMass;
    double newAngle1;
    double newAngle2;
    int newDistance;




    cout << "Name your star!" << endl;
    cin >> input;
    newName = input;
    while(!selected) {
        cout << "What is the mass of your star in solar masses! (0.50-8.00 2 decimal places)" << endl;
        cin >> input;
        if(checkFloatInput(input)) {
            if(stof(input) < 0.5 || stof(input) > 8) {
                invalidInput();
            } else {
                newMass = stof(input);
                selected = true;
            }
        } else {
            invalidInput();
        }
    }

    selected = false;
    while(!selected) {
        cout << "What is the right ascension of your star! (0.0-24.0 up 1 decimal place)" << endl;
        cin >> input;
        if(checkFloatInput(input)) {
            if(stod(input) < 0 || stod(input) > 24) {
                invalidInput();
            } else {
                newAngle1 = stod(input);
                selected = true;
            }
        } else {
            invalidInput();
        }
    }

    selected = false;
    while(!selected) {
        cout << "What is the declination of your star! (-90.0 to 90.0 1 decimal place)" << endl;
        cin >> input;
        if(checkFloatInput(input)) {
            if(stod(input) < -90 || stod(input) > 90) {
                invalidInput();
            } else {
                newAngle2 = stod(input);
                selected = true;
            }
        } else {
            invalidInput();
        }
    }

    selected = false;
    while(!selected) {
        cout << "What is the distance of your star to Earth in lightyears! (5 to 100)" << endl;
        cin >> input;
        if(checkIntInput(input)) {
            if(stoi(input) < 5 || stoi(input) > 100) {
                invalidInput();
            } else {
                newDistance = stoi(input);
                selected = true;
            }
        } else {
            invalidInput();
        }
    }
    pair<int, int> newPosition = make_pair(newAngle1, newAngle2);
    Star newStar(newName, newMass, newPosition, newDistance);
    //Star *newStarPointer = &newStar;
    //tree.InsertStar(tree.root, newStarPointer);

}

Star preSearchBFS(BinaryTree tree) {
    string input;
    Node* resultNode;
    Star* resultStar;
    bool selected = false;
    while (!selected) {
        cout << "What star mass would you like to search for? (0.5 to 8 up to 2 decimal places)" << endl;
        cin >> input;
        if(checkFloatInput(input)) {
            if(stof(input) < 0.5 || stof(input) > 8) {
                invalidInput();
            } else {
                auto StartTime = chrono::high_resolution_clock::now();
                //resultNode = tree.BreadthFirstSearch(tree.root, stof(input));
                auto EndTime = chrono::high_resolution_clock::now();
                auto TimeTaken = std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - StartTime); //This gives timetaken in milliseconds
                cout << "Time taken to search: " << TimeTaken.count() << " miliseconds." << endl;

                //resultStar = resultNode->star;
                resultStar->printStarInfo();
                selected = true;
            }
        } else {
            invalidInput();
        }
    }
    return *resultStar;
}

void preSearchDFS(BinaryTree tree) {
    string input;
    vector<Node*> resultNodes;
    vector<Star*> resultStars;
    bool selected = false;
    while (!selected) {
        cout << "What star mass would you like to search for? (0.5 to 8 up to 2 decimal places)" << endl;
        cin >> input;
        if(checkFloatInput(input)) {
            if(stof(input) < 0.5 || stof(input) > 8) {
                invalidInput();
            } else {
                auto StartTime = chrono::high_resolution_clock::now();
                tree.DepthFirstSearchList(tree.root, stof(input), resultNodes);
                auto EndTime = chrono::high_resolution_clock::now();
                auto TimeTaken = std::chrono::duration_cast<std::chrono::milliseconds>(EndTime - StartTime); //This gives timetaken in milliseconds
                cout << "Time taken to search: " << TimeTaken.count() << " miliseconds." << endl;

                //resultStars = resultNodes->star;
                //resultStars->printStarInfo();
                selected = true;
            }
        } else {
            invalidInput();
        }
    }
}

int main() {
    vector<Star> stars;
    BinaryTree tree;

    bool quit = false;

    printStar2();
    cout << "Hello, and welcome to Star Searcher." << endl;
    cout << "Please select an option below" << endl;
    cout << "-------------------" << endl;

    string input;
    while (!quit){

        cout << "1. Generate Star Dataset" << endl;
        cout << "2. Insert Custom Star" << endl;
        cout << "3. Search for specified mass with BFS" << endl;
        cout << "4. Search for specified mass with DFS" << endl;
        cout << "9. Exit Program" << endl;

        cin >> input;
        //input = "1"; //DELETE
        if(checkIntInput(input)) {
            if(stoi(input) == 1) {
                preGenData(stars, tree);
            } 

            else if (stoi(input) == 2) {
                preInsertCustom(stars, tree);
            }

            else if (stoi(input) == 3) {
                
                preSearchBFS(tree);
                
            }

            else if(stoi(input) == 4) {
                
                preSearchDFS(tree);
                
            }
            else if(stoi(input) == 9) {
                exit(0);
            }

            else {
                invalidInput();
            }

        } else {
            invalidInput();
        }

    }

    return 0;
}

