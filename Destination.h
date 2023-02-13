#ifndef DESTINATION_H
#define DESTINATION_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

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