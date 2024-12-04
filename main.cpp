#include "Star.h"
#include "GenerateData"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    vector<Star> stars;
    stars = generateData(1);
    bool selected = false;

    printStar2();
    cout << "Hello, and welcome to Star Searcher." << endl;
    cout << "Please select an option below" << endl;
    cout << "-------------------" << endl;

    string input;
    while (!selected){
        
        cout << "1. Generate Star Dataset" << endl;
        cout << "2. Insert Custom Star" << endl;
        cout << "3. Search for specified mass with BFS" << endl;
        cout << "4. Search for specified mass with DFS" << endl;

        cin >> input;
        if(checkInput(input)) {
            if(stoi(input) == 1) {
                preGenData();
                selected != selected;
            } 

            else if (stoi(input) == 2) {
                preInsertCustom();
                selected != selected;
            }

            else if (stoi(input) == 3) {
                preSearchBFS();
                selected != selected;
            }

            else if(stoi(input) == 4) {
                preSearchDFS();
                selected != selected;
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
    cout << "Invalid Input" << endl;
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
            } 
        }
    }
    

}

void preInsertCustom() {

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
