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
    return 0;
}