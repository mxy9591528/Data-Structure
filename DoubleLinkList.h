#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct LinkList
{
	int data;
	struct LinkList*prev;
	struct LinkList*next;
}L;
L*SetLinkList(int n)
{
	L*head = NULL, *end = NULL;
	for (int i = 0; i < n; i++)
	{
		L*node = (L*)malloc(sizeof(L));
		node->data = i;
		node->prev = node->next = NULL;
		if (!head)
			head = end = node;
		else
		{
			node->prev = end;
			end->next = node;
			end = node;
		}
	}
	return head;
}
L*Search(L*p, int index)
{
	L*cur = p;
	while (index--)
	{
		cur = cur->next;
	}
	return cur;
}
L*Headadd(L*p,int val)
{
	L*node = (L*)malloc(sizeof(L));
	node->data = val;
	node->next = p;
	p->prev = node;
	node->prev = NULL;
	return node;
}
void Add(L*p, int index,int val)
{
	L*cur = Search(p, index);
	L*node = (L*)malloc(sizeof(L));
	node->data = val;
	node->next = cur->next;
	cur->next->prev = node;
	cur->next = node;
	node->prev = cur;
}
void Delete(L*p, int index)
{
	L*cur = p;
	while (index--)
	{
		cur = cur->next;
	}
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
	free(cur);
}
void Modify(L*p,int val,int index)
{
	L*cur = Search(p, index);
	cur->data = val;
}