//conctrl.h
/**
 * This file defined most ver kinds, structures and some basic condows functions
 * Copyright by hezex. Reach me at hezexi520@163.com
 * No warranty is given. Condows is open source on Github
*/

bool RegisterConClass(const CNDCLASS*);

void RegCommand();
void RegButton();
//void RegTextBox();

//conctrl.cpp
/**
 * This file realized the contents of conctrl.h
 * Copyright by hezex. Reach me at hezexi520@163.com
 * No warranty is given. Condows is open source on Github
*/

void RegCommand()
{
	char fill[30][120]={0};
	CNDCLASS cmdClass;
	cmdClass.Fill=(char **)fill;
	cmdClass.MsgProc=NULL;
	cmdClass.bkColor=0x07;
	cmdClass.ClassName="Command";
	RegisterConClass(&cmdClass);
}
void RegButton()
{
	char fill[1][3]={"[]"};
	CNDCLASS btnClass;
	btnClass.Fill=(char **)fill;
	btnClass.MsgProc=NULL;
	btnClass.bkColor=0x07;
	btnClass.ClassName="Button";
	RegisterConClass(&btnClass);
}

