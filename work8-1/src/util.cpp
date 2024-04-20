/**
  ******************************************************************************
  * @file    util.cpp
  * @author  ���෨ 202311998186
  * @date    2024-04-19
  * @brief   ʵ�ù��߿�
  ******************************************************************************
  */
#include <cmath>
#include "Point.h"
  /**
	* @brief  ������֮��ľ���
	* @param  p1: Point��������
	* @param  p2: Point��������
	* @retval ����֮��ľ���
	*/
double getLength(const Point& p1, const Point& p2) {
	return sqrt(
		(p1.m_dX - p2.m_dX) * (p1.m_dX - p2.m_dX) +
		(p1.m_dY - p2.m_dY) * (p1.m_dY - p2.m_dY)
	);
}

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
