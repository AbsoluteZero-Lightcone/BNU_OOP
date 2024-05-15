/**
  ******************************************************************************
  * @file    Stack.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-15
  * @brief   Stack class
  * @encode  GB2312
  ******************************************************************************
  */

  /* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STACK_H
#define __STACK_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* Class ---------------------------------------------------------------------*/
template<class T>
class Stack {
private:
	int m_nSize;
	T* m_ptrData;
public:
	// Constructors & Deconstructor
	Stack();
	Stack(const Stack<T>& source);
	~Stack();

	// Getters
	T& operator[](int t_nIndex)const;
	T& at(int t_nIndex)const;
	T& front()const;
	T& back()const;
	T& top()const;
	T& bottom()const;
	T* data()const;
	int size()const;
	bool isEmpty()const;

	// Operations
	T pop();
	Stack<T>& push(const T& t_data);
	Stack<T>& operator>>(T& pop);
	Stack<T>& operator<<(const T& push);

	void clear();
	Stack<T>& resize(int t_nSize);

	void operator=(const Stack<T>& source);

	operator T* () const;

	template<class T> friend istream& operator>>(istream& in, Stack<T>& source);
	template<class T> friend ostream& operator<<(ostream& out, const Stack<T>& source);
	template<class T> friend bool operator==(const Stack<T>& n1, const Stack<T>& n2);
	template<class T> friend bool operator!=(const Stack<T>& n1, const Stack<T>& n2);
};

/* Exported functions ------------------------------------------------------- */
template<class T>
istream& operator>>(istream& in, Stack<T>& source);
template<class T>
ostream& operator<<(ostream& out, const Stack<T>& source);
template<class T>
bool operator==(const Stack<T>& n1, const Stack<T>& n2);
template<class T>
bool operator!=(const Stack<T>& n1, const Stack<T>& n2);

#include "Stack_Template.h"

#endif /* !__STACK_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
