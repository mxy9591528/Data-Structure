#pragma once
#include"Queue.h"
typedef int STD;
typedef struct Stack
{
	Queue q1;
	Queue q2;
}Stack;
void InitStack(Stack*p)
{
	QueueInit(&p->q1);
	QueueInit(&p->q2);
}
void StackPush(Stack*p, STD n)
{
	if (QueueEmpty(&p->q1))
		QueuePush(&p->q2, n);
	else
		QueuePush(&p->q1, n);
}
STD StackPop(Stack*p)
{
	Queue*emptyQ = &p->q1;
	Queue*notemptyQ = &p->q2;
	if (!QueueEmpty(&p->q1))
	{
		emptyQ = &p->q2;
		notemptyQ = &p->q1;
	}
	while (QueueSize(notemptyQ)>1)
	{
		QueuePush(emptyQ, QueueFront(notemptyQ));
		QueuePop(notemptyQ);
	}
	STD top= QueueFront(notemptyQ);
	QueuePop(notemptyQ);
	return top;
}
STD StackTop(Stack*p)
{
	if (QueueEmpty(&p->q1))
		return QueueBack(&p->q2);
	else
		return QueueBack(&p->q1);
}
bool StackEmpty(Stack*p)
{
	return QueueEmpty(&p->q1) && QueueEmpty(&p->q2);
}
void StackFree(Stack*p)
{
	QueueDestory(&p->q1);
	QueueDestory(&p->q2);
}