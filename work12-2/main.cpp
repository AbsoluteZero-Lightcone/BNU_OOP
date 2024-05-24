/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-23
  * @brief   work12-2 的常规方法
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
using namespace std;
#include <map>
#include <set>
#include <string>

/**
  * @brief 使用multiset实现
  * @retval	None
  */
void dic_multiset() {
	multiset<string> dic;
	string word;
	while (true) {
		cout << "word: "; 
		cin >> word;
		if (word == "QUIT")break;
		cout << (dic.count(word) ? "出现过" : "没出现过") << " 曾经出现次数: " << dic.count(word) << endl;
		dic.insert(word);
	}
}

/**
  * @brief 使用map实现
  * @retval None
  */
void dic_map() {
	map<string, int> dic;
	string word;
	while (true) {
		cout << "word: ";
		cin >> word;
		if (word == "QUIT")break;
		cout << (dic[word] ? "出现过" : "没出现过") << " 曾经出现次数: " << dic[word] << endl;
		dic[word]++;
	}
}

int main() {
	cout << "-------使用map实现--------" << endl;
	dic_map();
	cout << "-----使用multiset实现-----" << endl;
	dic_multiset();
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
