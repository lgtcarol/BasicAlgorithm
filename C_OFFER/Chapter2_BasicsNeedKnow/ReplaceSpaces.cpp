#include <cstdio>
#include <cstring>
void ReplaceBlank(char str[], int length)
{
	if(str == NULL && length <= 0)
		return;
	int len1 = strlen(str)-1;//��Ч�ַ������һ���±� 
	int cnt = 0;//��¼�ո���Ŀ 
	int i = 0;//�����ַ���ָ�� 
	while(str[i] != '\0')
	{
		if(str[i] == ' ')
			cnt++;
		i++;
	}
	int len2 = cnt*2 + len1;//������Ч�ַ����һ���±�
	if(len2 > length)
		return;
	while(len1 >= 0 && len1 < len2)
	{
		if(str[len1] != ' ')
		{
			str[len2] = str[len1];//��ֵ  
			len2--;
		}
		else
		{
			str[len2--] = '0';
			str[len2--] = '2';
			str[len2--] = '%';
			
		}
		len1--;
	} 
	 
}
// ====================���Դ���====================
void Test(const char* testName, char str[], int length, const char expected[])
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    ReplaceBlank(str, length);

    if(expected == NULL && str == NULL)
        printf("passed.\n");
    else if(expected == NULL && str != NULL)
        printf("failed.\n");
    else if(strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// �ո��ھ����м�
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";
    Test("Test1", str, length, "hello%20world");
}

// �ո��ھ��ӿ�ͷ
void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    Test("Test2", str, length, "%20helloworld");
}

// �ո��ھ���ĩβ
void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    Test("Test3", str, length, "helloworld%20");
}

// �����������ո�
void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    Test("Test4", str, length, "hello%20%20world");
}

// ����NULL
void Test5()
{
    Test("Test5", NULL, 0, NULL);
}

// ��������Ϊ�յ��ַ���
void Test6()
{
    const int length = 100;

    char str[length] = "";
    Test("Test6", str, length, "");
}

//��������Ϊһ���ո���ַ���
void Test7()
{
    const int length = 100;

    char str[length] = " ";
    Test("Test7", str, length, "%20");
}

// ������ַ���û�пո�
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    Test("Test8", str, length, "helloworld");
}

// ������ַ���ȫ�ǿո�
void Test9()
{
    const int length = 100;

    char str[length] = "   ";
    Test("Test9", str, length, "%20%20%20");
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

    return 0;
}
