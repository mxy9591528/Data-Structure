#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef struct LinkList
{
	int data;
	struct LinkList*next;
}L;
L*SetLinkList(int n)
{
	L*head = NULL, *end = NULL;
	for (int i = 0; i < n; i++)
	{
		L*node = (L*)malloc(sizeof(L));
		node->data = i;
		node->next = NULL;
		if (!head)
			head =end= node;
		else
		{
			end->next = node;
			end = node;
		}
	}
	return head;
}
L*Addnode(L*p, int val, int n)
{
	L*prev = p;
	L*cur = p;
	while (n--)
	{
		prev = cur;
		cur = cur->next;
	}
	L*node = (L*)malloc(sizeof(L));
	node->data = val;
	prev->next = node;
	node->next = cur;
	return p;
}
void*Headinsert(L*p, int val)
{
	L*node = (L*)malloc(sizeof(L));
	node->data = val;
	node->next = p;
	p = node;
}  
L*Delete_fdata(L*p, int val)//数据查找
{
	if (p->data == val)
	{
		p = p->next;
		return p;
	}
	L*prev = p;
	L*cur = p;
	while (cur->data != val)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = cur->next;
	free(cur);
	cur = NULL;
	return p;
}
L*Delete_index(L*p, int n)//下标查找
{
	if (n == 1)
	{
		p = p->next;
		return p;
	}
	L*prev = p;
	L*cur = p;
	while (n--)
	{
		if (!cur)
		{
			prev->next = NULL;
			return p;
		}
		prev = cur;
		cur = cur->next;
	}
	prev->next = cur->next;
	free(cur);
	cur = NULL;
	return p;

}
int Find_fdata(L*p, int val)//数据查找
{
	L*cur = p;
	int index = 0;
	while (cur->data != val)
	{
		cur = cur->next;
		index++;
	}
	return index;
}
L*Find_index(L*p, int n)//下标查找
{
	L*cur = p;
	while (n--)
	{
		cur = cur->next;
	}
	return cur;
}
L*Modify(L*p, int val, int n)
{
	L*cur = p;
	Find_index(p, n)->data = val;
	return p;
}
L*Reverse(L*p)
{
	L*newhead = NULL, *node = NULL;
	while (p)
	{
		node = p;
		p = p->next;
		node->next = newhead;
		newhead = node;
	}
	return newhead;
}