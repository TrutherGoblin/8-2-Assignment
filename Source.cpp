#include <Python.h>

#include <iostream>

#include <Windows.h>

#include <cmath>

#include <string>



using namespace std;


void CallProcedure(string pName)

{

	char* procname = new char[pName.length() + 1];

	std::strcpy(procname, pName.c_str());



	Py_Initialize();

	PyObject* my_module = PyImport_ImportModule("PythonCode");

	PyErr_Print();

	PyObject* my_function = PyObject_GetAttrString(my_module, procname);

	PyObject* my_result = PyObject_CallObject(my_function, NULL);

	Py_Finalize();



	delete[] procname;

}




int callIntFunc(string proc, string param)

{

	char* procname = new char[proc.length() + 1];

	std::strcpy(procname, proc.c_str());



	char* paramval = new char[param.length() + 1];

	std::strcpy(paramval, param.c_str());





	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;



	Py_Initialize();



	pName = PyUnicode_FromString((char*)"PythonCode");

	

	pModule = PyImport_Import(pName);


	pDict = PyModule_GetDict(pModule);

	 

	pFunc = PyDict_GetItemString(pDict, procname);

	if (PyCallable_Check(pFunc))

	{

		pValue = Py_BuildValue("(z)", paramval);

		PyErr_Print();

		presult = PyObject_CallObject(pFunc, pValue);

		PyErr_Print();

	}

	else

	{

		PyErr_Print();

	}

	

	Py_DECREF(pValue);

	

	Py_DECREF(pModule);

	Py_DECREF(pName);

	

	Py_Finalize();



	

	delete[] procname;

	delete[] paramval;





	return _PyLong_AsInt(presult);

}





int callIntFunc(string proc, int param)

{

	char* procname = new char[proc.length() + 1];

	std::strcpy(procname, proc.c_str());



	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;



	Py_Initialize();



	pName = PyUnicode_FromString((char*)"PythonCode");



	pModule = PyImport_Import(pName);

	

	pDict = PyModule_GetDict(pModule);

 

	pFunc = PyDict_GetItemString(pDict, procname);

	if (PyCallable_Check(pFunc))

	{

		pValue = Py_BuildValue("(i)", param);

		PyErr_Print();

		presult = PyObject_CallObject(pFunc, pValue);

		PyErr_Print();

	}

	else

	{

		PyErr_Print();

	}



	Py_DECREF(pValue);



	Py_DECREF(pModule);

	Py_DECREF(pName);



	Py_Finalize();



	

	delete[] procname;



	return _PyLong_AsInt(presult);

}





void main()

{

	int userChoice = -1;





	while (userChoice != 4) {

		cout << "****************************** MENU ******************************" << endl;

		cout << "1. Determine number of times each individual item appears" << endl;

		cout << "2. Determine the frequency of a specific item" << endl;

		cout << "3. Graphically display a text-based histogram" << endl;

		cout << "4. Quit program" << endl;

		cout << "******************************************************************" << endl;

		cout << "Make your selection. Enter 1, 2, 3, or 4." << endl;



		cin >> userChoice;



		if (userChoice == 1) {

			cout << "Number of times each item appears: " << endl;

			cout << callIntFunc("get_frequency_of_each_item", "") << endl;

		}



		else if (userChoice == 2) {

			cout << "Enter item name: " << endl;



			string item;

			cin >> item;



			cout << callIntFunc("get_frequency_of_single_item", item) << endl;

		}



		else if (userChoice == 3) {

			cout << "Histogram: " << endl;

			cout << callIntFunc("show_histogram", "") << endl;

		}



		else if (userChoice == 4) {

			cout << "Thank you for using the program. Goodbye." << endl;

		}



		else {

			cout << "Invalid selection. Please try again later." << endl;

			break;

		}

	}



}
