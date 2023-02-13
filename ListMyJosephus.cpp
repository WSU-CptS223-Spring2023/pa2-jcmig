#include "ListMyJosephus.h"

ListMyJosephus::ListMyJosephus(int m, int n) : M(m), N(n) {
    for (int i = 1; i <= N; i++) {
        Destination dest(i, "city" + to_string(i));
        destinationList.push_back(dest);
    }
}

ListMyJosephus::~ListMyJosephus() {}

void ListMyJosephus::clear() {
    destinationList.clear();
}

int ListMyJosephus::currentSize() {
    return destinationList.size();
}

bool ListMyJosephus::isEmpty() {
    return destinationList.empty();
}

Destination ListMyJosephus::eliminateDestination() {
    list<Destination>::iterator itr = destinationList.begin();
    int counter = 0;
    while (destinationList.size() > 1) {
        if (counter == M - 1) {
            Destination eliminatedDest = *itr;
            itr = destinationList.erase(itr);
            if (itr == destinationList.end()) {
                itr = destinationList.begin();
            }
            counter = 0;
            continue;
        }
        ++itr;
        ++counter;
        if (itr == destinationList.end()) {
            itr = destinationList.begin();
        }
    }
    return destinationList.front();
}

void ListMyJosephus::printAllDestinations() {
    list<Destination>::iterator itr;
    for (itr = destinationList.begin(); itr != destinationList.end(); ++itr) {
        itr->printPosition();
        itr->printDestinationName();
    }
}