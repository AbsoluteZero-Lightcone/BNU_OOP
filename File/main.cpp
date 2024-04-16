#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void data_format() {
	ifstream infile("shape.csv",ios::in);
	ofstream outfile("shape.txt",ios::out);
	string temp;
	while (!infile.eof()) {
		getline(infile, temp);
		for (int i = 0; i < temp.length(); i++)
			if (temp[i] == ',')
				temp[i] = ' ';
		outfile << temp << endl;
	}
	infile.close();
	outfile.close();
}

int main() {
	system("chcp 65001");

	data_format();

	ifstream shape("shape.txt", ios::in);
	while (!shape.eof()) {
		string s;
		shape >> s;
		cout << s << " ";
	}
	cout << endl;
	shape.close();
	cout << "--------------------" << endl;
	ofstream outfile("1.txt");
	string s;
	for (int i = 0; i < 5; i++) {
		cin >> s;
		outfile << s << "    ";
	}
	outfile.close();
	ifstream infile("1.txt");
	string ss;
	while (!infile.eof()){// 会一直读到最后，最后的空格也会进一次循环
		if(infile >> ss)// 判断是否接收到内容
			cout << ss<<" ";
	}
	infile.close();


	return 0;
}