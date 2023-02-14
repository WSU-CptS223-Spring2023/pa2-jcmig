#include "ListMyJosephus.h"

using namespace std;

void testListMyJosephus() {
    int M = 3, N = 4;
    int line;
    string csvLine;
    ListMyJosephus listJosephus = ListMyJosephus(M, N);
    ifstream infile("destinations.csv");

    clock_t k = clock();
    clock_t cpuStart;
    do cpuStart = clock();
    while (cpuStart == k);

    srand(time(0));
    line = rand() % 25 + 1;

    cout << "** Test ListMyJosephus**" << endl;
    cout << "M: " << M << " ; N: " << N << " ; Selected line: " << line << endl;

    if (infile.is_open()) {
        while (getline(infile, csvLine)) {
            stringstream lineStream(csvLine);
            string destinationName;
            getline(lineStream, destinationName, ';');
            Destination dest = Destination(line, destinationName);
            listJosephus.addDestination(dest);
            N++;
        }
    }

    list<Destination> eliminatedDestinations;
    cout << "Original destinations:" << endl;
    listJosephus.printAllDestinations();

    clock_t j = clock();
    clock_t elimStart;
    do elimStart = clock();
    while (elimStart == k);

    while (listJosephus.currentSize() > 1) {
        int i = 1;
        Destination dest = listJosephus.eliminateDestination();
        eliminatedDestinations.push_back(dest);
        cout << "ROUND #" << i << " --- Remaining destinations:" << endl;
        listJosephus.printAllDestinations();
    }

    clock_t elimEnd = clock();

    cout << "~~~~~~~~~~~~~~~" << endl;
    cout << "Order of elimination:" << endl;

    list<Destination>::iterator itr;
    for (itr = eliminatedDestinations.begin(); itr != eliminatedDestinations.end(); ++itr) {
        itr->printPosition();
        itr->printDestinationName();
    }

    cout << "- - - - - - - - - - - - - - -" << endl;
    listJosephus.printAllDestinations();
    cout << "- - - - - - - - - - - - - - -" << endl;

    clock_t cpuEnd = clock();

    double cpuTime = (cpuEnd - cpuStart) / CLOCKS_PER_SEC;
    cpuTime = cpuTime * 1000;

    double elimTime = (elimStart - elimEnd) / CLOCKS_PER_SEC;
    elimTime = elimTime * 1000000;

    cout << "~~List testing~~" << endl;
    cout << "N=" << N << ",M=" << M << endl;
    cout << "Total CPU time: " << cpuTime << " milliseconds" << endl;
    cout << "Avg elimination time: " << elimTime << " microseconds" << endl;
}