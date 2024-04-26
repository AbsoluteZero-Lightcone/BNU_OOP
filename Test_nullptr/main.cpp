#include <iostream>
using namespace std;

int main() {
	int* p = new int[10] {};
	cout << "NULL = "<<NULL << endl;
	cout << "nullptr = "<< (int)nullptr << endl;
	cout << "p = " << p << endl;
	cout << " (!p) = " <<(!p) << endl;
	cout <<  " (!!p) = " << (!!p) << endl;
	cout <<  " (p != nullptr)  = " << (p != nullptr) << endl;
	delete[] p, cout << "delete[] p" << endl;
	cout << "p = " << p << endl;
	cout << " (!p) = " << (!p) << endl;
	cout << " (!!p) = " << (!!p) << endl;
	cout << " (p != nullptr)  = " << (p != nullptr) << endl;
	return 0;
}