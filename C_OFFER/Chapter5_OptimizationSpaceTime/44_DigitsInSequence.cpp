// 面试题44：数字序列中某一位的数字
// 题目：数字以0123456789101112131415…的格式序列化到一个字符序列中。在这
// 个序列中，第5位（从0开始计数）是5，第13位是1，第19位是4，等等。请写一
// 个函数求任意位对应的数字。

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

/**
(1) 摸出规律切忌急于求成，逐步分解确定思路框架，逐部分析结合具体实例。
(2) 思维突破：要先猜或思考出实现什么功能，带着思路理解code.
              如果不行，则自己依据思路设计整个过程。
			  回头再看可能发现 该code 是思维的升级版，或者是更便捷的版本。
    ！在得知整数确定index对应的值时，我想出了笨的常规解法。
(3) 当参数中出现" 做差 "时，要考虑差值范围的正否。如 n-1=0时为0位数，可不是pow(10,0)能描述的，要单独处理
(4) 思维妙招：若共5位数，正2和倒3指的同一位。如今本就多算了一个整数，倒着数将错就错。同时，逐个取出整数的每位本就适合倒取(因不用考虑整数位数) 
(5) 要求：框架易有，思路要坚，给自己深入下去的练习 
*/ 


int countOfIntegers(int digits);
int digitAtIndex(int index, int digits);
int beginNumber(int digits);

int digitAtIndex(int index)
{
	if(index < 0)
		return -1;

	int digits = 1;
	while(true)
	{
		int numbers = countOfIntegers(digits);
		if(index < numbers * digits)
			return digitAtIndex(index, digits);

		index -= digits * numbers;
		digits++;
	}

	return -1;
}

int countOfIntegers(int digits)
{
	if(digits == 1)
		return 10;
	digits--;
	return 9*countOfIntegers(digits);
}

//此函数耗时有点多，属于思路混乱，先自己别乱再看他人代码 
int digitAtIndex(int index, int d)
{
	int num = beginNumber(d) + index/d;
	int indexFromRight = d  - 	index%d;
	for(int i = 1; i < indexFromRight; ++i)
		num /= 10;
	return num % 10;
	
}
int beginNumber(int digits)
{
	if(digits == 1)
		return 0;

	return pow(10, digits - 1);
}

// ====================测试代码====================
void test(const char* testName, int inputIndex, int expectedOutput)
{
	if(digitAtIndex(inputIndex) == expectedOutput)
		cout << testName << " passed." << endl;
	else
		cout << testName << " FAILED." << endl;
}

int main()
{
	test("Test1", 0, 0);
	test("Test2", 1, 1);
	test("Test3", 9, 9);
	test("Test4", 10, 1);
	test("Test5", 189, 9);  // 数字99的最后一位，9
	test("Test6", 190, 1);  // 数字100的第一位，1
	test("Test7", 1000, 3); // 数字370的第一位，3
	test("Test8", 1001, 7); // 数字370的第二位，7
	test("Test9", 1002, 0); // 数字370的第三位，0
	return 0;
}
























































