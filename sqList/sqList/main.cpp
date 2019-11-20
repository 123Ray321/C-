#include<iostream>
#include<string>
#include<time.h>
#include<math.h>
#define MaxSize 10
using namespace std;

typedef struct 
{
	int * elem;
	int length;
	int listsize;
}sqList;

//��ʼ��List
string InitList(sqList &L)
{
	L.elem = (int *)malloc(MaxSize * sizeof(int));
	if (!L.elem)
		return "Initial error!";
	L.length = 0;
	L.listsize = MaxSize;
	return "Initial successful��";
}


//��ȡ��I��Ԫ�أ��ɹ�����1���ɹ�����0
int GetElem(sqList L, int i, int * e)
{
	if (L.length == 0 || i < 1 || i > L.length)
		return 0;
	*e = L.elem[i - 1];
	return 1;
}

//����Ԫ��
int InsertList(sqList &L, int i, int e)
{
	//������
	int k = 0;
	if (L.length == MaxSize)
		return 0;
	//i���ڷ�Χ��
	if (i < 1 || i > L.length + 1)
		return 0;
	if (i <= L.length)
	{
		for (k = L.length - 1; k >= i - 1; k--)
		{
			L.elem[k + 1] = L.elem[k];
		}
	}
	L.elem[i - 1] = e;
	L.length++;
	return 1;
}

//ɾ��Ԫ��
int DeleteElem(sqList &L,int i,int * e)
{
	int k = 0;
	if (L.length == 0)
		return 0;
	if (i < 1 || i > L.length)
		return 0;
	* e = L.elem[i - 1];
	if (i < L.length)
	{
		for (k = i - 1; k < L.length - 1; k++)
		{
			L.elem[k] = L.elem[k + 1];
		}
	}
	L.length--;
	return 1;
}

//����List�е������
int Find_max(sqList L )
{
	int i = 0, max = L.elem[0];
	for (i = 1; i < L.length; i++)
	{
		if (L.elem[i] > max)
			max = L.elem[i];
	}
	return max;
}

//���List���Ƿ���ڸú������������Ԫ��
int Find_elem(sqList L , int elem)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == elem)
			return 1;
	}
	return 0;
}

//���ر�����λ�õ�����Ԫ��
void Return_odd(sqList L)
{
	for (int i = 0; i < L.length; i++)
	{
		if ((i+1) % 2 != 0)
		{
			cout << L.elem[i] << " ";
		}
	}
	cout << endl;
}

//��List������Ԫ�صĺ�
int Sum(sqList L)
{
	int sum = 0;
	/*for (int i = 0; i < L.length; i++)
	{
		sum += L.elem[i];
	}*/
	int i = 0;
	while (i < L.length)
	{
		sum += L.elem[i];
		i++;
	}
	return sum;
}

//�ݹ���List�б���Ԫ�صĺͣ�
int Sum_dg(sqList L,int i)
{
	int sum = 0;
	if (i < L.length)
	{
		sum = L.elem[i];
		sum += Sum_dg(L, i+1);
	}
	return sum;
}

//������ȫƽ����
void On_all(sqList L)
{
	int count = 0;
	double min = 0;
	for (int i = 0; i < L.length; i++)
	{
		min = (double)sqrt(L.elem[i]);
		if (min == (int)min)  //�жϽ���Ƿ�Ϊ����
		{
			cout << L.elem[i] << " ";
			count++;
		}		
	}
	cout << endl;
	cout << "������" << count << endl;
}

int main()
{
	int e;
	sqList L;
	cout << InitList(L) << endl;
	
	//����N�����������
	srand(time(0));
	for (int i = 0; i < MaxSize; i++)
	{
		L.elem[i] = (rand() % 101);
		L.length++;
	}
	for (int i = 0; i < L.length; i++)
	{
		cout << L.elem[i] << " ";
	}
	cout << endl;
	DeleteElem(L, 1, &e);
	for (int i = 0; i < L.length; i++)
	{
		cout << L.elem[i] << " ";
	}
	cout << endl << e << " ";
	return 0;
}