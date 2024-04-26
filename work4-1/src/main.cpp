/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.2.0
  * @date    2024-04-23
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
#include <string>
#include <cmath>
#include <cstdint>
using namespace std;
#include "Deposit.h"

int main() {
	Deposit bank[] = {
		Deposit("����","123456",10000,Date(2020,5,1)),
		Deposit("����","112233",20000,Date(2020,7,1)),
		Deposit("����","111111",15000,Date(2021,10,1)),
		Deposit("����","222222",58000,Date(2021,2,1)),
		Deposit("����","888888",50000,Date(2022,1,1))
	};
	Deposit::setInterest(0.005);
	Date current(2022, 7, 1);
	for (int i = 0; i < 6; i++)	{
		cout << endl;
		cout << current <<"����������˻�����Ϣ" << endl;
		if (current.getMonth() == 8)// �³�
			Deposit::setInterest(0.004);
		cout << "�˺�\t����\t����\t���\t������\t����ʱ��" << endl;
		for (int j = 0; j < 5; j++) {
			cout << bank[j] << endl;// �³���Ϣ
			bank[j].update();// ������Ϣ
		}
		current.toNextMonth();
	}

	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
