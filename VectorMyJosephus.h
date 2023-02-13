#ifndef VECTORMYJOSEPHUS_H
#define VECTORMYJOSEPHUS_H

#include "Destination.h"
#include <vector>

using std::vector;

class VectorMyJosephus {
public:
    VectorMyJosephus(int M, int N);
    ~VectorMyJosephus();

    void clear();
    int currentSize();
    bool isEmpty();
    Destination eliminateDestination();
    void printAllDestinations();

private:
    int M;
    int N;
    vector<Destination> destinationVector;
};

#endif