/*
    Tutorial.c
    The module represents my demo functions and its assessment.

    Sandbox

    Created by alimovlex.
    Copyright (c) 2020 alimovlex. All rights reserved.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <errno.h>
#include <math.h>
#include <tgmath.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <float.h>
#include <pthread.h>
#include <ctype.h>
//#include <Block.h>

//Preprocessing section-------------------------------
#define MIN(a,b) (((a)<(b)) ? a : b)
#define MAX(a,b) (((a)>(b)) ? a : b)
#define MULTIPLY(a, b) a*b 
#define merge(a, b) a##b 
#define get(a) #a 
#define MKSTR( x ) #x
#define B(x) StringToBinary_(#x)
unsigned long long StringToBinary_(const char *s)
{
	unsigned long long i = 0;
	while (*s)
	{
		i <<= 1;
		i += *s++ - '0';
	}
	return i;
}
//----------------------------ENDING---------------------

typedef struct Blank
{
    float total;
    int count;
    int tax_percent;
}Box;

typedef struct SizeOfTypes
{
    int i; //4 bytes
    __int8_t k; //1 byte
    __int16_t l; //2 byte
    __int32_t m; //4 byte
    __int64_t n; //8 byte
    long int j; //8 byte
    float f; //4 byte
    double g; //8 byte
    long double h; //8 byte
    char str[0]; //1 byte
}TypeSize;

int characterSetTest()
{
	srand((unsigned)time(NULL));
	int hex = rand() % 0xFFF;
	int dec = rand() % 20;
	int bin = rand() % B(111);
	int oct = rand() % 020;
	int i = 0;
	printf("\nHexadecimal number:0x%02X \n", hex); //hexadecimal output
	printf("Decimal RND number: %d\n", dec);
	printf("Binary RND number: %d\n", bin);
	printf("Octal RND number: %o\n", oct);
	printf("Oct and Hex numbers: %o 0x%02X\n", oct, hex);
	printf("~hex = 0x%02X\n", ~hex);
	printf("bin<<1 = %d\n", bin << 2);
	printf("bin>>1 = %d\n", bin >> 2);
	printf("postfix = %i\n", i++);//i=1
	printf("prefix = %i\n", ++i);
	printf("In C programming All graphic "
		"characters are: \n");
	for (i = 0; i <= 127; ++i)
		if (isgraph(i) != 0)
			printf("%c ", i);
	printf("\n");
    return 0;
	//Fn();
	//free(sizeof(struct numbers));
}

int listFiles()
{
	DIR *dp;
	struct dirent *ep;

	dp = opendir("./");
	if (dp != NULL)
	{
		while (ep = readdir(dp))
			puts(ep->d_name);
		(void)closedir(dp);
	}
	else {
        perror("Couldn't open the directory");
        return -1;
    }
    return 0;
}

int testingPointers(int *p, void *ptr, int(funcPtr)())
{
    //Dynamic structure initialization
    Box *m = (Box*)malloc(sizeof(Box));
    m->count = 100.0;
    m->tax_percent = 200;
    m->tax_percent = 100;
    Box num =  { 100.0, 200,100 };// C11 struct init
    printf("The size of the structure box has on the heap %ld bytes and "
           "%ld bytes on the stack\n",sizeof(m),sizeof(num));//sizes
    free(m);
    //------------------Ending---------------------
	int  i = 0,a=10;
	float y = 5.5;
	int **z = &p;
	**z = 70;
	printf("p contains address %p\n", p);
	printf("p is pointing to the value %d\n", *p); //error creating threads.p is pointing to value 70
	// (int*)ptr - does type casting of void  
	// *((int*)ptr) dereferences the typecasted  
	// void pointer variable. 
	printf("Integer variable is = %d\n", *((int*)ptr));
	// void pointer is now float 
	ptr = &y;
	printf("Float variable is= %.2f\n", *((float*)ptr));
    printf("funcPtr contains address %p\n", funcPtr);
    return 0;
}

int pointersTest()
{
	static int sa = 10; //example of static variable (it saves its value over each function calling)
	int j = 63, x = 4, i = 0, a = 10;
	a += 5;
	sa += 5;
	printf("a = %d, sa = %d\n", a, sa);
	printf("The address of j is %p\n", &j);
	printf("The value of j is %d\n", j);
        printf("address of function pointersTest is :%p\n", pointersTest);
    return 0;
}

int fileTest()
{
	//writing to file
	FILE *fp= fopen("test.txt", "w+");
	char buff[255];
	int descriptor = fileno(fp);
	if (fp == NULL)
	{
		fprintf(stderr, "\nError opend file\n");
		fclose(fp);
        return -1;
	}
	else
	{
		fprintf(fp, "This is testing for fprintf...\n");
		fputs("This is testing for fputs...\n", fp);
                printf("The file descriptor is %d\n", descriptor);
		fclose(fp);
	}
	//reading the file
	fp = fopen("test.txt", "r");
	while (fgets(buff, sizeof(buff), fp))
	{
		printf("%s\n", buff);
	}
	fclose(fp);
    return 0;
	/*while (!feof(fp))
	{
	fgets(buff, 255, (FILE*)fp);
	//fscanf(fp, "%s", buff);
	printf("%s\n", buff);
	}
	*/
}

