/**
  ******************************************************************************
  * @file    ExpressionElement_Base.cpp
  * @author  Zhang Yifa 202311998186
  * @version V2.1.0
  * @date    2024-05-20
  * @brief   ExpressionElement_Base
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "ExpressionElement_Base.h"
#include "ExpressionDouble.h"
#include "ExpressionOperator.h"
#include "ExpressionBrackets.h"

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const ExpressionElement_Base& e) {
	if (typeid(e) == typeid(ExpressionDouble)) {
		out << dynamic_cast<const ExpressionDouble&>(e);
	}
	else if (typeid(e) == typeid(ExpressionOperator)) {
		out << dynamic_cast<const ExpressionOperator&>(e);
	}
	else if(typeid(e) == typeid(ExpressionBrackets)){
		out << dynamic_cast<const ExpressionBrackets&>(e);
	}
	return out;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
