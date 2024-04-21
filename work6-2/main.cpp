/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-21
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
#include "AlarmClock.h"

bool isContinue();

int main() {
	// �����߶೤ʱ���װ��AlarmClock���ﲻ�Ǻܺ���
	// ��Ϊû���Ǹ�������Ҫ���һ�� һ���涨ʱ��Ͳ����� �Ĺ���
	// ���Ҫʵ�ֵĻ���ҲҪ���߶೤ʱ��ʵ��������
	// 
	// �����߶೤ʱ���������Ӧ����Ϊ�˱������һֱ�����ȡ����Э�ķ�����
	// ��ʵ����Ӧ��������֮���Ӽ����߲Ŷԣ�����ʵ������һ���ܣ�ֻ����10�룩
	do {
		int a, b, c, d, e;
		cout << "�������ʼʱ�䣨ʱ �� �룩��";
		cin >> a >> b >> c;
		cout << "����������ʱ�䣨ʱ �֣�  ��";
		cin >> d >> e;
		AlarmClock alarm(a, b, c, d, e);
		cout << "�������ʱʱ������ �룩  ��";
		cin >> a >> b;
		Clock current(0, 0, 0);
		Clock target(0, a, b);
		while (current < target) {
			current++;
			cout << alarm << "\r";
			Sleep(1000);
			cout << "                         \r";
			alarm.Tick();
		}
	} while (isContinue());

	return 0;
}

bool isContinue() {
	while (1) {
		cout << "��ʱ��������Ҫ������Y/N����";
		char command;
		cin >> command;
		if (command == 'Y' || command == 'y')return 1;
		else if (command == 'N' || command == 'n')return 0;
		else cout << "Invalid Command" << endl;
	}
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
