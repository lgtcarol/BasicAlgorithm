#include <cstdio>
/**
(1) ���ڸ��������ֵ��ʼ��Ӧ��С��Ϊ int����Сֵ����0 
(2) �����ϵ����䲻��ֻ��continue, if-elseҲ�ܺã�����sum�������ھֲ����⣬����continueʹ��max�����߼��״�
(3) max���µ�λ�úܹؼ�����sum������Ͳ���ǰ����ܴ����ʱӦע�� 
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
    int Max = 0x80000000;//���ԾͰ���intռ32λȥ������� 
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

// ====================���Դ���====================
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

// �������ֶ��Ǹ���
// -2, -8, -1, -5, -9
void Test2()
{
    int data[] = {-2, -8, -1, -5, -9};
    Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// �������ֶ�������
// 2, 8, 1, 5, 9
void Test3()
{
    int data[] = {2, 8, 1, 5, 9};
    Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// ��Ч����
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

