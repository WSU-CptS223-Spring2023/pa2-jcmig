#include <fstream>
#include <sstream>
#include <list>
#include "Destination.h"
#include "ListMyJosephus.h"

using namespace std;

void testListMyJosephus() {
    int N = 4, M = 3;
    int lineNum;
    string line;
    string destinationString;
    string city;
    string country;
    Destination destination();
    list<Destination> destinationList;

    ifstream file("destinations.csv");
    for (int i = 0; i < lineNum; i++) {
        getline(file, line);
    }

    stringstream lineStream(line);
    while (getline(lineStream, destinationString, ';')) {
        int pos = destinationList.size();
        int index = destinationString.find(",");
        city = destinationString.substr(0, index);
        country = destinationString.substr(index + 2);
    }
}