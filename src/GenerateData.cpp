#include "Star.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;



vector<string> colors = {"Red", "Blue", "Purple", "Green", "Yellow", "Orange", "White", "Black", "Cyan", "Pink", "Brown", "Turquoise", "Beige"};
vector<string> sizes = {"Large", "Massive", "Dwarf", "Small", "Medium"};
vector<string> shapes = {"Flat", "Round", "Square"};




vector<Star> generateData(int numStars) {
    vector<Star> stars;
    
    for(int i = 0; i < numStars; i++) {
        srand(time(NULL)*i);
        int tmp = 0;
        string color;
        string size;
        string shape;
        string name = "";
        float mass;
        int distance;
        pair<double, double> position;


        tmp = rand() % colors.size();
        color = colors[tmp];
        tmp = rand() % sizes.size();
        size = sizes[tmp];
        tmp = rand() % shapes.size();
        shape = shapes[tmp];
        double angle1;
        double angle2;

        name += size;
        name += " ";
        name += color;
        name += " ";
        name += shape;
        name += " ";
        name += "Star";

        mass = (rand() % 801 + 5);
        mass /= 100 ; // 0.5 to 8 2 decimal places
        distance = rand() % 96 + 5; // 5 to 100
        angle1 = (rand() % 241)/10; //0 to 24 1 decimal place
        angle2 = (rand() % 1800)/10 - 90; //-90 to 90 1 decimal place
        position = make_pair(angle1, angle2);
        Star newStar(name, mass, position, distance);
        stars.push_back(newStar);
    }
    return stars;

}
