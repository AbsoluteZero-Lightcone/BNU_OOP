/**
  ******************************************************************************
  * @file    Sum.h
  * @author  ���෨
  * @date    2024-04-19
  * @brief   ��ӽӿڳ������
  ******************************************************************************
  */
#ifndef __SUM_H
#define __SUM_H

class Sum {
public:
	Sum() {}
	virtual ~Sum() {}
	virtual void Show() = 0;
	virtual void Add(Sum* num) = 0;
};

#endif // !__SUM_H