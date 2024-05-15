/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-15
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
#include <string>
using namespace std;

#include "Person.h"

template<typename T, int N>
int find(const T(&arr)[N], const T target) {
	for (int i = 0; i < N; i++) {
		if (arr[i] == target) {
			return i;
		}
	}
	return -1;
}

int main() {
	int a[10] = { 1,3,5,7,9,2,4,6,8,10 };    //分别查找0, 4
	char b[] = "Beijing Normal University";  //分别查找 字符‘m’ ‘i’  ‘z’
	string c[] = { "BNU","welcome","Beijing","abc","1234" }; //分别查找"ok"  "abc"
	Person d[] = {
		Person("wangwei",20),
		Person("liuli",30),
		Person("zhangsan",40),
		Person("zhaoming",20)
	};	//分别查找Person（"liuli", 30）, Person（"liuli", 20）
	int index;
	index = find(a, 0); if (index != -1)cout << "a[" << index << "] = " << a[index] << endl;else cout << "Not Found." <<endl;
	index = find(a, 4); if (index != -1)cout << "a[" << index << "] = " << a[index] << endl;else cout << "Not Found." <<endl;
	index = find(b, 'm'); if (index != -1)cout << "b[" << index << "] = " << b[index] << endl;else cout << "Not Found." <<endl;
	index = find(b, 'i'); if (index != -1)cout << "b[" << index << "] = " << b[index] << endl;else cout << "Not Found." <<endl;
	index = find(b, 'z'); if (index != -1)cout << "b[" << index << "] = " << b[index] << endl;else cout << "Not Found." <<endl;
	index = find<string>(c,"ok");if(index!=-1)cout << "c[" << index << "] = " << c[index] << endl;else cout << "Not Found." <<endl;
	index = find<string>(c,"abc");if(index!=-1)cout << "c[" << index << "] = " << c[index] << endl;else cout << "Not Found." <<endl;
	index = find(d, Person("liuli", 30)); if (index != -1)cout << "d[" << index << "] = " << d[index] << endl;else cout << "Not Found." <<endl;
	index = find(d, Person("liuli", 20)); if (index != -1)cout << "d[" << index << "] = " << d[index] << endl; else cout << "Not Found." << endl;

	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
