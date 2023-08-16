#ifndef _MATRIX_LED_H__
#define _MATRIX_LED_H__
void _74HC595_WriteByte(unsigned char Byte);
void MatrixLED_Init();
void MatrixLED_ShowColumn(unsigned char Column,Data);

#endif