/**
  ******************************************************************************
  * @file    util.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-25
  * @brief   util
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __UTIL_H
#define __UTIL_H

/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;
#include "Fish.h"
/* Exported functions ------------------------------------------------------- */
int random(int range);
bool isContinue();
void showFed(Fish* fed);
void showList(Fish** fish, int length);

#endif /* !__UTIL_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
