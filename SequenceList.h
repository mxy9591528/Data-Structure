#pragma once
#define initcapacity 3
#define addnum 2
#include<stdio.h>
#include<stdlib.h>
typedef struct SequenceList
{
	int*p;
	int capacity;
	int sz;
}S;

int InitList(S*pf)
{
	pf->capacity = initcapacity;
	pf->p =(int*)malloc(sizeof(int)*(pf->capacity));
	pf->sz = 0;
	return 1;
}
int checkcapacity(S*pf)
{
	if (pf->sz == pf->capacity)
	{
		pf->capacity += addnum;
		pf->p = (int*)realloc(pf->p, sizeof(int)*pf->capacity);
	}
	return 1;
}
int Add(S*pf, int n)
{
	checkcapacity(pf);
	pf->p[pf->sz] = n;
	pf->sz++;
	return 1;
}
int Delete(S*pf, int n)
{
	if (!pf->sz)
		return 0;
	for (int i = n - 1; i < pf->sz - 1; i++)
		pf->p[i] = pf->p[i + 1];
	pf->sz--;
	return 1;
}
int Check(S*pf, int n)
{
	if (!pf->sz)
		return 0;
	for (int i = 0; i < pf->sz; i++)
	{
		if (n == pf->p[i])
		{
			printf("找到了，下标为%d\n", i);
		}
	}
	return 1;
}
int Modify(S*pf, int n, int ps)
{
	if (!pf->sz)
		return 0;
	if (ps > pf->sz)
		return -1;
	pf->p[ps] = n;
	return 1;
}