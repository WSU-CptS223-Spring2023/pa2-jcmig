#ifndef LISTMYJOSEPHUS_H
#define LISTMYJOSEPHUS_H

#include "Destination.h"
#include <list>


using std::list;
using std::to_string;

class ListMyJosephus {
public:
    ListMyJosephus(int M, int N);
    ~ListMyJosephus();

    void clear();
    int currentSize();
    bool isEmpty();
    Destination eliminateDestination();
    void printAllDestinations();

    void addDestination(Destination dest);

private:
    int M;
    int N;
    list<Destination> destinationList;
};

#endif