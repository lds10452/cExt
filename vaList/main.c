#include<stdlib.h>
#include<stdarg.h>
#include<stdio.h>

void printArg(int num, ...)
{
	va_list list;
	va_start(list, num);
	char* str = va_arg(list, char*);
	printf("%s\n", str);
	int value = va_arg(list, int);
	printf("%d\n", value);
	va_end(list);
}

int main()
{
	printArg(5, "string", 0);
	system("pause");
	return 0;
}