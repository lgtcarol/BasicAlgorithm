// ������58��һ������ת����˳��
// ��Ŀ������һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣
// Ϊ������������ź���ͨ��ĸһ���������������ַ���"I am a student. "��
// �����"student. a am I"��

#include <cstdio>
#include "Utilities\StringUtil.cpp"
#include <string>
#include <string.h>
using namespace std; 
/**
1. Reverse��������������һ����������ǲ��������±����ͷβ���� ָ�뼴�ɣ�ע�⴫��ָ����Ϊ�βΣ�
2. ERROR�����Կո���Ϊ���ʴ�������ֵ�λʱ��δ���Ǹտ�ʼ��Ϊ�ո������� 
3. ���ڿ�汾 https://www.cnblogs.com/xiongyunqi/p/4389301.html
   һ��һ��C++���ϱ�׼����.h����չ���Ŀ��ļ������±�׼��ı�׼���ж���һ��������.h����չ�������Ӧ��
   ������˺��ߵĺö�Ľ�֮�⣬����һ����Ǻ��ߵĶ����������ˡ�std�����ֿռ��С���Ψ��string�ر�
   ����<cstring>����C��׼���<string.h>���Ӧ 
*/

char* ReverseSentence(char *pData)
{
    if(pData == NULL)
        return NULL;

    char *pBegin = pData;

    char *pEnd = pData;
    while(*pEnd != '\0')
        pEnd ++;
    pEnd--;

    // ��ת��������
    Reverse(pBegin, pEnd);

    // ��ת�����е�ÿ������
    pBegin = pEnd = pData;
    while(*pBegin != '\0')
    {
        if(*pBegin == ' ') //lgt���Ե������ 
        {
            pBegin ++;
            pEnd ++;
        }
        else if(*pEnd == ' ' || *pEnd == '\0')
        {
            Reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        }
        else
            pEnd ++;
    }

    return pData;
}

// ====================���Դ���====================
void Test(const char* testName,  char* input, const char* expectedResult)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    ReverseSentence(input);

    if((input == NULL && expectedResult == NULL)
        || (input != NULL && strcmp(input, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// ���ܲ��ԣ��������ж������
void Test1()
{
    char input[] = "I am a student.";
    char expected[] = "student. a am I";

    Test("Test1", input, expected);
}

// ���ܲ��ԣ�������ֻ��һ������
void Test2()
{
    char input[] = "Wonderful";
    char expected[] = "Wonderful";

    Test("Test2", input, expected);
}

// ³���Բ���
void Test3()
{
    Test("Test3", NULL, NULL);
}

// �߽�ֵ���ԣ����Կ��ַ���
void Test4()
{
    Test("Test4", "", "");
}

// �߽�ֵ���ԣ��ַ�����ֻ�пո�
void Test5()
{
    char input[] = "   ";
    char expected[] = "   ";
    Test("Test5", input, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
