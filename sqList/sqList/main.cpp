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

//初始化List
string InitList(sqList &L)
{
	L.elem = (int *)malloc(MaxSize * sizeof(int));
	if (!L.elem)
		return "Initial error!";
	L.length = 0;
	L.listsize = MaxSize;
	return "Initial successful！";
}


//获取第I个元素，成功返回1不成功返回0
int GetElem(sqList L, int i, int * e)
{
	if (L.length == 0 || i < 1 || i > L.length)
		return 0;
	*e = L.elem[i - 1];
	return 1;
}

//插入元素
int InsertList(sqList &L, int i, int e)
{
	//表满了
	int k = 0;
	if (L.length == MaxSize)
		return 0;
	//i不在范围内
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

//删除元素
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

//查找List中的最大数
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

//检查List中是否存在该函数输入参数这元素
int Find_elem(sqList L , int elem)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == elem)
			return 1;
	}
	return 0;
}

//返回表奇数位置的所有元素
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

//求List中所有元素的和
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

//递归求List列表中元素的和！
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

//返回完全平方数
void On_all(sqList L)
{
	int count = 0;
	double min = 0;
	for (int i = 0; i < L.length; i++)
	{
		min = (double)sqrt(L.elem[i]);
		if (min == (int)min)  //判断结果是否为整数
		{
			cout << L.elem[i] << " ";
			count++;
		}		
	}
	cout << endl;
	cout << "个数：" << count << endl;
}

int main()
{
	int e;
	sqList L;
	cout << InitList(L) << endl;
	
	//生成N个随机整数！
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