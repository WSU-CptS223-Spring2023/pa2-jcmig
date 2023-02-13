#include "Destination.h"

Destination::Destination(int pos, string name) : position(pos), name(name) {}

Destination::~Destination() {}

void Destination::printPosition() {
    cout << "Position: " << position << endl;
}

void Destination::printDestinationName() {
    cout << "Destination Name: " << name << endl;
}