int preprocessingTest()
{
	printf("%s\n", __func__);//print the name of the function
	printf("Minimum of 20 and 30 = %d\n", MIN(20, 30));
	printf("Maximum of 20 and 30 = %d\n", MAX(20, 30));
	printf(MKSTR(HELLO C++));
	printf("\nValue of __LINE__ : %d\n", __LINE__);
	printf("Value of __FILE__ : %s\n", __FILE__);
	printf("\nValue of __DATE__ : %s\n", __DATE__);
	printf("\nValue of __TIME__ : %s\n", __TIME__);
	printf("Multiplication = %d\n", MULTIPLY(20, 30));
	//printf(merge("Hello ", "World\n"));
	printf("%s\n", get(GeeksQuiz));
	//printf("\a"); signal exclamation
    return 0;
}

int dataTypeSizeTest()
{
	float x = 0.1;
	long int a = 1;
	__int8_t z = 2;
	char b = 'G';
	long double c = 3.14;
	struct SizeOfTypes;
	//-------------------------------printing the variables defined above along with their sizes 
	printf("Size of char %ld\n",sizeof(b));
	printf("Size of long int %ld\n",sizeof(a));
	printf("Size of long double %ld\n", sizeof(c));
	printf("Size of float %ld\n", sizeof(x));
	printf("Size of int %ld\n", sizeof(z));
	printf("Size of structure of data types %ld\n", sizeof(TypeSize));
        printf("Value of INT_MAX %d\n", INT_MAX);
        printf("Value of INT_MIN %d\n", INT_MIN);
        printf("Value of FLT_MAX %f\n", FLT_MAX);
        printf("Value of FLT_MIN %f\n", FLT_MIN);
    return 0;
}

void timerFunction(int(func)())
{
    clock_t t;
    t = clock();
    func();
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("function %s took %f seconds to execute \n", __FUNCTION__, time_taken);
}

int localTimeCheck()
{
	time_t t;
	struct tm *tmp;
	char MY_TIME[50];
	time(&t);
	//localtime() uses the time pointed by t , 
	// to fill a tm structure with the  
	// values that represent the  
	// corresponding local time. 
	tmp = localtime(&t);
	// using strftime to display time 
	strftime(MY_TIME, sizeof(MY_TIME), "%x - %I:%M%p", tmp);
	printf("Formatted date & time : %s\n", MY_TIME);
	return 0;
}

int argumentsTest(int args,...)
{
    va_list ap;
    va_start(ap,args);
    int summ = va_arg(ap,int);
    int i;
    for(i=0;i<args;i++)
        printf("Arguments Summ: %i\n", va_arg(ap,int));
    va_end(ap);
    return summ;
}

int sandbox()
{
    return 0;
}




