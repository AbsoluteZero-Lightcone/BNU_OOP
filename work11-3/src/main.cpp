/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-16
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */
#include <iostream>
#include <string>
using namespace std;
#include "Stack.h"


template<unsigned N>
bool isValidBrackets(const char(&s)[N]) {
	int cur = 0;
	for (int i = 0; i < N-1; i++){
		if (s[i] == '(')
			cur++;
		else if (s[i] == ')')
			cur--;
	}
	return !cur;
}


template<unsigned N>
int (&formOrder(const char (& s)[N]))[N-1] {
	static int order[N-1];
	int cur = 0;
	for (int i = 0; i < N-1; i++) {
		if (s[i] == '(') {
			cur++;
			order[i] = -1;
		}
		else if (s[i] == ')') {
			cur--;
			order[i] = -1;
		}
		else {
			order[i] = cur;
		}
	}
	return (int(&)[N-1])order;
}

template<class T,unsigned N>
void printArray(T (&arr)[N]) {
	cout << "{";
	for (int i = 0; i < N; i++) {
		if (i)cout << ",";
		cout << arr[i];
	}
	cout << "}";
	cout << endl;
}

template<unsigned N>
double eval(string s) {
	
}

int main() {
	cout << isValidBrackets("((((146+156))*(12-12)/3))") << endl;
	printArray(formOrder("((((146+156))*(12-12)/3))"));
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
