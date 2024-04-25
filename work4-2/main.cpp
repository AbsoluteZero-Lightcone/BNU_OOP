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
		cout << "您要养几条鱼（N>=5）: ";
		cin >> N;
		if (N >= 5)break;
		cerr << "请输入不小于5的整数" << endl;
	}
	Fish** fish = new Fish * [N];
	string name, color;
	for (int i = 0; i < N; i++) {
		cout << "请输入第" << i + 1 << "条鱼的名字、颜色：";
		cin >> name >> color;
		fish[i] = new Fish(name, color);
	}
	/* ----------------------------------------- Input */
	cout << "开始养鱼了！" << endl;
	do {
		/* Update ---------------------------------------- */
		Fish::s_nCurrentDay++;
		cout << "第" << Fish::s_nCurrentDay << "天：";
		int feed = 0, countingdown = random(Fish::s_nAlive);
		for (int i = 0; i < N; i++)
			if (fish[i]->isAlive()) { // 不给死了的喂食
				if (countingdown == 0) {
					fish[i]->update(true);
					feed = i; // 第几个被喂了
				}
				else fish[i]->update(false);
				countingdown--;
			}
		/* ---------------------------------------- Update */
		/* Print ----------------------------------------- */
		if (Fish::s_nAlive == 0) {
			showFed(fish[feed]); // 如果恰好死的那天是十的倍数那么不打印空表格，而是使用常规输出
			cout << "抱歉，所有的鱼都死了，养鱼失败了，程序结束。" << endl;
			break;
		}
		if (Fish::s_nCurrentDay % 10 == 0)showList(fish, N);
		else showFed(fish[feed]);
		/* ----------------------------------------- Print */
	} while (isContinue());
	return 0;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
