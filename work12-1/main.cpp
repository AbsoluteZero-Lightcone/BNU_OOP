/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-23
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
#include <vector>
#include <list>

using namespace std;
#include <chrono>
using namespace chrono;

/**
  * @brief Լɪ������
  * @param m ÿ�γ��е�����
  * @param n ������
  * @retval �������ʣ�µ��˵ı��
  */
template<typename CONTAINER_T>
int yuesefu(int m, int n) {
	CONTAINER_T container;
	for (int i = 1; i <= n; i++)
		container.push_back(i);
	typename CONTAINER_T::iterator it = container.begin();
	while (container.size() > 1) {
		for (int i = 1; i < m; i++) {
			it++;
			if (it == container.end()) it = container.begin();
		}
		it = container.erase(it);
		if (it == container.end()) it = container.begin();
	}
	return container.front();
}


int main() {
	int m, n;
	steady_clock::time_point begin, end;
	duration<double> time;
	int result1, result2;

	cout << "������ÿ�γ��е�����m��";
	cin >> m;
	cout << "������������n��";
	cin >> n;


	begin = steady_clock::now();
	result1 = yuesefu<list<int>>(m, n);
	end = steady_clock::now();
	time = duration_cast<duration<double>>(end - begin);
	cout << "list: " << time.count()*1e3 << "us" << endl;
	cout << "���ʣ�µ��˵ı���ǣ�" << result1 << endl;
	
	begin = steady_clock::now();
	result2 = yuesefu<vector<int>>(m, n);
	end = steady_clock::now();
	time = duration_cast<duration<double>>(end - begin);
	cout << "vector: " << time.count()*1e3 << "ms" << endl;
	cout << "���ʣ�µ��˵ı���ǣ�" << result2 << endl;

	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
