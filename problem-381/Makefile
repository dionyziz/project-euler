381: 381.o euclidean.o millerrabin.o
	g++ -O3 381.o euclidean.o millerrabin.o

euclidean.o: euclidean.cpp euclidean.h
	g++ -O3 -c euclidean.cpp

millerrabin.o: millerrabin.cpp millerrabin.h
	g++ -O3 -c millerrabin.cpp

381.o: 381.cpp euclidean.h
	g++ -O3 -c 381.cpp

clean:
	rm -rf *.o a.out
