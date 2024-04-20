/**
  ******************************************************************************
  * @file    util.cpp
  * @author  张亦法 202311998186
  * @date    2024-04-19
  * @brief   实用工具库
  ******************************************************************************
  */
#include <cmath>
#include "Point.h"
  /**
	* @brief  求两点之间的距离
	* @param  p1: Point类型引用
	* @param  p2: Point类型引用
	* @retval 两点之间的距离
	*/
double getLength(const Point& p1, const Point& p2) {
	return sqrt(
		(p1.m_dX - p2.m_dX) * (p1.m_dX - p2.m_dX) +
		(p1.m_dY - p2.m_dY) * (p1.m_dY - p2.m_dY)
	);
}

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
