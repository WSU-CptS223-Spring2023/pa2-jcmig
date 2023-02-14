#include "Destination.h"

Destination::Destination(int pos, string name) : position(pos), name(name) {}

Destination::~Destination() {}

void Destination::printPosition() {
    cout << position << ". ";
}

void Destination::printDestinationName() {
    cout << name << ", ";
}