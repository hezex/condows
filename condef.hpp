//condef.h
/**
 * This file defined most macros which is useful in condows
 * Copyright by hezex. Reach me at hezexi520@163.com
 * No warranty is given. Condows is open source on Github
*/

#define CON_NULL 0

//Condows Messages
#define CM_CREATE 0x10000000
#define CM_DELETE 0x10000001
#define CM_ONFOCUS 0x10000002
#define CM_OFFFOCUS 0x10000003
#define CM_KBPRESS 0x10000004
#define CM_KBBOUNCE 0x10000005

#define CMB_ONCLICK 0x11000000
#define CMB_ONPRESS 0x11000001
#define CMB_ONBOUNCE 0X11000002

//Condows Styles
//#define CS_BORDER 0x10000000
//#define CS_ENABLE_CLOSE 0x10000001

//Command Colors
/*Use (<<4) to set background colors*/
#define CLR_BACK 0x0
#define CLR_BLUE 0x1
#define CLR_GREEN 0x2
#define CLR_L_GREEN 0x3
#define CLR_RED 0x4
#define CLR_PURPLE 0x5
#define CLR_YELLOW 0x6
#define CLR_WHITE 0x7
#define CLR_GRAY 0x8
#define CLR_P_BLUE 0x9
#define CLR_P_GREEN 0xa
#define CLR_PL_GREEN 0xb
#define CLR_P_RED 0xc
#define CLR_P_PURPLE 0xd
#define CLR_P_YELLOW 0xe
#define CLR_P_WHITE 0xf

//Command Palette
/*When use, integrate the macros with operator '|'*/
#define CP_BLUE 1
#define CP_GREEN 2
#define CP_RED 4
#define CP_LIGHT 8
#define FOREGROUND(x) (x)
#define BACKGROUND(x) (x<<4)

//Basic Functions
void SetOutputPos(short,short);
void SetOutputColor(char);
COORD GetOutputPos();
//COORD GetOutputAttributes();
SMALL_RECT GetOutputRect();


//condef.cpp
/**
 * This file realized the contents of condef.h
 * Copyright by hezex. Reach me at hezexi520@163.com
 * No warranty is given. Condows is open source on Github
*/

using namespace std;

void SetOutputPos(short x,short y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

void SetOutputColor(char color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

