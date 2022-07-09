//condef.h
/**
 * This file defined most macros which is useful in condows
 * Copyright by hezex. Reach me at hezexi520@163.com
 * No warranty is given. Condows is open source on Github
*/

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

#define CON_NULL 0

//Condows Messages
#define CM_CREATE 0x10000000
//#define CM_DESTORY 0x10000001
#define CM_ONFOCUS 0x10000002
#define CM_OFFFOCUS 0x10000003
#define CM_KBDOWN 0x10000004
#define CM_KBUP 0x10000005
#define CM_COMMAND 0x10000006
#define CM_FOCUSNXT 0x10000007

//Condows Styles
//#define CS_BORDER 0x10000001
//#define CS_ENABLECLOSE 0x10000002
#define CS_VISIBLE 0x10000004
//Condows Button Styles
//#define CBS_CHECKBOX 0x20000001

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
#define FB_EXCHANGE(x) (((x&0xf)<<4)|(x>>4))

//Basic Functions
void SetOutputPos(short,short);
void SetOutputColor(char);
COORD GetOutputPos();
//COORD GetOutputAttributes();
SMALL_RECT GetOutputRect();


typedef void *HCND;
typedef long long CPARAM;

typedef void(*CONMSGCALLBACK)(HCND,CONMSG);

struct CONMSG
{
	int msg;
	CPARAM para;
};
struct CNDCLASS
{
	char **Fill;
	CONMSGCALLBACK MsgProc;
	char bkColor; //You can use command palette here
	const char *ClassName;
};
struct CND__
{
	CNDCLASS cndClass;
	char *Caption;
	COORD capPos;
	int x,y;
	int h,w;
};

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

COORD GetOutputPos()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);
	return csbi.dwCursorPosition;
}

SMALL_RECT GetOutputRect()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);
	return csbi.srWindow;
}

