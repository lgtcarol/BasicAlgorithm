// ������38���ַ���������
// ��Ŀ������һ���ַ�������ӡ�����ַ������ַ����������С����������ַ���abc��
// ���ӡ�����ַ�a��b��c�������г����������ַ���abc��acb��bac��bca��cab��cba��

#include <cstdio>
/**
����˼�뻹�Ǻ����Եģ�����ѡ������һ�ַ�������forѭ���������򣩣�������һ�㣬�ݹ鷵��ʱ�ָ�����(����ͬ��״̬��for) 
*/
void Permutation(char* pStr, char* pBegin);

void Permutation(char *s)
{
	if(s == NULL)
		return;
	Permutation(s, s);
}

void Permutation(char*s, char *pB)
{
	if(*pB == '\0')
		printf("%s\n",s);
	else
	{
		for(char *ch = pB; *ch!='\0'; ch++)
		{
			char t = *pB;
			*pB = *ch;
			*ch = t;
			
			Permutation(s, pB+1);
						
			t = *pB;
			*pB = *ch;
			*ch = t;
			 
		}
	}
}

// ====================���Դ���====================
void Test(char* pStr)
{
    if(pStr == NULL)
        printf("Test for NULL begins:\n");
    else
        printf("Test for %s begins:\n", pStr);

    Permutation(pStr);

    printf("\n");
}

int main(int argc, char* argv[])
{
    Test(NULL);

    char string1[] = "";
    Test(string1);

    char string2[] = "a";
    Test(string2);

    char string3[] = "ab";
    Test(string3);

    char string4[] = "abc";
    Test(string4);

    return 0;
}


