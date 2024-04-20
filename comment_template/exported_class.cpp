/**
  ******************************************************************************
  * @file    exported_class.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   exported_class class
  * @encode  GB2312
  ******************************************************************************
  */

#include "exported_class.h"

exported_class::exported_class() {}
exported_class::exported_class(const exported_class& source) {}
exported_class::~exported_class() {}
void exported_class::operator=(const exported_class& source) {}
datatype1 exported_class::get_dataname1() { return m_dataname1; }
void exported_class::set_dataname1(datatype1 t_dataname1) { m_dataname1 = t_dataname1; }
datatype2 exported_class::get_dataname2() { return m_dataname2; }
void exported_class::set_dataname2(datatype2 t_dataname2) { m_dataname2 = t_dataname2; }

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
