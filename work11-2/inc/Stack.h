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
	Stack(int t_nSize, T* t_ptrData);
	Stack(const Stack<T>& source);
	~Stack();

	// Getter & Setter
	int get_nSize()const;
	void set_nSize(int t_nSize);
	T* get_ptrData()const;
	void set_ptrData(T* t_ptrData);
	void set(int t_nSize, T* t_ptrData);

	
	void operator=(const Stack<T>& source);

	friend ostream& operator<<(ostream& out, const Stack<T>& source);
	friend bool operator==(const Stack<T>& n1, const Stack<T>& n2);
	friend bool operator!=(const Stack<T>& n1, const Stack<T>& n2);
};

/* Exported functions ------------------------------------------------------- */
template<class T>
ostream& operator<<(ostream& out, const Stack<T>& source);
template<class T>
bool operator==(const Stack<T>& n1, const Stack<T>& n2);
template<class T>
bool operator!=(const Stack<T>& n1, const Stack<T>& n2);

#endif /* !__STACK_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
