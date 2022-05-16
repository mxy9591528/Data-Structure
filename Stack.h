#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define INITCAPACITY 10

typedef int STD;

typedef struct Stack
{
	STD*base;
	STD top;
	int capacity;
}S;

void InitStack(S*pf)
{
	pf->base =(int*)malloc(sizeof(int)*INITCAPACITY);
	pf->capacity = INITCAPACITY;
	pf->top = 0;
}
void checkcapacity(S*pf)
{
	assert(pf);
	if (pf->top == pf->capacity)
	{
		pf->capacity *= 2;
		pf->base =(STD*)realloc(pf->base,pf->capacity*sizeof(int));
	}
}
void StackPush(S*pf, int n)
{
	checkcapacity(pf);
	pf->base[pf->top] = n;
	pf->top++;
}

void StackPop(S*pf)
{
	assert(pf&&pf->top > 0);
	pf->top--;
}

bool StackEmpty(S*pf)
{
	assert(pf);
	if (pf->top == 0)
		return true;
	else
		return false;
}
void StackDestory(S*pf)
{
	assert(pf);
	pf->capacity = pf->top = 0;
	free(pf->base);
	pf->base = NULL;
}
int StackTop(S*pf)
{
	assert(pf&&pf->top > 0);
	return pf->base[pf->top - 1];
}
int StackSize(S*pf)
{
	assert(pf);
	return pf->top;
}