#include <cstdio>
/**
(1) 存在负数的最大值初始化应最小化为 int型最小值而非0 
(2) 互斥关系的语句不是只有continue, if-else也很好，本题sum更新属于局部互斥，若用continue使得max更新逻辑易错
(3) max更新的位置很关键，在sum操作后和操作前区别很大，设计时应注意 
*/
bool g_InvalidInput = false;
int FindGreatestSumOfSubArray(int *p, int nLength)
{
	if((p == NULL) || (nLength <= 0))
    {
    	g_InvalidInput = true;
        return 0;
    }
    g_InvalidInput = false;
    int sum = 0;
    int Max = 0x80000000;//所以就按着int占32位去考虑设计 
    for(int i = 0; i < nLength; i++)
    {
    	
    	if(sum <= 0)
    	{
    		sum = p[i];
		}
		else
			sum += p[i];
		if(sum > Max)
    		Max = sum;
	}
	if(sum > Max)
		Max = sum;
	return Max;
} 

// ====================测试代码====================
void Test(const char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);

    int result = FindGreatestSumOfSubArray(pData, nLength);
    if(result == expected && expectedFlag == g_InvalidInput)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
    Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// 所有数字都是负数
// -2, -8, -1, -5, -9
void Test2()
{
    int data[] = {-2, -8, -1, -5, -9};
    Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// 所有数字都是正数
// 2, 8, 1, 5, 9
void Test3()
{
    int data[] = {2, 8, 1, 5, 9};
    Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// 无效输入
void Test4()
{
    Test("Test4", NULL, 0, 0, true);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}

