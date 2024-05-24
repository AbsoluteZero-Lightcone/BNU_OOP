/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-23
  * @brief   work12-2 �ĳ��淽��
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
using namespace std;
#include <map>
#include <set>
#include <string>

/**
  * @brief ʹ��multisetʵ��
  * @retval	None
  */
void dic_multiset() {
	multiset<string> dic;
	string word;
	while (true) {
		cout << "word: "; 
		cin >> word;
		if (word == "QUIT")break;
		cout << (dic.count(word) ? "���ֹ�" : "û���ֹ�") << " �������ִ���: " << dic.count(word) << endl;
		dic.insert(word);
	}
}

/**
  * @brief ʹ��mapʵ��
  * @retval None
  */
void dic_map() {
	map<string, int> dic;
	string word;
	while (true) {
		cout << "word: ";
		cin >> word;
		if (word == "QUIT")break;
		cout << (dic[word] ? "���ֹ�" : "û���ֹ�") << " �������ִ���: " << dic[word] << endl;
		dic[word]++;
	}
}

int main() {
	cout << "-------ʹ��mapʵ��--------" << endl;
	dic_map();
	cout << "-----ʹ��multisetʵ��-----" << endl;
	dic_multiset();
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
