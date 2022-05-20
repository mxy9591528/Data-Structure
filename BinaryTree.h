#pragma once
#include<stdio.h>

typedef char TD;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode*left;
	struct BinaryTreeNode*right;
	TD data;
}BTNode;
#include"Queue-Tree.h"
void PrevOrder(BTNode*root)
{
	if (root)
	{
		printf("%c ", root->data);
		PrevOrder(root->left);
		PrevOrder(root->right);
	}
	else
		printf("NULL ");
}

void InOrder(BTNode*root)
{
	if (root)
	{
		InOrder(root->left);
		printf("%c ", root->data);
		InOrder(root->right);
	}
	else
		printf("NULL ");
}

void PostOrder(BTNode*root)
{
	if (root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%c ", root->data);
	}
	else
		printf("NULL ");
}

int TreeNodeSize(BTNode*root)
{
	return root == NULL ? 0 : TreeNodeSize(root->left) + TreeNodeSize(root->right) + 1;
}

int TreeLeafSize(BTNode*root)
{
	if (!root)
		return 0;
	if (!root->left && !root->right)
		return 1;
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

int TreeMaxDepth(BTNode*root)
{
	if (!root)
		return 0;
	int leftDepth = TreeMaxDepth(root->left);
	int rightDepth = TreeMaxDepth(root->right);
	return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}
void LevelOrder(BTNode*root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode*ret = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", ret->data);
		if (ret->left)
			QueuePush(&q, ret->left);
		if (ret->right)
			QueuePush(&q, ret->right);
	}
	printf("\n");
}

void TreeDestory(BTNode*root)
{
	if (!root)
		return;
	TreeDestory(root->left);
	TreeDestory(root->right);
	free(root);
	root = NULL;
}