#pragma once

#include "Star.h"
#include "GenerateData.cpp"
#include "BinaryTree.h"
#include <iostream>
#include <bits/stdc++.h>
#include "printStar.cpp"
using namespace std;

#pragma once


int main() {
    
    vector<Star> stars;
    stars = generateData(1);
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

        cin >> input;
        if(checkIntInput(input)) {
            if(stoi(input) == 1) {
                preGenData();
            } 

            else if (stoi(input) == 2) {
                preInsertCustom();
            }

            else if (stoi(input) == 3) {
                preSearchBFS();
            }

            else if(stoi(input) == 4) {
                preSearchDFS();
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

void invalidInput() {
    cout << "Invalid input" << endl;
}

void preGenData() {
    string input;
    bool selected = false;
    while(!selected) {
        cout << "How many Stars would you like to generate (up to 100,000)" << endl;
        cin >> input;
        if(checkIntInput(input)) {
            if(stoi(input) < 0 || stoi(input) > 100000) {
                invalidInput();
            } else {
                generateData(stoi(input));
                selected = true;
            }
        } else {
            invalidInput();
        }
    }
    

}

void preInsertCustom() {
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
}

void preSearchBFS() {
    string input;
    bool selected = false;
    while (!selected) {
        cout << "What star mass would you like to search for? (0.5 to 8 up to 2 decimal places)" << endl;
        cin >> input;
        if(checkFloatInput(input)) {
            if(stof(input) < 0.5 || stof(input) > 8) {
                invalidInput();
            } else {
                
            }
        } else {
            invalidInput();
        }
    }
}

void preSearchDFS() {

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