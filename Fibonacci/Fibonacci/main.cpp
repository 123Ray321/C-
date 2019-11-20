#include<iostream>
#include<string>
#define N 100
using namespace std;

typedef struct
{
	unsigned int * elem;
	int length;
	int listsize;
}sqList;

string Initlist(sqList &L)
{
	L.elem = (unsigned int *)malloc(N * sizeof(unsigned int));
	L.length = 0;
	L.listsize = N;
	if (!L.elem)
		return "InitList Error!";
	else
		return "InitList Success!";
}

int main()
{
	sqList L;
	cout << Initlist(L) <<endl;
	L.elem[0] = 0;
	L.elem[1] = 1;
	L.length = 2;
	cout << "0 1 ";
	for (int i = 2; i < N; i++)
	{
		L.elem[i] = L.elem[i - 2] + L.elem[i - 1];
		L.length++;
		cout << L.elem[i] << " ";
	}

	return 0;
}