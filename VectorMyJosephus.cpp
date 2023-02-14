#include "VectorMyJosephus.h"

VectorMyJosephus::VectorMyJosephus(int m, int n) : M(m), N(n) {}

VectorMyJosephus::~VectorMyJosephus() {}

void VectorMyJosephus::clear() {
    destinationVector.clear();
}

int VectorMyJosephus::currentSize() {
    return destinationVector.size();
}

bool VectorMyJosephus::isEmpty() {
    return destinationVector.empty();
}

Destination VectorMyJosephus::eliminateDestination() {
    int index = (M - 1) % destinationVector.size();
    Destination rmd = destinationVector[index];
    destinationVector.erase(destinationVector.begin() + index);
    return rmd;
}

void VectorMyJosephus::printAllDestinations() {
    vector<Destination>::iterator itr;
    for (itr = destinationVector.begin(); itr != destinationVector.end(); ++itr) {
        itr->printPosition();
        itr->printDestinationName();
    }
}

void VectorMyJosephus::addDestination(Destination dest) {
    destinationVector.push_back(dest);
}