 
#include <stdlib.h>
#include <iostream>  
#include "include\Python.h"

using namespace std;

int main()
{
	//初始化Python环境  
	Py_Initialize();
	
	PyRun_SimpleString("import sys");
	//添加Insert模块路径  
	//PyRun_SimpleString(chdir_cmd.c_str());
	PyRun_SimpleString("sys.path.append('./')");

	//导入模块  
	PyObject* pModule = PyImport_ImportModule("Cal");

	if (!pModule)
	{
		cout << "获取模块失败！" << endl;
		system("pause");
		return 0;
	}

	cout << "获取模块成功！" << endl;

	//获取Insert模块内_add函数  
	PyObject* pv = PyObject_GetAttrString(pModule, "cal");
	if (!pv || !PyCallable_Check(pv))
	{
		cout << "没有发现cal函数！" << endl;
		system("pause");
		return 0;
	}
	cout << "获取cal函数失败!" << endl;
	
	//初始化要传入的参数，args配置成传入两个参数的模式  
	PyObject* args = PyTuple_New(1);
	//将Long型数据转换成Python可接收的类型  
	PyObject* arg1 = PyBytes_FromString("1*2+1");
	

	//将arg1配置为arg带入的第一个参数  
	PyTuple_SetItem(args, 0, arg1);

	//传入参数调用函数，并获取返回值  
	PyObject* pRet = PyObject_CallObject(pv, args);
	
	if (pRet)
	{
		//将返回值转换成long型  
		double result = PyFloat_AsDouble(pRet);
		cout << "result:" << result << endl;
	}
	
	Py_Finalize();

	system("pause");

	return 0;
}