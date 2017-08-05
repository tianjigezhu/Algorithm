test: test.o CSingleLinkList.o
	g++ -o test test.o CSingleLinkList.o

test.o: test.cpp CSingleLinkList.hpp
	g++ -o test.o -c test.cpp

CSingleLinkList.o: CSingleLinkList.cpp CSingleLinkList.hpp ISingleLinkList.hpp Type.hpp
	g++ -o CSingleLinkList.o -c CSingleLinkList.cpp