#ifndef __XPT2046_H__
#define __XPT2046_H__


#define XPT2406_XP_8  0x9C
#define XPT2406_YP_8 0xDC
#define XPT2406_AUX_8  0xEC
#define XPT2406_VBAT_8  0xAC


#define XPT2406_XP_12  0x94
#define XPT2406_YP_12 0xD4
#define XPT2406_AUX_12  0xE4
#define XPT2406_VBAT_12  0xA4


unsigned int XPT2046_ReadAD(unsigned char Command);

#endif 