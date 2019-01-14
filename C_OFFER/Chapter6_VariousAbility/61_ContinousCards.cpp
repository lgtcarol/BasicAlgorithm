// 面试题61：扑克牌的顺子
// 题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
// 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王可以看成任意数字。

#include <cstdio>
#include <cstdlib>
/**
脱离背景抽象为实质性问题就是一个数列的按规则判断问题，放到扑克牌背景下更好解释或定义规则
1. 对数组进行排序，定义 Compare函数为升序
2. 统计魔法数字0的个数
3.  
*/ 
int Compare(const void *arg1, const void *arg2);
bool IsContinuous(int* numbers, int length)
{
    if(numbers == NULL || length < 1)
        return false;
    qsort(numbers, length, sizeof(int), Compare);
    int numberOfZero = 0;
    int numberOfGap = 0;
    
    for(int i = 0; i < length && numbers[i] == 0; ++i)
        ++numberOfZero;
    
    //lgt的实现更好理解 
    int norm =  numberOfZero+1;
    for(; norm<length; norm++)
    {
    	if(numbers[norm] == numbers[norm-1]) //ATRENTION:特殊情况又忽略了！相等会被for处理吞没但实际这是不符合要求的！ 
    		return false;
    	int gap = numbers[norm]-numbers[norm-1]-1;
    	numberOfGap += gap;
	}
//    int small = numberOfZero; //0的个数 
//    int big = small + 1; //其他数字个数起点，控制考虑过的牌的张数 
//
//	while(big < length)
//	{
//		if(numbers[small] == numbers[big])
//            return false;
//        numberOfGap += numbers[big] - numbers[small] - 1;//所消耗的0个数
//		small = big;
//		++big; 
//	} 
	return (numberOfGap > numberOfZero) ? false : true;
} 
int Compare(const void *arg1, const void *arg2)
{
    return *(int*) arg1 - *(int*) arg2;
}
// ====================测试代码====================
void Test(const char* testName, int* numbers, int length, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(IsContinuous(numbers, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1()
{
    int numbers[] = { 1, 3, 2, 5, 4 };
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test2()
{
    int numbers[] = { 1, 3, 2, 6, 4 };
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test3()
{
    int numbers[] = { 0, 3, 2, 6, 4 };
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test4()
{
    int numbers[] = { 0, 3, 1, 6, 4 };
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test5()
{
    int numbers[] = { 1, 3, 0, 5, 0 };
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test6()
{
    int numbers[] = { 1, 3, 0, 7, 0 };
    Test("Test6", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test7()
{
    int numbers[] = { 1, 0, 0, 5, 0 };
    Test("Test7", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test8()
{
    int numbers[] = { 1, 0, 0, 7, 0 };
    Test("Test8", numbers, sizeof(numbers) / sizeof(int), false);
}

void Test9()
{
    int numbers[] = { 3, 0, 0, 0, 0 };
    Test("Test9", numbers, sizeof(numbers) / sizeof(int), true);
}

void Test10()
{
    int numbers[] = { 0, 0, 0, 0, 0 };
    Test("Test10", numbers, sizeof(numbers) / sizeof(int), true);
}

// 有对子
void Test11()
{
    int numbers[] = { 1, 0, 0, 1, 0 };
    Test("Test11", numbers, sizeof(numbers) / sizeof(int), false);
}

// 鲁棒性测试
void Test12()
{
    Test("Test12", NULL, 0, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();
    Test12();

    return 0;
}
