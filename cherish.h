#pragma once
#include<stdio.h>
#include "malloc.h"
#define MAXSIZE 1024
typedef int DataType;
typedef struct {
	DataType data[MAXSIZE];
	int last;

}SeqList;
SeqList SL;

int insertElem(SeqList* L, int i, DataType x) {
	int j;
	if (L->last == MAXSIZE - 1) {
		printf("overflow"); return 0;
	}
	if ((i < 1) || (i > L->last + 2)) {
		printf("error"); return 0;
	}
	for (j = L->last; j >= i - 1; j--)
		L->data[j + 1] = L->data[j];
	L->data[i - 1] = x;
	L->last++;
	return 1;

}

int deleteElem(SeqList* L, int i) {
	int j;
	if (i<1 || i>L->last + 1) {
		printf("Error!", i); return 0;
	}
	for (j = i; j <= L->last; j++)
		L->data[j - 1] = L->data[j];
	L->last--;
	return 1;

}

int LocateElem(SeqList* L, DataType x) {
	int i;
	for (i = 0; i <= L->last; i++)
		if (L->data[i] == x) return i + 1;
	return 0;

}

int LocateElem1(SeqList* L, DataType x) {
	int i = L->last;
	while (i >= 0 && L->data[i] != x) i--;
	return i + 1;

}

typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* next;
}LNode, * PNode, * LinkList;


int InitList(LinkList* h)
{
	*h = (LinkList)malloc(sizeof(LNode));
	if (!h)
	{
		printf("��ʼ���������\n");
		return 0;
	}
	(*h)->next = NULL;
	return 1;
}


int ListLength(LinkList h)
{
	int total = 0;
	PNode p = h->next;
	while (p)
	{
		total++;
		p = p->next;
	}
	return total;
}


int ListEmpty(LinkList h)
{
	if (h->next)
		return 0;
	else
		return 1;
}



int ListInsert(LinkList h, int pos, DataType x)
{
	PNode p = h, q;
	int i = 0;
	while (p && i < pos - 1)
	{
		p = p->next;
		i++;
	}
	if (!p || i > pos - 1)
	{
		printf("����λ�ò��Ϸ���\n");
		return 0;
	}
	q = (PNode)malloc(sizeof(LNode));
	if (!q)
	{
		printf("���������½��\n");
		return 0;
	}
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1;
}



int ListDelete(LinkList h, int pos, DataType* item)
{
	PNode p = h, q;
	int i = 0;
	while (p->next && i < pos - 1)
	{
		p = p->next;
		i++;
	}
	if (!p->next || i > pos - 1)
	{
		printf("ɾ��λ�ò��Ϸ���\n");
		return 0;
	}
	q = p->next;
	p->next = q->next;
	*item = q->data;
	free(q);
	return 1;
}


PNode Find(LinkList h, DataType item)
{
	PNode p = h->next;
	while (p && p->data != item)
		p = p->next;
	return p;
}


int GetElem(LinkList h, int pos, DataType* item)
{
	int i = 0;
	PNode p = h->next;
	while (p && i < pos - 1)
	{
		i++;
		p = p->next;
	}
	if (!p || i > pos - 1)
	{
		printf("λ�ò������Ϸ���\n");
		return 0;
	}
	*item = p->data;
	return 1;
}



void DestroyList(LinkList h)
{
	PNode p = h->next;
	while (h)
	{
		p = h;
		h = h->next;
		free(p);
	}
}


void TraverseList(LinkList h)
{
	PNode p = h->next;
	while (p)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}


void out(LinkList p)          //�ݹ�
{
	if (p)
	{
		out(p->next);
		printf("%d\t", p->data);    //�������
	}
}


#define MAX_SIZE 100

typedef struct {
	int data[MAX_SIZE];
	int top;
} Stack;

// ��ʼ��ջ
void initStack(Stack* stack) {
	stack->top = -1;
}

// �ж�ջ�Ƿ�Ϊ��
int isEmpty(Stack* stack) {
	return stack->top == -1;
}

// �ж�ջ�Ƿ�����
int isFull(Stack* stack) {
	return stack->top == MAX_SIZE - 1;
}

// ��ջ
void push(Stack* stack, int value) {
	if (isFull(stack)) {
		printf("Stack is full. Cannot push element.\n");
		return;
	}
	stack->data[++stack->top] = value;
}

// ��ջ
int pop(Stack* stack) {
	if (isEmpty(stack)) {
		printf("Stack is empty. Cannot pop element.\n");
		return -1;
	}
	return stack->data[stack->top--];
}

// ��ȡջ��Ԫ��
int top(Stack* stack) {
	if (isEmpty(stack)) {
		printf("Stack is empty.\n");
		return -1;
	}
	return stack->data[stack->top];
}

// ��ӡջ�е�Ԫ��
void printStack(Stack* stack) {
	printf("Stack: ");
	for (int i = 0; i <= stack->top; i++) {
		printf("%d ", stack->data[i]);
	}
	printf("\n");
}



