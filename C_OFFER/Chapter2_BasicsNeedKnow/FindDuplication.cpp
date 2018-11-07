#include <cstdio>
#include <cstring>
using namespace std;
//#include <cstdlib>
bool duplicate(int nums[], int length, int *dup)
{
	if(nums==NULL || length<=0)
		return false;
	for(int i = 0; i < length; i++)
		if(nums[i]<0 || nums[i]>=length)
			return false;
	for(int i = 0; i < length; i++)
		//位置i处未放置正确元素,反而错放nums[i] 
		//之所以用while是直到当前位置放置好对的元素，即遍历的目标是在i位放数据i 
		//那么一旦有元素还没放好但它的正确位置上却是个正确元素，则该元素重复 
		while(i != nums[i] ) 
		{
			//nums[i]正确放置的地方却有正确元素，证明至少nums[i]出现两次 
			if(nums[i] == nums[nums[i]])
			{
				*dup = nums[i];//别忘了要带参回去！ 
				return true; 
			} 
			//帮i位调整试图找到它的主儿
			//方法是：把i位当前的元素不断物归原主
			int temp = nums[i];
			nums[i] = nums[nums[i]];
			//出现非常低级的bug: nums[nums[i]] = temp;竟然用起废弃的值！！太差劲！ 
			nums[temp] = temp;
		}
	//如若上述过程没有退出，说明0-(length-1)正好与其下标对应，无重复元素
	return false; 
}
//-------------------测试代码---------------------------
bool contains(int array[], int length, int number)
{
    for(int i = 0; i < length; ++i)
    {
        if(array[i] == number)
            return true;
    }

    return false;
}

void test(const char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
    printf("%s begins: ", testName);

    int duplication;
    bool validInput = duplicate(numbers, lengthNumbers, &duplication);
	//------lgt test-----
	//printf("validInput: %c",validInput);
	printf("hello");
    if(validArgument == validInput)
    {
        if(validArgument)
        {
            if(contains(expected, expectedExpected, duplication))
                printf("Passed.\n");
            else
                printf("FAILED.\n");
        }
        else
            printf("Passed.\n");
    }
    else
        printf("FAILED.\n");
}

// 重复的数字是数组中最小的数字
void test1()
{
    int numbers[] = { 2, 1, 3, 1, 4 };
    int duplications[] = { 1 };
    test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 重复的数字是数组中最大的数字
void test2()
{
    int numbers[] = { 2, 4, 3, 1, 4 };
    int duplications[] = { 4 };
    test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 数组中存在多个重复的数字
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplications[] = { 2, 4 };
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 没有重复的数字
void test5()
{
    int numbers[] = { 2, 1, 3, 5, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test6()
{
    int* numbers = NULL;
    int duplications[] = { -1 }; // not in use in the test function
    test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}

int  main(void)
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
} 
