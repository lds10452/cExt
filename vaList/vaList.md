```
#define va_list char *
```

va_start(ap, last_arg)：初始化可变参数列表。ap 是一个 va_list 类型的变量，last_arg 是最后一个固定参数的名称（也就是可变参数列表之前的参数）。该宏将 ap 指向可变参数列表中的第一个参数。

```
// 指向可变参数的第一个
#define va_start(ap,v) ( ap = (va_list)&v + _INTSIZEOF(v) )
```

va_arg(ap, type)：获取可变参数列表中的值。ap 是一个 va_list 类型的变量，type 是参数的类型。该宏返回类型为 type 的值，并将 ap 指向下一个参数。

```
// ap 自增 sizeof(t)，然后减去 sizeof(t)，顺序获取参数的值
#define va_arg(ap,t) ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
```

va_end(ap)：结束可变参数列表的访问。ap 是一个 va_list 类型的变量。该宏将 ap 置为 NULL。

```
// 指针清零
#define va_end(ap) (ap = ((va_list)0))
```

例：

```
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

输出：
string
0
```

