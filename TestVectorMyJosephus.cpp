#include "VectorMyJosephus.h"

using namespace std;

void testVectorMyJosephus(int M, int N) {
    int line;
    string csvLine;
    VectorMyJosephus vectorJosephus = VectorMyJosephus(M, N);
    ifstream infile("destinations.csv");
    ofstream outfile("results.log");

    clock_t k = clock();
    clock_t cpuStart;
    do cpuStart = clock();
    while (cpuStart == k);

    srand(time(0));
    line = rand() % 25 + 1;

    cout << "** Test VectorMyJosephus**" << endl;
    cout << "M: " << M << " ; N: " << N << " ; Selected line: " << line << endl;

    if (infile.is_open()) {
        while (getline(infile, csvLine)) {
            stringstream lineStream(csvLine);
            string destinationName;
            getline(lineStream, destinationName, ';');
            Destination dest = Destination(line, destinationName);
            vectorJosephus.addDestination(dest);
            N++;
        }
    }

    vector<Destination> eliminatedDestinations;
    cout << "Original destinations:" << endl;
    vectorJosephus.printAllDestinations();

    double elimTimes[vectorJosephus.currentSize()];
    double elimTime;

    int i = 0;
    while (vectorJosephus.currentSize() > 1) {
        clock_t j = clock();
        clock_t elimStart;
        do elimStart = clock();
        while (elimStart == j);

        Destination dest = vectorJosephus.eliminateDestination();
        eliminatedDestinations.push_back(dest);

        clock_t elimEnd = clock();

        cout << "ROUND #" << i + 1 << " --- Remaining destinations:" << endl;
        vectorJosephus.printAllDestinations();

        elimTime = (elimStart - elimEnd) / CLOCKS_PER_SEC;
        elimTime = elimTime * 1000000;
        elimTimes[i] = elimTime;

        i++;
    }

    cout << "~~~~~~~~~~~~~~~" << endl;
    cout << "Order of elimination:" << endl;

    vector<Destination>::iterator itr;
    for (itr = eliminatedDestinations.begin(); itr != eliminatedDestinations.end(); ++itr) {
        itr->printPosition();
        itr->printDestinationName();
    }

    cout << "- - - - - - - - - - - - - - -" << endl;
    vectorJosephus.printAllDestinations();
    cout << "- - - - - - - - - - - - - - -" << endl;

    clock_t cpuEnd = clock();

    double cpuTime = (cpuEnd - cpuStart) / CLOCKS_PER_SEC;
    cpuTime = cpuTime * 1000;

    double elimTimesSum, elimTimeAvg;
    for (int i = 0; i < sizeof(elimTimes) / sizeof(double); i++) {
        elimTimesSum += elimTimes[i];
    }

    elimTimeAvg = elimTimesSum / (sizeof(elimTimes) / sizeof(double));

     if (outfile.is_open()) {
        outfile << "N=" << N << ",M=" << M << endl;
        outfile << "Total CPU time: " << cpuTime << " milliseconds" << endl;
        outfile << "Avg elimination time: " << elimTime << " microseconds" << endl;
        outfile << endl << endl;
    }
}