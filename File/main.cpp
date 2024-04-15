#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ofstream outfile("1.txt");
	string s;
	for (int i = 0; i < 5; i++) {
		cin >> s;
		outfile << s << " ";
	}
	outfile.close();
	ifstream infile("1.txt");
	string ss;
	do {
		infile >> ss;
		cout << ss<<" ";
	} while (!infile.eof());
	return 0;
}