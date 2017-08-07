test: test.o
	g++ -o test test.o

test.o: test.cpp CSingleLinkList.hpp
	g++ -o test.o -c test.cpp

clean:
	rm *.o test