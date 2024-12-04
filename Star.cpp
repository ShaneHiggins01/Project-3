#include "Star.h"

Star::Star(string newName, float newMass, pair<double, double> newPosition, int newDistance) {
    name = newName;
    mass = newMass;
    position = newPosition;
    distance = newDistance;
}

string Star::getName() {
    return name;
}