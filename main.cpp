#include "Star.h"
#include "GenerateData"
#include <iostream>
using namespace std;

int main() {
    
    vector<Star> stars;
    stars = generateData(1);

    cout << stars[0].getName();

    return 0;
}