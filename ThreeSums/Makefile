all: clean ThreeSums
	./ThreeSums.exe

ThreeSums: List.o ThreeSums.o
	g++ List.o ThreeSums.o -o ThreeSums

ThreeSums.o: ThreeSums.cpp
	g++ -Wall -c ThreeSums.cpp -o ThreeSums.o

List.o: List.h List.cpp
	g++ -Wall -c List.cpp -o List.o

clean:
	rm -f *.o $@