/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa
  * @version V1.2.0
  * @date    2024-03-05
  * @brief   A demonstration of the class Date.
  * @encode  UTF-8
  ******************************************************************************
  */
#include <iostream>
#include <string>
using namespace std;

#include "date.h"

// �ûص�����ʵ�����������Զ��������ʽ
void output(int year, int month, int day) {
    cout << year << "��" << month << "��" << day << "��" << endl;
}
void output(string s){
    cout << "��ʾ��Ϣ��" << s << endl;
}

int main(){
    //system("chcp 65001");
    Date today(2024,3,5, output, output);
    today.showDate();
    today++;// �����������Լ������
    today.showDate();
    today++++++++;// ��������ʽ����
    today.showDate();
    today.setDate(0, 0, 0);// ���кϷ��Լ���set����
    cout << (Date::isValid(0, 0, 0)?"��Ч":"��Ч") << endl;// ���ⲻ��ʵ����������ʹ�����ṩ�ľ�̬����
    system("pause");
    return 0;
}

// todo: +- toNextMonth toNextYear ���ؿ���������������
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
