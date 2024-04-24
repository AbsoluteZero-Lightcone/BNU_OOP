/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
#include <string>
using namespace std;
#include "Student.h"

int main() {
	Student stu2[10] = {
		Student("张三","202010000005",'m',90),
		Student("李四","201810200012",'m',85),
		Student("王五","202010020108",'m',76),
		Student("刘丽丽","201910060022",'f',92),
		Student("赵勇平","202010000115",'m',88),
		Student("张春生","200610000059",'m',82),
		Student("周勇刚","201110040001",'m',77),
		Student("王阳","201810080072",'f',89),
		Student("刘燕","202010000023",'f',90),
		Student("何平平","202010000007",'f',93)
	};


	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
