#include <iostream>
#include <string>
#include <time.h>

using namespace std;
//结点结构体定义
typedef struct Node
{
	int data;
	struct Node * next;
} Node;

typedef struct Node* Linklist;

//头插法创建链表
void CreateListHead(Linklist &L, int n)
{
	Linklist p;
	int i;
	srand(time(0));
	L = (Linklist)malloc(sizeof(Node));
	L->next = NULL;
	for (i = 0; i < n; i++)
	{
		p = (Linklist)malloc(sizeof(Node));
		p->data = rand() % 101;
		p->next = L->next;
		L->next = p;
	}
}

//头插法插入元素到链表
void InsertListHead(Linklist &L, int e)
{
	Linklist p;
	p = (Linklist)malloc(sizeof(Node));
	p->data = e;
	p->next = L->next;
	L->next = p;
}

////尾插法建立链表(字符型)
//void CreateListTail(Linklist &L,char *a)
//{
//	Linklist p;
//	Linklist r;
//	int i;
//	L = (Linklist)malloc(sizeof(Node));
//	L->next = NULL;
//	r = L;
//	for (i = 0; i < strlen(a); i++)
//	{
//		p = (Linklist)malloc(sizeof(Node));
//		p->data = a[i];
//		r->next = p;
//		r = p;
//	}
//	r->next = NULL;
//}


//尾插法建立链表
void CreateListTail(Linklist &L, int n)
{
	Linklist p;
	Linklist r;
	int i;
	srand(time(0));
	L = (Linklist)malloc(sizeof(Node));
	L->next = NULL;
	r = L;
	for (i = 0; i < n; i++)
	{
		p = (Linklist)malloc(sizeof(Node));
		p->data = rand() % 101;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

//获取元素
int GetElem(Linklist L, int i,int &e)
{
	int j;
	Linklist p;
	p = L->next;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return 0;
	e = p->data;
	return 1;
}

//修改元素
int UpdateElem(Linklist &L, int i, int e)
{
	int j;
	Linklist p;
	p = L->next;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return 0;
	p->data = e;
	return 1;
}

//向链表中插入元素
int ListInsert(Linklist &L,int i,int e)
{
	int j;
	Linklist p,s;
	p = L;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return 0;
	s = (Linklist)malloc(sizeof(Node));
	s->next = p->next;
	s->data = e;
	p->next = s;
	return 1;
}

//删除链表中的元素
int ListDelete(Linklist &L,int i,int &e)
{
	int j;
	Linklist p,q;
	p = L;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return 0;
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return 1;
}

//清空链表
int ClearList(Linklist &L)
{
	Linklist p, q;
	p = L->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return 1;
}

//输出链表
void OutPutList(Linklist L)
{
	Linklist p;
	int j;
	p = L;
	while (p)
	{
		cout << p->data <<" ";
		p = p->next;
	}
	cout << endl;
}

//按一定规则改变字符串
//void ChangeList(Linklist &L)
//{
//	Linklist p,s;
//	p = L;
//	int count = 0;
//	int flag = 1;
//	int first;
//	while (p)
//	{
//		p = p->next;
//		count++;		
//		
//		//记录每一个空格后第一个字母的位置
//		if (flag)
//		{
//			first = count;
//			s = p;
//			flag = 0;
//		}
//		
//		
//		if (!p)
//		{
//			char e;
//			ListInsert(L, count, s->data);
//			ListInsert(L, count + 1, 'a');
//			ListInsert(L, count + 2, 'y');
//			ListDelete(L, first, e);
//			break;
//		}
//		
//		char a = p->data;
//		if (a == ' ')
//		{
//			int a;		
//
//			if (s->data < 97)
//				s->data += 32;
//			char e;
//			ListInsert(L, count,s->data);
//			ListInsert(L, count + 1, 'a');
//			ListInsert(L, count + 2, 'y');
//			ListDelete(L, first, e);
//			flag = 1;
//			count += 2;
//		}
//	}
//	char a;
//	GetElem(L, 1, a);
//	UpdateElem(L,1,a - 32);
//}

void ReverseList(Linklist &La, Linklist &Lb)
{
	Linklist p;
	p = La->next;
	while (p)
	{
		InsertListHead(Lb, p->data);
		p = p->next;
	}
}

//递归结构原地逆转
Linklist ReverseList_InSitu_Rec(Linklist &head)
{
	Linklist newHead;
	if ((head == NULL) || (head->next == NULL))
		return head;
	//递归部分
	newHead = ReverseList_InSitu_Rec(head->next);
	//回朔部分
	head->next->next = head;
	head->next = NULL;
	return newHead;
}

//循环结构原地逆转
void ReverseList_InSitu_Loop(Linklist &L)
{
	Linklist p, next, head;
	p = NULL;
	head = L->next;
	while (head)
	{
		next = head->next;
		head->next = p;
		p = head;
		head = next;
	}
	L->next = p;
}

int main()
{
	//定义列表和辅助列表
	Linklist La,Lout;
	Lout = (Linklist)malloc(sizeof(Node));
	CreateListTail(La,10);
	OutPutList(La->next);
	OutPutList(ReverseList_InSitu_Rec(La->next));

	return 0;
}