//conuser.h
/**
 * This file defined the functions for users
 * Copyright by hezex. Reach me at hezexi520@163.com
 * No warranty is given. Condows is open source on Github
*/

map<const char*,CNDCLASS> regCtrl;
int focus;

void RegCommand();
void RegButton();
HCND ConInit(CONMSGCALLBACK cmdProc,const char* cmdCaption,int w,int h);

bool RegisterConClass(const CNDCLASS*);
HCND CreateCondow(const char*,const char*,COORD,CONMSGCALLBACK,CPARAM,int,int,int,int);

//conuser.cpp
/**
 * This file realize the contents of conuser.h
 * Copyright by hezex. Reach me at hezexi520@163.com
 * No warranty is given. Condows is open source on Github
*/

bool RegisterConClass(const CNDCLASS *CndClass)
{
	if(regCtrl.find(CndClass->ClassName)==regCtrl.end()) return false;
	else regCtrl[CndClass->ClassName]=*CndClass;
	return true;
}

HCND CreateCondow(const char* conClass,const char* conCaption,COORD capPos,CONMSGCALLBACK MsgProc,CPARAM,int x,int y,int h,int w)
{
	CND__ *cnd;
	cnd->cndClass=regCtrl[conClass];
	cnd->Caption=(char *)conCaption;
	cnd->capPos=capPos;
	cnd->cndClass.MsgProc=MsgProc;
	cnd->x=x;cnd->y=y;
	cnd->h=h;cnd->w=w;
	return (HCND)cnd;
}

HCND ConInit(CONMSGCALLBACK cmdProc,const char* cmdCaption,int w,int h)
{
	RegCommand();
	RegButton();
	HCND hCon=CreateCondow("Command",cmdCaption,(COORD){0,0},cmdProc,(CPARAM)NULL,0,0,w,h);
	return hCon;
}

