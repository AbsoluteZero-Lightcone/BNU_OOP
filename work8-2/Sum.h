/**
  ******************************************************************************
  * @file    Sum.h
  * @author  张亦法
  * @date    2024-04-19
  * @brief   相加接口抽象基类
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