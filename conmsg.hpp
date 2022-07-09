//conmsg.h
/**
 * This file built the structures of message loop
 * Copyright by hezex. Reach me at hezexi520@163.com
 * No warranty is given. Condows is open source on Github
*/

queue<CONMSG> msg_queue;

void SendMessage(COMMSG*);
void CatchMessage(COMMSG*);
void DealMessage(COMMSG*,HCND);

void DefConProc(HCND,CONMSG);


//conmsg.cpp
/**
 * This file realize the contents in conmsg.h 
 * Copyright by hezex. Reach me at hezexi520@163.com
 * No warranty is given. Condows is open source on Github
*/

void SendMessage(COMMSG* conMsg)
{
	msg_queue.push(*conMsg);
}

void CatchMessage(COMMSG* conMsg)
{
	for(int i=0x01;i<=0xa5;i++)
		if(KEY_DOWN(i))
		{
			conMsg->msg=CM_KBDOWN;
			conMsg->para=i; //Here is the VK number
		}
}

