/**
  ******************************************************************************
  * @file    show.cpp
  * @author  Zhang Yifa 202311998186
  * @version V2.2.1
  * @date    2024-05-21
  * @brief   show
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ----------------------------------------------------------------- */
#include "show.h"

/* Exported variables ------------------------------------------------------- */
const string tests[] = {
	// verified functions:
	"1 + (2.15) * 3 / (2.120001*(1-6))+2.1 * (3 /2.12)*1-6",// һ��ı��ʽ
	"123",// ��������
	"((((()))))" ,// �жϿ�����
	"-1+2",
	"1+(-2)",// ������ -1+2 �� 1+(-2)
	"1/(2-2)"// ������
	"2(3+4)",// �˺�ʡ�Ե�����Ƿ� 2(3+4)
	"2^3",// ������֧��
	"2%3",// ����ȡ������fmod֧��

	// todos:
	"1++++----2",// todo ��鲻�Ϸ��������Ӽ���
	"sin(123)",// todo ����ʽ����֧��
	"|-12|",// todo ����������ţ�����ֵ��
	"12!",// todo ���õ�Ŀ����(�׳�����)
	"E^(i*Pi)",// todo ��ѧ����
	"ans+1",// todo ���书��
};

const string cmds[] = {
	"exit",
	"test",
};
/* Exported functions ------------------------------------------------------- */
bool cmd_detector(string s) {
	for (int i = 0; i < CMD_COUNT; i++) {
		if (s == cmds[i]) {
			switch (i) {
			case CMD_EXIT:
				exit(0);
				break;
			case CMD_TEST:
				test(tests);
				break;
			}
			return true;
		}
	}
	return false;
}

void show(const Expression& e) {
	cout << endl << "-- Calculating process ---------------------------------------------------------" << endl << endl;
	double res = Expression::Process(e);
	cout << endl << "------------------------------------------------------- Calculation completed --" << endl;
	cout << endl << ">>> " << e << " = " << res << endl << endl;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
