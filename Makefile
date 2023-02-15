prog:	main.o TestListMyJosephus.o TestVectorMyJosephus.o ListMyJosephus.o VectorMyJosephus.o
			g++ -g main.o TestListMyJosephus.o TestVectorMyJosephus.o ListMyJosephus.o VectorMyJosephus.o -o PA2

main.o:	main.cpp Destination.h ListMyJosephus.h VectorMyJosephus.h
			g++ -c -g -Wall -std=c++11 main.cpp

ListMyJosephus.o: ListMyJosephus.cpp Destination.h ListMyJosephus.h
			g++ -c -g -Wall -std=c++11 ListMyJosephus.cpp

VectorMyJosephus.o: VectorMyJosephus.cpp Destination.h VectorMyJosephus.h
			g++ -c -g -Wall -std=c++11 VectorMyJosephus.cpp

TestListMyJosephus.o:	TestListMyJosephus.cpp ListMyJosephus.h Destination.h
			g++ -c -g -Wall -std=c++11 TestListMyJosephus.cpp

TestVectorMyJosephus.o:	TestVectorMyJosephus.cpp VectorMyJosephus.h Destination.h
			g++ -c -g -Wall -std=c++11 VectorMyJosephus.cpp

clean:
			-rm *.o

run:
			@./PA2