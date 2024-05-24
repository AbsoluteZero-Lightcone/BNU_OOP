/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V2.0.0
  * @date    2024-05-23
  * @brief   work12-2 的第二种方法
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
int main() {
	system("python -c \"word, dic = [''], {}; temp = [[word.__setitem__(0, input('word:')), exit() if word[0] == 'QUIT' else 0, print('出现过 曾经出现次数: ', dic[word[0]]) if word[0] in dic else print('没出现过 曾经出现次数: 0'), dic.__setitem__(word[0], (dic[word[0]] + 1) if word[0] in dic else 1)] for i in iter(int, 1)]\"");
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
