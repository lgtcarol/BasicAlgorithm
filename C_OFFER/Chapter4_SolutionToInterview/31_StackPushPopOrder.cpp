#include <cstdio>
#include <stack>
using namespace std;
/**
(1)方法思路(如何使用这两个条件，或者两个如何协作切合目标特点)：依据"入栈序列"入栈直到栈顶为"出栈序列"的依次元素 
(2)目标基于思路的意义：若"入栈序列"入栈完毕 且 "出栈序列"全部出栈。
(3)其他情况： "入栈序列"完毕(因入栈没有条件限制正常进行即可故目标状态就是完毕)都没有得到对应 "出栈序列"中某元素（即出栈个数小于长度）
(4)不论如何程序都是要终止的："入栈序列"空了就结束 
(4+) 保险的所有情形通常才是while的控制条件："出栈序列"出栈完毕（但显然此为最乐观，上述是提前终止条件，当发现时再往乐观目标去遍历无意义，但乐观目标才包含最大范围的情况） 
(5)确定返回值：根据题目需求可得为布尔结果 
*/
bool IsPopOrder(const int* pPush, const int* pPop, int nLen)
{
	bool isPossible = false; 
	stack<int> pushData;
	stack<int> popData; //pPop数组类似尺度一般 度量 动态的pushData(其数据来源于pPush) 
	//参数（问题）合理性检验 
	if(pPush==NULL || pPop==NULL || nLen<=0)
		return false;
	//参数保护，尤其指针类型的
	const int *pNPush = pPush;
	const int *pNPop = pPop;
	while(pNPop-pPop < nLen)
	{
		while(pushData.empty() || pushData.top()!=*pNPop)
		{
			if(pNPush-pPush >= nLen)
				break;
			pushData.push(*pNPush);
			pNPush++;	
		}	
		if(pushData.top() != *pNPop)
			break; //达到无论如何的终止条件（正解或结束解）
		pushData.pop();
		pNPop++; 
	}
	if(pNPop-pPop == nLen)
		isPossible = true;
	return isPossible; 
} 
// ====================测试代码====================
void Test(const char* testName, const int* pPush, const int* pPop, int nLength, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(IsPopOrder(pPush, pPop, nLength) == expected)
        printf("Passed.\n");
    else
        printf("failed.\n");
}

void Test1()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 5, 3, 2, 1};
    
    Test("Test1", push, pop, nLength, true);
}

void Test2()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 2, 1};
    
    Test("Test2", push, pop, nLength, true);
}

void Test3()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 3, 5, 1, 2};
    
    Test("Test3", push, pop, nLength, false);
}

void Test4()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 1, 2};
    
    Test("Test4", push, pop, nLength, false);
}

// push和pop序列只有一个数字
void Test5()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {2};

    Test("Test5", push, pop, nLength, false);
}

void Test6()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {1};

    Test("Test6", push, pop, nLength, true);
}

void Test7()
{
    Test("Test7", NULL, NULL, 0, false);
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

    return 0;
}
































































