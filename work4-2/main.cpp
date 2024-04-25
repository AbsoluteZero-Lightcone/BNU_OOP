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

int random() {
	time_t now;
	time(&now);
	srand(now);
	return rand();
}

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

int main() {
	cout << "您要养几条鱼（N>=5）: ";
	int N;
	cin >> N;
	Fish** fish = new Fish * [N];
	string name, color;
	for (int i = 0; i < N; i++) {
		cout << "请输入第" << i + 1 << "条鱼的名字、颜色：";
		cin >> name >> color;
		fish[i] = new Fish(name, color);
	}
	cout << "开始养鱼了！" << endl;
	do {
		Fish::s_nCurrentDay++;
		cout << "第" << Fish::s_nCurrentDay << "天：";

		int countingdown = random() % Fish::s_nAlive; // countingdown: 0~(Fish::s_nAlive-1)
		int feed = 0;
		for (int i = 0; i < N; i++)
			if (fish[i]->isAlive()) { // 不给死了的喂食
				if (countingdown == 0) {
					fish[i]->update(true);
					feed = i; // 第几个被喂了
				}
				else {
					fish[i]->update(false);
				}
				countingdown--;
			}
		if (Fish::s_nAlive == 0) {
			cout << "第" << Fish::s_nCurrentDay << "天："
				<< fish[feed]->getName() << " 吃到了食物" << endl;
			// 如果恰好死的那天是十的倍数那么不打印空表格，而是使用常规输出
			cout << "抱歉，所有的鱼都死了，养鱼失败了，程序结束。" << endl;
			break;
		}
		if (Fish::s_nCurrentDay % 10 == 0) {
			cout << "还有" << Fish::s_nAlive
				<< "条活着的鱼，它们的情况是：" << endl
				<< "名字\t\t颜色\t\t体重\t\t上次吃食时间" << endl;
			for (int i = 0; i < N; i++)
				if (fish[i]->isAlive())
					cout << *fish[i];
		}
		else cout << "第" << Fish::s_nCurrentDay << "天：" 
			<< fish[feed]->getName() << " 吃到了食物" << endl;

	} while (isContinue());
	
	return 0;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
