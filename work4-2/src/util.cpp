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
  * @brief 取随机数
  */
int random(int range) {
	time_t now;
	time(&now);
	srand(now);
	return rand() % range;
}
/**
  * @brief 询问是否继续
  */
bool isContinue() {
	string command;
	cout << "您要结束养鱼吗？(Y/N) : ";
	cin >> command;
	if (command == "y" || command == "Y") {
		cout << "程序结束。" << endl;
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
  * @brief 打印第几个被喂了
  */
void showFed(Fish* fed) {
	cout << "第" << Fish::s_nCurrentDay << "天："
		<< fed->getName() << " 吃到了食物" << endl;
}

/**
  * @brief 打印所有活鱼
  */
void showList(Fish** fish, int length) {
	cout << "还有" << Fish::s_nAlive
		<< "条活着的鱼，它们的情况是：" << endl
		<< "名字\t\t颜色\t\t体重\t\t上次吃食时间" << endl;
	for (int i = 0; i < length; i++)
		if (fish[i]->isAlive())
			cout << *fish[i];
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
