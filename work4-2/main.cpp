/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-25
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */
#include <iostream>
#include <string>
using namespace std;
#include "Fish.h"
#include "util.h"

int main() {
	/* Input ----------------------------------------- */
	int N;
	while (1) {
		cout << "��Ҫ�������㣨N>=5��: ";
		cin >> N;
		if (N >= 5)break;
		cerr << "�����벻С��5������" << endl;
	}
	Fish** fish = new Fish * [N];
	string name, color;
	for (int i = 0; i < N; i++) {
		cout << "�������" << i + 1 << "��������֡���ɫ��";
		cin >> name >> color;
		fish[i] = new Fish(name, color);
	}
	/* ----------------------------------------- Input */
	cout << "��ʼ�����ˣ�" << endl;
	do {
		/* Update ---------------------------------------- */
		Fish::s_nCurrentDay++;
		cout << "��" << Fish::s_nCurrentDay << "�죺";
		int feed = 0, countingdown = random(Fish::s_nAlive);
		for (int i = 0; i < N; i++)
			if (fish[i]->isAlive()) { // �������˵�ιʳ
				if (countingdown == 0) {
					fish[i]->update(true);
					feed = i; // �ڼ�����ι��
				}
				else fish[i]->update(false);
				countingdown--;
			}
		/* ---------------------------------------- Update */
		/* Print ----------------------------------------- */
		if (Fish::s_nAlive == 0) {
			showFed(fish[feed]); // ���ǡ������������ʮ�ı�����ô����ӡ�ձ�񣬶���ʹ�ó������
			cout << "��Ǹ�����е��㶼���ˣ�����ʧ���ˣ����������" << endl;
			break;
		}
		if (Fish::s_nCurrentDay % 10 == 0)showList(fish, N);
		else showFed(fish[feed]);
		/* ----------------------------------------- Print */
	} while (isContinue());
	return 0;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
