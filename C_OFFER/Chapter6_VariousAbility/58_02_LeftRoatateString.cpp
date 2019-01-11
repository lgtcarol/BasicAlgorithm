// ������58������������ת�ַ���
// ��Ŀ���ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
// �붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ����������ַ���"abcdefg"����
// ��2���ú�������������ת2λ�õ��Ľ��"cdefgab"��

#include <cstdio>
#include "Utilities\StringUtil.cpp"
#include <string.h>
/**
1. ��ʵ��(һ)��һ���ģ�ȫ����ת���پֲ���ת����
    �������ڣ�����ֻ���ַ������֣��������ݿո�����while����Reverse���� 
2.  �����ڲ��ĳ���Ҫ�жϳ��ȵĺ����ԣ��籾���n��nLength 
3.   Attention:�Լ�ʵ����c���Ե��ַ�������:strlen,strcmp��  
*/
char* LeftRotateString(char* pStr, int n)
{
    if(pStr != NULL)
    {
       // int nLength = static_cast<int>(strlen(pStr));
        int nLength = strlen(pStr);
        if(nLength > 0 && n > 0 && n < nLength)
        {
            char* pFirstStart = pStr;  
            char* pFirstEnd = pStr + n - 1;
            char* pSecondStart = pStr + n;
            char* pSecondEnd = pStr + nLength - 1;//lgtע�������ַ�������ͨ�����ȿ���λ��ʱҪ�ӳ�ʼָ��λ�� 

            // ��ת�ַ�����ǰ��n���ַ�
            Reverse(pFirstStart, pFirstEnd);
            // ��ת�ַ����ĺ��沿��
            Reverse(pSecondStart, pSecondEnd);
            // ��ת�����ַ���
            Reverse(pFirstStart, pSecondEnd);
        }
    }

    return pStr;
}

// ====================���Դ���====================
void Test(const char* testName, char* input, int num, const char* expectedResult)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    char* result = LeftRotateString(input, num);

    if((input == NULL && expectedResult == NULL)
        || (input != NULL && strcmp(result, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// ���ܲ���
void Test1()
{
    char input[] = "abcdefg";
    char expected[] = "cdefgab";

    Test("Test1", input, 2, expected);
}

// �߽�ֵ����
void Test2()
{
    char input[] = "abcdefg";
    char expected[] = "bcdefga";

    Test("Test2", input, 1, expected);
}

// �߽�ֵ����
void Test3()
{
    char input[] = "abcdefg";
    char expected[] = "gabcdef";

    Test("Test3", input, 6, expected);
}

// ³���Բ���
void Test4()
{
    Test("Test4", NULL, 6, NULL);
}

// ³���Բ���
void Test5()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test5", input, 0, expected);
}

// ³���Բ���
void Test6()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test6", input, 7, expected);
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

