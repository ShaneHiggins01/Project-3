#include "Star.h"
#include "GenerateData"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    vector<Star> stars;
    stars = generateData(1);
    bool quit = false;

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
        if(checkInput(input)) {
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
        if(checkInput(input)) {
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
    

    while(!selected) {
        cout << "Name your star!" << endl;
        cin >> input;

    }
}

void preSearchBFS() {

}

void preSearchDFS() {

}

bool checkInput(string input) {
    if(all_of(input.begin(), input.end(), ::isdigit)) {
        return true;
    } else {
        return false;
    }
}