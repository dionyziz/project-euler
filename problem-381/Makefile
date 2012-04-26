381: 381.o euclidean.o
	g++ -O2 381.o euclidean.o

euclidean.o: euclidean.cpp euclidean.h
	g++ -O2 -c euclidean.cpp

381.o: 381.cpp euclidean.h
	g++ -O2 -c 381.cpp

clean:
	rm *.o a.out
