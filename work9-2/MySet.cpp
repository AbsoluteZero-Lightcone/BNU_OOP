/**
  ******************************************************************************
  * @file    MySet.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-25
  * @brief   MySet class
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "MySet.h"

/* Constructors & Deconstructor --------------------------------------------- */
/**
  * @brief 无参构造函数，创建集合，将元素个数设为0.
  * @param None
  */
MySet::MySet() :_count(0) {}
MySet::MySet(const MySet& source) :_count(source._count) {
	for (int i = 0; i < _count; i++) {
		_array[i] = source._array[i];
	}
}

/* Exported functions ------------------------------------------------------- */
/**
  * @brief 重载下标运算符
  */
const int& MySet::operator[](unsigned i)const {
	// 这里返回的是const int& 但作业里要求是返回int&，有以下两点理由：
	// 1.这里返回int&引用相当危险，相当于直接暴露了类的私有成员，
	//   通过返回到类外的引用修改集合元素时，无法检查集合内元素的合法性
	// 2.使用const修饰的对象无法使用非const的成员函数
	if (i >= 0 && i < _count) {
		return _array[i];
	}
	else throw "Index Error.";
}

/**
  * @brief 判断整数x是否是集合的元素
  * @param int x
  * @retval bool
  */
bool MySet::IsInSet(int x) const {
	for (int i = 0; i < _count; i++)
		if (x == _array[i])
			return true;
	return false;
}

void MySet::append(int n) {
	if (!IsInSet(n)) {
		_array[_count] = n;
		_count++;
		return;
	}else throw "有重复的元素";
}

/**
  * @brief 类内重载赋值运算符
  */
void MySet::operator=(const MySet& source) {
	_count = source._count;
	for (int i = 0; i < _count; i++) {
		_array[i] = source._array[i];
	}
}

/**
  * @brief 两个集合对象的加法运算”+”，含义是合并两个集合
  */
MySet MySet::operator+(const MySet& n2) const {
	MySet temp(*this);
	// n2 用值传递更方便一些，不用创建临时对象
	// 但是作业要求是传常引用，多比值传递多一步引用，也大差不差
	for (int i = 0; i < n2._count; i++)
		if (!temp.IsInSet(n2._array[i]))
			temp.append(n2._array[i]);
	return temp;
}

/**
  * @brief 两个集合对象的减法运算”-”，含义是求出集合1中的不属于集合2的元素
	各操作的要求请参看程序注释。
  */
MySet MySet::operator-(const MySet& n2) const {
	MySet temp;
	for (int i = 0; i < _count; i++)
		if (!n2.IsInSet(_array[i]))
			temp.append(_array[i]);
	return temp;
}

/**
  * @brief 集合的“前置++”运算，含义是将集合中的每一个元素自增1（前置自增）
  */
MySet& MySet::operator++() {
	for (int i = 0; i < _count; i++)
		_array[i]++;
	return *this;
}

/**
  * @brief 集合的“后置++”运算，含义是将集合中的每一个元素自增1（后置自增）
  */
MySet MySet::operator++(int) {
	MySet temp(*this);
	++*this;
	return temp;
}

/**
  * @brief 友元：集合的“前置--”运算，含义是将集合中的每一个元素自减1（前置自减）
  */
MySet& operator--(MySet& source) {
	for (int i = 0; i < source._count; i++)
		source._array[i]--;
	return source;
}

/**
  * @brief 友元：集合的“后置--”运算，含义是将集合中的每一个元素自减1（后置自减）
  */
MySet operator--(MySet& source, int) {
	MySet temp(source);
	--source;
	return temp;
}


/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const MySet& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const MySet& source) {

	return out;
}
/**
  * @brief 重载标准输入流 >>运算符
  * @param istream& input : 标准输出流对象
  * @param MySet& target : 接受输入数据的对象
  * @retval istream& 实现链式编程
  */
istream& operator>>(istream& input, MySet& target) {
	cout << "请输入集合中元素的个数n(n>0)：";
	int n;
	input >> n;
	cout << "请输入这" << n << "个元素（不要重复）：";
	MySet buffer;
	while (1) {
		try {
			buffer = target;
			for (int i = 0; i < n; i++) {
				int num;
				cin >> num;
				buffer.append(num);
			}
			break;
		}
		catch (const char* err) {
			cerr << err << "，请重新输入" << endl;
		}
	}
	target = buffer; // 全输对了才覆盖原来的对象
	return input;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
