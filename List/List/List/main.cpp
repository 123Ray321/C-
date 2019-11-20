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

//����б��е�����Ԫ��
void OutputList(SqList l)
{
	for (int i = 0; i < l.length; i++)
	{
		cout << l.elem[i] <<" ";
	}
}


//��ʼ���б�
Status InitList(SqList &l,int n)
{
	l.elem = (int *)malloc(n * sizeof(int));
	if (!l.elem)
		return Error;
	l.length = 0;
	l.listsize = n;
	return OK;
}

//��ȡ�б��е�ĳһλ�õ�Ԫ��
Status GetElem(SqList l, int i, int *e)
{
	if (l.length == 0)
		return Error;
	if (i < 1 || i > l.length)
		return Error;
	*e = l.elem[i - 1];
}


//���б��в���Ԫ��
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

//ɾ���б��е�ĳһ��Ԫ��
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

//���������б�
void LinkList(SqList &la, SqList lb)
{
	//��¼�б�la�ĳ���
	int laLen = la.length;
	//��la�б��ĩβ����lb�б��Ԫ�ذ�������
	for (int i = laLen; i < laLen + lb.length; i++)
	{
		la.elem[i] = lb.elem[i - laLen];
		la.length++;
	}
}

//����ϲ������б�
void MergeList(SqList &La,SqList Lb)
{
	//����������������ڼ�¼������������б�ʱ���б���������λ��
	int coutLa = 0;
	int coutLb = 0;
	int laLen = La.length;
	//����һ����ʱ�б��洢�б�la��Ԫ��
	SqList temp;
	InitList(temp, MaxSize);
	for (int i = 0; i < La.length; i++)
		temp.elem[i] = La.elem[i];
	La.length = 0;
	//������������б������뵽la�б���
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
		cout << "��ʼ���б�ɹ���" << endl;
	if (InitList(Lb, MaxSize))
		cout << "��ʼ���б�ɹ���" << endl;
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