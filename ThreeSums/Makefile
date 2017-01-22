all: ThreeSums

ThreeSums: List.o ThreeSums.o
	g++ List.o ThreeSums.o -o ThreeSums

ThreeSums.o: ThreeSums.cpp
	g++ -c ThreeSums.cpp -o ThreeSums.o

List.o: List.h List.cpp
	g++ -c List.cpp -o List.o

clean:
	rm -f *.o $@