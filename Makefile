prog:	main.o TestListMyJosephus.o TestVectorMyJosephus.o
			g++ -g main.o TestListMyJosephus.o TestVectorMyJosephus.o -o PA2

main.o:	main.cpp Destination.h ListMyJosephus.h VectorMyJosephus.h
			g++ -c -g -Wall -std=c++11 main.cpp

TestListMyJosephus.o:	TestListMyJosephus.cpp ListMyJosephus.h Destination.h
			g++ -c -g -Wall -std=c++11 TestListMyJosephus.cpp

TestVectorMyJosephus.o:	TestVectorMyJosephus.cpp VectorMyJosephus.h Destination.h
			g++ -c -g -Wall -std=c++11 VectorMyJosephus.cpp

clean:
			-rm *.o

run:
			@./PA2