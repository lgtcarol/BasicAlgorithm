#include <cstdio>
#include <stack>
using namespace std;
/**
(1)����˼·(���ʹ�������������������������Э���к�Ŀ���ص�)������"��ջ����"��ջֱ��ջ��Ϊ"��ջ����"������Ԫ�� 
(2)Ŀ�����˼·�����壺��"��ջ����"��ջ��� �� "��ջ����"ȫ����ջ��
(3)��������� "��ջ����"���(����ջû�����������������м��ɹ�Ŀ��״̬�������)��û�еõ���Ӧ "��ջ����"��ĳԪ�أ�����ջ����С�ڳ��ȣ�
(4)������γ�����Ҫ��ֹ�ģ�"��ջ����"���˾ͽ��� 
(4+) ���յ���������ͨ������while�Ŀ���������"��ջ����"��ջ��ϣ�����Ȼ��Ϊ���ֹۣ���������ǰ��ֹ������������ʱ�����ֹ�Ŀ��ȥ���������壬���ֹ�Ŀ��Ű������Χ������� 
(5)ȷ������ֵ��������Ŀ����ɵ�Ϊ������� 
*/
bool IsPopOrder(const int* pPush, const int* pPop, int nLen)
{
	bool isPossible = false; 
	stack<int> pushData;
	stack<int> popData; //pPop�������Ƴ߶�һ�� ���� ��̬��pushData(��������Դ��pPush) 
	//���������⣩�����Լ��� 
	if(pPush==NULL || pPop==NULL || nLen<=0)
		return false;
	//��������������ָ�����͵�
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
			break; //�ﵽ������ε���ֹ���������������⣩
		pushData.pop();
		pNPop++; 
	}
	if(pNPop-pPop == nLen)
		isPossible = true;
	return isPossible; 
} 
// ====================���Դ���====================
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

// push��pop����ֻ��һ������
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
































































