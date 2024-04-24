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

int main()
{
    time_t now;
    time(&now);
    int n;
    srand(now);
    for (int i = 0; i < 50; i++)
    {
        n = rand();
        cout << now << " " << n << endl;
    }
    return 0;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
