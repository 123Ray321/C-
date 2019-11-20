 
#include <stdlib.h>
#include <iostream>  
#include "include\Python.h"

using namespace std;

int main()
{
	//��ʼ��Python����  
	Py_Initialize();
	
	PyRun_SimpleString("import sys");
	//���Insertģ��·��  
	//PyRun_SimpleString(chdir_cmd.c_str());
	PyRun_SimpleString("sys.path.append('./')");

	//����ģ��  
	PyObject* pModule = PyImport_ImportModule("Cal");

	if (!pModule)
	{
		cout << "��ȡģ��ʧ�ܣ�" << endl;
		system("pause");
		return 0;
	}

	cout << "��ȡģ��ɹ���" << endl;

	//��ȡInsertģ����_add����  
	PyObject* pv = PyObject_GetAttrString(pModule, "cal");
	if (!pv || !PyCallable_Check(pv))
	{
		cout << "û�з���cal������" << endl;
		system("pause");
		return 0;
	}
	cout << "��ȡcal����ʧ��!" << endl;
	
	//��ʼ��Ҫ����Ĳ�����args���óɴ�������������ģʽ  
	PyObject* args = PyTuple_New(1);
	//��Long������ת����Python�ɽ��յ�����  
	PyObject* arg1 = PyBytes_FromString("1*2+1");
	

	//��arg1����Ϊarg����ĵ�һ������  
	PyTuple_SetItem(args, 0, arg1);

	//����������ú���������ȡ����ֵ  
	PyObject* pRet = PyObject_CallObject(pv, args);
	
	if (pRet)
	{
		//������ֵת����long��  
		double result = PyFloat_AsDouble(pRet);
		cout << "result:" << result << endl;
	}
	
	Py_Finalize();

	system("pause");

	return 0;
}