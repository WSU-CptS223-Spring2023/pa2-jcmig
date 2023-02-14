#ifndef DESTINATION_H
#define DESTINATION_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

using std::string;
using std::cout;
using std::endl;
using std::stringstream;
using std::getline;

class Destination {
public:
    Destination(int position, string name);
    ~Destination();

    void printPosition();
    void printDestinationName();

private:
    int position;
    string name;
};

#endif