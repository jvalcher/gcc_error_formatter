/*
    Tutorial.cpp
    The module represents my demo functions and its assessment.

    Sandbox

    Created by alimovlex.
    Copyright (c) 2020 alimovlex. All rights reserved.
*/
#include <ctime>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <ctime>
#include <exception>
#include <algorithm>
#include <iterator>
#include <array>
#include <functional>
#include <numeric>
#include <chrono>
#include <iomanip>
#include <memory>
#include <cstdarg>
//----------------------------------------MACROSES
#define MIN(a,b) (((a)<(b)) ? a : b)
#define MAX(a,b) (((a)>(b)) ? a : b)
#define MULTIPLY(a, b) a*b 
#define merge(a, b) a##b 
#define RECEIVE(a) #a
#define MKSTR( x ) #x

//----------------------------------------END
using namespace std;
using namespace chrono;

int fileTest()
{
	fstream MyFile;
    const string fileName = "test.txt";
	MyFile.open(fileName, ios::out);
	MyFile << "Hello" << endl;
	if (MyFile.is_open()) 
	{
		MyFile << "This is awesome!"<<endl;
	}
	else
	{
		cout << "Something went wrong"<<endl;
        return -1;
	}
	MyFile.close();
	MyFile.open(fileName);
	if (MyFile.is_open())
	{
		string line;
		while (!MyFile.eof())
		{
			getline(MyFile, line);
			cout << " "<< line;
		}
		cout << endl;
	}
	MyFile.close();
    return 0;
}

int localTimeCheck()
{
    // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    char* dt = ctime(&now);

    cout << "The local date and time is: " << dt << endl;

    // convert now to tm struct for UTC
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "The UTC date and time is:" << dt << endl;

    return 0;
}

int testingPointers()
{
	int x = 1;
	int *pointer_to_x = &x;
	int & nickname_x = x; //the link to x variable
	cout <<"x="<< x << endl;
	int y = *pointer_to_x;
	y = 3;
	*pointer_to_x = 4;
	nickname_x = *pointer_to_x;
	cout <<"y="<< *pointer_to_x << endl;
	cout<<"nickname x="<<nickname_x<<endl;
	int *p = &x;
	p = &y;
	*p = 0;
	int j = *p;
	p = nullptr;
	//Another program
	int  var;
	int  *ptr;
	int  **pptr;

	var = 3000;
	// take the address of var
	ptr = &var;
	// take the address of ptr using address of operator &
	pptr = &ptr;
    cout<<hex;//hexadecimal output mode
	// take the value using pptr
	cout << "Value of var :" << var << endl;
	cout << "Value available at *ptr :" << *ptr << endl;
	cout << "Value available at **pptr :" << **pptr << endl;

    function<int()> fcnPtr;
    fcnPtr = localTimeCheck;
    fcnPtr();
    return 0;
	//j = *p; ERROR
	//now x==xref==3
}

int argumentsTest(int args,...)
{
    va_list ap;
    va_start(ap,args);
    int i, summ;
    for(i=0;i<args;i++)
        printf("Summ: %i\n",va_arg(ap,int));
    summ = va_arg(ap,int);
    va_end(ap);
    return summ;
}

int dataTypeSizeTest()
{
	cout << "Size of char : " << sizeof(char) << " byte" << endl;
	cout << "Size of int : " << sizeof(int)	<< " bytes" << endl;
	cout << "Size of short int : " << sizeof(short int)	<< " bytes" << endl;
	cout << "Size of long int : " << sizeof(long int) << " bytes" << endl;
	cout << "Size of signed long int : " << sizeof(signed long int)	<< " bytes" << endl;
	cout << "Size of unsigned long int : " << sizeof(unsigned long int)	<< " bytes" << endl;
	cout << "Size of float : " << sizeof(float)	<< " bytes" << endl;
	cout << "Size of double : " << sizeof(double) << " bytes" << endl;
	cout << "Size of wchar_t : " << sizeof(wchar_t)	<< " bytes" << endl;

    return 0;
}
//--------------------------------time measurement functions
int timerFunction(int(func)())
{
	auto start = high_resolution_clock::now();

	// unsync the I/O of C and C++. 
	ios_base::sync_with_stdio(false);

	func();

	auto end = high_resolution_clock::now();

	// Calculating total time taken by the program. 
	double time_taken = duration_cast<nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	cout << "Time taken by function is : " << fixed << time_taken << setprecision(9);
	cout << " sec" << endl;
    return 0;
}

int preprocessingTest()
{
	cout<<__func__<<endl;//print the name of the function
	cout<<"Minimum of 20 and 30 = "<<MIN(20, 30)<<endl;
	cout<<"Maximum of 20 and 30 = "<<MAX(20, 30)<<endl;
	cout<<MKSTR(HELLO C++)<<endl;
	cout<<"Value of __LINE__ : "<< __LINE__<<endl;
	cout<<"Value of __FILE__ : "<< __FILE__<<endl;
	cout<<"Value of __DATE__ : "<< __DATE__<<endl;
	cout<<"Value of __TIME__ : "<< __TIME__<<endl;
	cout<<"Multiplication = "<<MULTIPLY(20, 30)<<endl;
	cout<<RECEIVE(GeeksQuiz)<<endl;
    return 0;
}