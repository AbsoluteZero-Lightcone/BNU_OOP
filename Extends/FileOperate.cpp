#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void data_format() {
    ifstream infile("shape.csv");
    ofstream outfile("shape.txt");
    char temp[50] = { 0 };
    char outtemp[50] = { 0 };
    do
    {
        for (int i = 0; i < 50; i++)
        {
            temp[i] = 0;
            outtemp[i] = 0;
        }
        infile.getline(temp, 49);
        for (int i = 0; i < strlen(temp); i++)
            if (temp[i] != ',')
                outtemp[i] = temp[i];
            else
                outtemp[i] = ' ';
        outfile << outtemp << endl;
    } while (!infile.eof());
    infile.close();
    outfile.close();
}