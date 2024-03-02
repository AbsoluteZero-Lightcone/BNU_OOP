#include <iostream>
using namespace std;

#include "inline_test.h"

int main(){
    int i = 1;
    inline_test it1(i,temp(1));// 匿名对象
    cout << 1 <<endl;

    return 0;
}