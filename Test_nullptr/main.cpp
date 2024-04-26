#include <iostream>
using namespace std;

int main() {
	int* p = new int(1);
	cout << NULL << (int)NULL << endl;
	cout <<p<<" " << (int)p << endl;
	delete p;
	cout << p<<" " << (int)p << endl;
	if (!p)delete p;
	cout << p<<" " << (int)p << endl;
	if (p)delete p;
	cout << p<<" " << (int)p << endl;
	return 0;
}