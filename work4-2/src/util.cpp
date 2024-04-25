/**
  ******************************************************************************
  * @file    util.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-25
  * @brief   util
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "util.h"

/* Exported functions ------------------------------------------------------- */
/**
  * @brief ȡ�����
  */
int random(int range) {
	time_t now;
	time(&now);
	srand(now);
	return rand() % range;
}
/**
  * @brief ѯ���Ƿ����
  */
bool isContinue() {
	string command;
	cout << "��Ҫ����������(Y/N) : ";
	cin >> command;
	if (command == "y" || command == "Y") {
		cout << "���������" << endl;
		return 0;
	}
	else if (command == "n" || command == "N") {
		return 1;
	}
	else {
		cerr << "Invalid command." << endl;
		return isContinue();
	}
}

/**
  * @brief ��ӡ�ڼ�����ι��
  */
void showFed(Fish* fed) {
	cout << "��" << Fish::s_nCurrentDay << "�죺"
		<< fed->getName() << " �Ե���ʳ��" << endl;
}

/**
  * @brief ��ӡ���л���
  */
void showList(Fish** fish, int length) {
	cout << "����" << Fish::s_nAlive
		<< "�����ŵ��㣬���ǵ�����ǣ�" << endl
		<< "����\t\t��ɫ\t\t����\t\t�ϴγ�ʳʱ��" << endl;
	for (int i = 0; i < length; i++)
		if (fish[i]->isAlive())
			cout << *fish[i];
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
