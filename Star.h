#include <string>

class Star {

    private:
    string name;
    int mass;
    pair<int, int> position; //0-24 right ascension, -90 - 90 declination
    int distance; //5-100 in lightyears
}