#pragma once
#include"Stack.h"
typedef int QUD;
typedef struct Queue
{
	S in;
	S out;
}Queue;
void QueueInit(Queue*p)
{
	InitStack(&p->in);
	InitStack(&p->out);
}
void QueuePush(Queue*p, QUD n)
{
	StackPush(&p->in, n);
}
void transfer(Queue*p)
{
	if (StackEmpty(&p->out))
	{
		while (StackSize(&p->in) > 0)
		{
			StackPush(&p->out, StackTop(&p->in));
			StackPop(&p->in);
		}
	}
}
void QueuePop(Queue*p)
{
	transfer(p);
	StackPop(&p->out);
}
QUD QueueFront(Queue*p)
{
	transfer(p);
	return StackTop(&p->out);
}
QUD QueueBack(Queue*p)
{
	if (StackEmpty(&p->in))
		return p->out.base[0];
	else
		return StackTop(&p->in);
}
bool QueueEmpty(Queue*p)
{
	return StackEmpty(&p->in) && StackEmpty(&p->out);
}
int QueueSize(Queue*p)
{
	if (StackEmpty(&p->in))
		return StackSize(&p->out);
	else
		return StackSize(&p->in);
}
void QueueDestory(Queue*p)
{
	StackDestory(&p->in);
	StackDestory(&p->out);
}