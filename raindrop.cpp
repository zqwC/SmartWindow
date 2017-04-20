/**************************************************************************************
 * Copyright (c) 张群伟.
 * All rights reserved.
 * 文件名	：raindrop.cpp
 * 摘要		：CRaindrop类的实现
 * 作者		：张群伟	南昌航空大学信息工程学院自动化系
 * 日期		：[3/29/2017]
 * 历史记录	：
 *		修改者：   日期：	 版本：	   修改内容：
 *	 1. 张群伟     17/2/25   1.0         创建该模块
 **************************************************************************************/

#include "raindrop.h"

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
// CRaindrop 构造/析构
CRaindrop::CRaindrop(int raindrop_pin)
{
	m_pin = raindrop_pin;
	pinMode(m_pin, INPUT);
}

CRaindrop::~CRaindrop()
{
	detach();
}

/**************************************************************************************
 * 函数名	：read()
 * 功能		：读取传感器的数据并返回
 * 参数		：void
 * 返回值   : m_value
 * 说明  	：
 * 作者		：张群伟	南昌航空大学信息工程学院自动化系
 * 日期		：[3/29/2017]
 **************************************************************************************/
int CRaindrop::read(void)
{
	m_value = digitalRead(m_pin);
	return m_value;
}

/**************************************************************************************
 * 函数名	：
 * 功能		：显示 感应板上没有水滴时，DO输出为高电平，开关指示灯灭 ，
 *			  滴上一滴水，DO输出为低电平，开关指示灯亮
 * 参数		：void
 * 返回值   : void
 * 说明  	：
 * 作者		：张群伟	南昌航空大学信息工程学院自动化系
 * 日期		：[3/29/2017]
 **************************************************************************************/
void CRaindrop::show(void)
{
	read();
	Serial.print("***|	Raindrop:  ");
	if (HIGH == m_value)
		Serial.print("No Rain!");
	else
		Serial.print("Rain!");

	Serial.println();
	delay(DELAY_VALUE);
}

/**************************************************************************************
 * 函数名	：monitor()
 * 功能		：监测
 * 参数		：void
 * 返回值   : SHUT_WINDOW   下雨
 *			  OPEN_WINDOW   没下雨
 * 说明  	：
 * 作者		：张群伟	南昌航空大学信息工程学院自动化系
 * 日期		：[3/29/2017]
 **************************************************************************************/
int CRaindrop::monitor(void)
{
	if (LOW == m_value)
		return SHUT_WINDOW;
	else
		return KEEP_WINDOW;
}

// raindrop.cpp end