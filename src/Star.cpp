#pragma once
#include <iostream>
#include "Star.h"
using namespace std;

Star::Star(string newName, float newMass, pair<double, double> newPosition, int newDistance) {
    name = newName;
    mass = newMass;
    position = newPosition;
    distance = newDistance;
}

Star::Star() {

}


string Star::getName() {
    return name;
}

float Star::getMass() {
    return mass;
}

void Star::printStarInfo() {
    cout << "Star Name: " << name << endl;
    cout << "Star Mass: " << mass << endl;
    cout << "Star Position: " << position.first << " " << position.second << endl;
    cout << "Star Distance: " << distance << endl;
}