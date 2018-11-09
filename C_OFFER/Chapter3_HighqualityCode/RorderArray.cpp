// 面试题21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。

#include <cstdio>

void Reorder(int *pData, unsigned int length, bool (*func)(int));
bool isEven(int n);

void ReorderOddEven_1(int *pData, unsigned int length)
{
	if(pData == NULL || length <= 0)
		return ;
	int *s = pData;
	int *e = pData + length -1;
	while(s < e)
	{
		while(s<e && (*s & 0x1)!=0)
			s++;
		while(s<e && (*e & 0x1)==0)
			e--;
		int t = *s;
		*s = *e;
		*e = t;
	}
}

void ReorderOddEven_2(int *pData, unsigned int length)
{
	Reorder(pData, length, isEven);
}
void Reorder(int *pData, unsigned int length, bool (*func)(int))
{
	if(pData == NULL || length <= 0)
		return ;
	int *s = pData;
	int *e = pData + length -1;
	while(s < e)
	{
		while(s<e && !func(*s))
			s++;
		while(s<e && func(*e))
			e--;
		int t = *s;
		*s = *e;
		*e = t;
	}	
}
bool isEven(int t)
{
	if(t&0x1 != 0)
		return true;
	else
		return false;
}

// ====================测试代码====================
void PrintArray(int numbers[], int length)
{
    if(length < 0)
        return;

    for(int i = 0; i < length; ++i)
        printf("%d\t", numbers[i]);

    printf("\n");
}

void Test(const char* testName, int numbers[], int length)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    int* copy = new int[length];
    for(int i = 0; i < length; ++i)
    {
        copy[i] = numbers[i];
    }

    printf("Test for solution 1:\n");
    PrintArray(numbers, length);
    ReorderOddEven_1(numbers, length);
    PrintArray(numbers, length);

    printf("Test for solution 2:\n");
    PrintArray(copy, length);
    ReorderOddEven_2(copy, length);
    PrintArray(copy, length);

    delete[] copy;
}

void Test1()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    Test("Test1", numbers, sizeof(numbers)/sizeof(int));
}

void Test2()
{
    int numbers[] = {2, 4, 6, 1, 3, 5, 7};
    Test("Test2", numbers, sizeof(numbers)/sizeof(int));
}

void Test3()
{
    int numbers[] = {1, 3, 5, 7, 2, 4, 6};
    Test("Test3", numbers, sizeof(numbers)/sizeof(int));
}

void Test4()
{
    int numbers[] = {1};
    Test("Test4", numbers, sizeof(numbers)/sizeof(int));
}

void Test5()
{
    int numbers[] = {2};
    Test("Test5", numbers, sizeof(numbers)/sizeof(int));
}

void Test6()
{
    Test("Test6", NULL, 0);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
/* 感悟：
1. while下的指针移动就会需要边界控制
2. 指针函数提高泛化能力。分两部分：	
（1）参数列表中包含指针函数这样一个变量的函数：void Reorder(int *pData, unsigned int length, bool (*func)(int));
	其参数形式较普通函数声明的区别：函数名称前加*，形参列表不需要虚变量
（2）调用上述函数的时候将形参实例化：	Reorder(pData, length, isEven);
	可以发现第三个参数不过就是声明的普通函数的函数名而已，而该函数返回值发挥作用则在Reorder函数体里：while(s<e && !func(*s))  
**/


























