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
  * @brief �޲ι��캯�����������ϣ���Ԫ�ظ�����Ϊ0.
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
  * @brief �����±������
  */
const int& MySet::operator[](unsigned i)const {
	// ���ﷵ�ص���const int& ����ҵ��Ҫ���Ƿ���int&���������������ɣ�
	// 1.���ﷵ��int&�����൱Σ�գ��൱��ֱ�ӱ�¶�����˽�г�Ա��
	//   ͨ�����ص�����������޸ļ���Ԫ��ʱ���޷���鼯����Ԫ�صĺϷ���
	// 2.ʹ��const���εĶ����޷�ʹ�÷�const�ĳ�Ա����
	if (i >= 0 && i < _count) {
		return _array[i];
	}
	else throw "Index Error.";
}

/**
  * @brief �ж�����x�Ƿ��Ǽ��ϵ�Ԫ��
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
	}else throw "���ظ���Ԫ��";
}

/**
  * @brief �������ظ�ֵ�����
  */
void MySet::operator=(const MySet& source) {
	_count = source._count;
	for (int i = 0; i < _count; i++) {
		_array[i] = source._array[i];
	}
}

/**
  * @brief �������϶���ļӷ����㡱+���������Ǻϲ���������
  */
MySet MySet::operator+(const MySet& n2) const {
	MySet temp(*this);
	// n2 ��ֵ���ݸ�����һЩ�����ô�����ʱ����
	// ������ҵҪ���Ǵ������ã����ֵ���ݶ�һ�����ã�Ҳ����
	for (int i = 0; i < n2._count; i++)
		if (!temp.IsInSet(n2._array[i]))
			temp.append(n2._array[i]);
	return temp;
}

/**
  * @brief �������϶���ļ������㡱-�����������������1�еĲ����ڼ���2��Ԫ��
	��������Ҫ����ο�����ע�͡�
  */
MySet MySet::operator-(const MySet& n2) const {
	MySet temp;
	for (int i = 0; i < _count; i++)
		if (!n2.IsInSet(_array[i]))
			temp.append(_array[i]);
	return temp;
}

/**
  * @brief ���ϵġ�ǰ��++�����㣬�����ǽ������е�ÿһ��Ԫ������1��ǰ��������
  */
MySet& MySet::operator++() {
	for (int i = 0; i < _count; i++)
		_array[i]++;
	return *this;
}

/**
  * @brief ���ϵġ�����++�����㣬�����ǽ������е�ÿһ��Ԫ������1������������
  */
MySet MySet::operator++(int) {
	MySet temp(*this);
	++*this;
	return temp;
}

/**
  * @brief ��Ԫ�����ϵġ�ǰ��--�����㣬�����ǽ������е�ÿһ��Ԫ���Լ�1��ǰ���Լ���
  */
MySet& operator--(MySet& source) {
	for (int i = 0; i < source._count; i++)
		source._array[i]--;
	return source;
}

/**
  * @brief ��Ԫ�����ϵġ�����--�����㣬�����ǽ������е�ÿһ��Ԫ���Լ�1�������Լ���
  */
MySet operator--(MySet& source, int) {
	MySet temp(source);
	--source;
	return temp;
}


/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const MySet& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const MySet& source) {

	return out;
}
/**
  * @brief ���ر�׼������ >>�����
  * @param istream& input : ��׼���������
  * @param MySet& target : �����������ݵĶ���
  * @retval istream& ʵ����ʽ���
  */
istream& operator>>(istream& input, MySet& target) {
	cout << "�����뼯����Ԫ�صĸ���n(n>0)��";
	int n;
	input >> n;
	cout << "��������" << n << "��Ԫ�أ���Ҫ�ظ�����";
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
			cerr << err << "������������" << endl;
		}
	}
	target = buffer; // ȫ����˲Ÿ���ԭ���Ķ���
	return input;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
