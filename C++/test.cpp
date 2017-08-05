#include "CSingleLinkList.hpp"

#include <iostream>

using Paradise::Algorithm::CSingleLinkList;
using Paradise::Type::EBool;

using std::cout;
using std::endl;

namespace a
{
template<class T>
struct B
{
	T c;
};
}

int main(int argc, char *argv[])
{
	Paradise::Algorithm::CSingleLinkList<int> singleLinkList;
	//singleLinkList.insertFirst(10);
	//cout << singleLinkList.front() << endl;
	a::B<int> d;
	d.c = 10;
	cout << d.c << endl;

	return 0;
}