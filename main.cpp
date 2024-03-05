#include <iostream>
#include <string>
using namespace std;

#include "date.h"

void output(int year, int month, int day) {
    cout << year << month << day;
}
void output(string s){
    cout << s << endl;
}
int main(){
    // system("chcp 65001");
    Date today(2024,3,5);
    today.showDate();
    today++;
    today.showDate();
    today++++++++;
    today.showDate();
    system("pause");
    return 0;
}