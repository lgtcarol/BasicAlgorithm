// ������21����������˳��ʹ����λ��ż��ǰ��
// ��Ŀ������һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ������
// ����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�

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

// ====================���Դ���====================
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
/* ����
1. while�µ�ָ���ƶ��ͻ���Ҫ�߽����
2. ָ�뺯����߷����������������֣�	
��1�������б��а���ָ�뺯������һ�������ĺ�����void Reorder(int *pData, unsigned int length, bool (*func)(int));
	�������ʽ����ͨ�������������𣺺�������ǰ��*���β��б���Ҫ�����
��2����������������ʱ���β�ʵ������	Reorder(pData, length, isEven);
	���Է��ֵ�������������������������ͨ�����ĺ��������ѣ����ú�������ֵ������������Reorder�������while(s<e && !func(*s))  
**/


























