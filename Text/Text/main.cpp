#include <iostream>
#include <string>
using namespace std;

bool UpDown(char *str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] < 91 && str[i] > 64)
		{
			str[i] += 32;
		}
		else
		{
			str[i] -= 32;
		}
	}
	return true;
}
//Ó¢ÎÄ
bool isPalindromeLe (char * str)
{
	int leftFlag;
	int rightFlag;
	int strLen = strlen(str);
	if (strLen <= 1)
		return false;
	if (strLen % 2 == 0)
	{
		leftFlag = strLen / 2 - 1;
		rightFlag = strLen / 2;
	}
	else
	{
		leftFlag = strLen / 2 - 1;
		rightFlag = strLen / 2 + 1;
	}
	for (; (leftFlag >= 0) && (rightFlag < strLen); leftFlag--, rightFlag++)
	{
		if (str[leftFlag] != str[rightFlag])
			return false;
	}
	return true;
}
//ºº×Ö
bool isPalindromeCc(char * str)
{
	int leftFlag;
	int rightFlag;
	int strLen = strlen(str);
	if ((strLen < 4) || (strLen % 2 != 0))
		return false;
	if (strLen % 3 == 0)
	{
		leftFlag = strLen / 2 - 3;
		rightFlag = strLen / 2 + 1;
	}
	else
	{
		leftFlag = strLen / 2 - 2;
		rightFlag = strLen / 2;
	}
	for (; (leftFlag >= 0) && (rightFlag < strLen); leftFlag -= 2, rightFlag += 2)
	{
		if (str[leftFlag] != str[rightFlag])
			return false;
	}
	return true;
}


void print(char * a[])
{
	int i = 0;
	int max_length = 0;
	for (i = 0; i < 5; i++)
	{	
		if (strlen(a[i]) > max_length)
			max_length = strlen(a[i]);
	}

	for (i = 0; i < max_length + 2; i++)
	{
		cout << "*";
	}
	cout << endl;

	int space = 0;
	for (i = 0; i < 5; i++)
	{
		space = max_length - strlen(a[i]);
		cout << "*" << a[i];
		for (int j = 0; j < space ; j++)
		{
			cout << " ";
		}
		cout << "*"<< endl;
	}

	for (i = 0; i < max_length + 2; i++)
	{
		cout << "*";
	}
	cout << endl;
}

int main()
{
	char * s;
	s = (char *)malloc(30 * sizeof(char));
	cin >> s;
	return 0;
}