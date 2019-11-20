#include <iostream>
#include <string>
#include <time.h>

#define MaxSize 20
#define Error 0
#define OK 1

using namespace std;

typedef int Status;
typedef struct
{
	int * elem;
	int length;
	int listsize;
}SqList;

//输出列表中的所有元素
void OutputList(SqList l)
{
	for (int i = 0; i < l.length; i++)
	{
		cout << l.elem[i] <<" ";
	}
}


//初始化列表
Status InitList(SqList &l,int n)
{
	l.elem = (int *)malloc(n * sizeof(int));
	if (!l.elem)
		return Error;
	l.length = 0;
	l.listsize = n;
	return OK;
}

//获取列表中的某一位置的元素
Status GetElem(SqList l, int i, int *e)
{
	if (l.length == 0)
		return Error;
	if (i < 1 || i > l.length)
		return Error;
	*e = l.elem[i - 1];
}


//向列表中插入元素
Status  InsertList(SqList &l, int i,int e)
{
	int k;
	if (l.length == MaxSize)
		return Error;
	if (i < 1 || i > l.length + 1)
		return Error;
	else
	{
		for (k = l.length - 1; k >= i - 1; k--)
			l.elem[k + 1] = l.elem[k];
	}
	l.elem[i - 1] = e;
	l.length++;
	return OK;
}

//删除列表中的某一个元素
Status  DeleteList(SqList &l, int i, int * e)
{
	int k;
	* e = l.elem[i - 1];
	if (l.length == 0)
		return Error;
	if (i < 1 || i > l.length)
		return Error;
	else
	{
		for (k = i - 1; k < l.length - 1; k--)
			l.elem[k] = l.elem[k + 1];
	}
	l.length--;
	return OK;
}

//连接两个列表
void LinkList(SqList &la, SqList lb)
{
	//记录列表la的长度
	int laLen = la.length;
	//从la列表的末尾处将lb列表的元素挨个插入
	for (int i = laLen; i < laLen + lb.length; i++)
	{
		la.elem[i] = lb.elem[i - laLen];
		la.length++;
	}
}

//交叉合并两个列表
void MergeList(SqList &La,SqList Lb)
{
	//下面的两个变量用于记录交叉遍历两个列表时，列表被遍历到的位置
	int coutLa = 0;
	int coutLb = 0;
	int laLen = La.length;
	//创建一个临时列表，存储列表la的元素
	SqList temp;
	InitList(temp, MaxSize);
	for (int i = 0; i < La.length; i++)
		temp.elem[i] = La.elem[i];
	La.length = 0;
	//交叉遍历两个列表，并插入到la列表中
	for (int i = 0; i < laLen + Lb.length; i++)
	{
		if (i % 2 == 0)
		{
			La.elem[i] = temp.elem[coutLa];
			La.length++;
			coutLa++;
		}
		else
		{
			La.elem[i] = Lb.elem[coutLb];
			La.length++;
			coutLb++;
		}
	}
}

int main()
{
	int i;
	SqList La;
	SqList Lb;
	if (InitList(La, MaxSize))
		cout << "初始化列表成功！" << endl;
	if (InitList(Lb, MaxSize))
		cout << "初始化列表成功！" << endl;
	srand(time(0));
	for (i = 0; i < 10; i++)
	{
		La.elem[i] = rand()%101;
		La.length++;
	}
	for (i = 0; i < 10; i++)
	{
		Lb.elem[i] = rand() % 101;
		Lb.length++;
	}
	OutputList(La);
	cout << endl;
	OutputList(Lb);
	cout << endl;
	LinkList(La,Lb);
	OutputList(La);
	cout << endl;
	return 0;
}