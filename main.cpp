#include "TestListMyJosephus.cpp"
#include "TestVectorMyJosephus.cpp"

/*
Qn 1:   Does the processor of the machine that is running the algorithms matter? 
        Will you receive the same timing statistics on every machine?

Ans:    The processor of the machine that is running the algorithms can matter,
        as different processors may have different clock speeds and architectures,
        which can affect the performance of algorithms. The timing statistics may
        not be the same on every machine due to this.

Qn 2:   Which of the two implementations (std::list vs std::vector) performs best 
        and under what conditions when implementing a variant of the Josephus problem? 
        Does it depend on the input?

Ans:    In general, std::vector is more efficient for accessing and manipulating
        elements at random positions, as opposed to std::list. However, std::list
        is more efficient for inserting or deleting elements at any position as
        it doesn't need to reorganize the elements in contiguous memory locations

        In terms of its implementation in PA2, std::vector's and std::list's 
        performance is dependent on the size of the input. If the input is relatively
        small, then either one would work well. However, if the input is very 
        large and the simulation involves multiple eliminations, then the performance 
        of the std::vector implementation will more than likely suffer due to the 
        need to constantly resize the underlying memory block. 

Qn 3:   How does the running time dependency on the parameter N compare with the
        dependency on the parameter M?

Ans:    The larger N becomes, the more elements need to be iterated through, which
        leads to a linear increase in running time. On the other hand, the running
        time for a given value of M depends on the distribution of numbers being
        eliminated.
*/

int main(void) {
    ofstream outfile("results.log");

    if (outfile.is_open()) {
        outfile << "~~List Testing~~" << endl;

        testListMyJosephus(3, 4);
        testListMyJosephus(3, 8);
        testListMyJosephus(3, 16);
        testListMyJosephus(3, 32);
        testListMyJosephus(3, 64);
        testListMyJosephus(3, 128);
        testListMyJosephus(3, 256);
        testListMyJosephus(3, 512);
        testListMyJosephus(3, 1024);
        testListMyJosephus(2, 512);
        testListMyJosephus(4, 512);
        testListMyJosephus(8, 512);
        testListMyJosephus(16, 512);
        testListMyJosephus(32, 512);
        testListMyJosephus(64, 512);
        testListMyJosephus(128, 512);
        testListMyJosephus(256, 512);

        outfile << "~~Vector Testing~~" << endl;

        testVectorMyJosephus(3, 4);
        testVectorMyJosephus(3, 8);
        testVectorMyJosephus(3, 16);
        testVectorMyJosephus(3, 32);
        testVectorMyJosephus(3, 64);
        testVectorMyJosephus(3, 128);
        testVectorMyJosephus(3, 256);
        testVectorMyJosephus(3, 512);
        testVectorMyJosephus(3, 1024);
        testVectorMyJosephus(2, 512);
        testVectorMyJosephus(4, 512);
        testVectorMyJosephus(8, 512);
        testVectorMyJosephus(16, 512);
        testVectorMyJosephus(32, 512);
        testVectorMyJosephus(64, 512);
        testVectorMyJosephus(128, 512);
        testVectorMyJosephus(256, 512);
    
    }

    
    return 0;
}