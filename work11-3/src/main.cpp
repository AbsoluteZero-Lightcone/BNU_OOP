/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V2.0.0
  * @date    2024-05-16
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */
#include <iostream>
#include <string>
using namespace std;

#include "Expression.h"

string tests[] = {
	// verified functions:
	"1 + (2.15) * 3 / (2.120001*(1-6))+2.1 * (3 /2.12)*1-6",// һ��ı��ʽ
	"123",// ��������
	"((((()))))" ,// �жϿ�����
	"-1+2",
	"1+(-2)",// ������ -1+2 �� 1+(-2)
	"1/(2-2)"// ������
	"2(3+4)",// �˺�ʡ�Ե�����Ƿ� 2(3+4)
	"2^3",// ������֧��
	"2%3",// ����ȡ������fmod֧��

	// todos:
	"1++++----2",// todo ��鲻�Ϸ��������Ӽ���
	"sin(123)",// todo ����ʽ����֧��
	"|-12|",// todo �������ţ�����ֵ��
	"12!",// todo ���õ�Ŀ����(�׳�����)
	"E^(i*Pi)",// todo ��ѧ����
	"ans+1",// todo ���书��
};

template<class T, unsigned N>
void test(T(&tests)[N]) {
	for (int i = 0; i < N; i++) {
		cout << "Test " << i << ": " << tests[i] << endl;
		try {
			Expression e(tests[i]);

			cout << "-- Calculating process ---------------------------------------------------------" << endl;
			double res = Expression::Process(e);
			cout << endl << "------------------------------------------------------- Calculation completed --" << endl ;
			cout << endl << ">>> " << e << " = " << res << endl << endl;
		}
		catch (const char* err) {
			cerr << endl << "[Error] " << err << endl << endl;
		}
	}

}

int main() {
	test(tests);
	cout << "Supported operators: + - * / ^ %" << endl;
	do {
		try {
			string s;
			cout << "Input an expression: " << endl << ">>> ";
			cin >> s;
			Expression e(s);
			cout << endl << "-- Calculating process ---------------------------------------------------------" << endl << endl;
			double res = Expression::Process(e);
			cout << endl << "------------------------------------------------------- Calculation completed --" << endl;
			cout << endl << ">>> " << e << " = " << res << endl << endl;
		}
		catch (const char* err) {
			cerr << endl << "[Error] " << err << endl << endl;
		}
	} while (true);
	return 0;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
