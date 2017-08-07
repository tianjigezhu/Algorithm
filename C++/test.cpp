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
	for (int index = 0; index < 10; ++index) {
		singleLinkList.insertFirst(index);
	}

	int count = singleLinkList.length();
	for (int index = 0; index < count; ++index) {
		cout << singleLinkList.valueAt(index) << endl;
	}

	return 0;
}