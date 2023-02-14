#include "ListMyJosephus.h"

using namespace std;

void testListMyJosephus(int M, int N) {
    int line;
    string csvLine;
    ListMyJosephus listJosephus = ListMyJosephus(M, N);
    ifstream infile("destinations.csv");
    ofstream outfile("results.log");

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

    double elimTimes[listJosephus.currentSize()];
    double elimTime;

    while (listJosephus.currentSize() > 1) {
        int i = 0;
        
        clock_t j = clock();
        clock_t elimStart;
        do elimStart = clock();
        while (elimStart == j);

        Destination dest = listJosephus.eliminateDestination();
        eliminatedDestinations.push_back(dest);

        clock_t elimEnd = clock();

        cout << "ROUND #" << i + 1 << " --- Remaining destinations:" << endl;
        listJosephus.printAllDestinations();

        elimTime = (elimStart - elimEnd) / CLOCKS_PER_SEC;
        elimTime = elimTime * 1000000;
        elimTimes[i] = elimTime;

        i++;
    }

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

    double elimTimesSum, elimTimeAvg;
    for (int i = 0; i < (sizeof(elimTimes) / sizeof(double)); i++) {
        elimTimesSum += elimTimes[i];
    }

    elimTimeAvg = elimTimesSum / (sizeof(elimTimes) / sizeof(double));

    if (outfile.is_open()) {
        outfile << "N=" << N << ",M=" << M << endl;
        outfile << "Total CPU time: " << cpuTime << " milliseconds" << endl;
        outfile << "Avg elimination time: " << elimTimeAvg << " microseconds" << endl << endl;
    }

}