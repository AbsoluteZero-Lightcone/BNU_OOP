/**
  ******************************************************************************
  * @file    ExpressionElement_Base.h
  * @author  Zhang Yifa 202311998186
  * @version V1.1.0
  * @date    2024-05-20
  * @brief   ExpressionElement_Base ≥ÈœÛ¿‡
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EXPRESSIONELEMENT_BASE_H
#define __EXPRESSIONELEMENT_BASE_H

/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class ExpressionElement_Base {
public:
	ExpressionElement_Base() {}
	virtual ~ExpressionElement_Base() {}
	virtual void fetch(string& s) = 0;
};
using Element = ExpressionElement_Base;

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const ExpressionElement_Base& e);

#endif /* !__EXPRESSIONELEMENT_BASE_H */
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
