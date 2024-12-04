#pragma once

#include <string>
#include <queue>
using namespace std;

#pragma once

class Star {

    private:
    string name;
    float mass; //0.5-8 solar masses 10^30
    pair<double, double> position; //0-24 right ascension, -90 - 90 declination
    int distance; //5-100 in lightyears

    public:
    Star(string name, float mass, pair<double, double> position, int distance);
    string getName();
    float getMass();
};
