/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-23
  * @brief   work12-2 的第二种方法
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
int main() {
	system("python -c \"word,dic = [''],{};list = [[word.__setitem__(0,input('word:')),print(dic) if word[0]=='QUIT'else print(end=''),exit() if word[0]=='QUIT'else print(end=''),dic.__setitem__(word[0],dic[word[0]]+1)if word[0] in dic else dic.__setitem__(word[0],1),]for i in iter(int,1)]\"");
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
