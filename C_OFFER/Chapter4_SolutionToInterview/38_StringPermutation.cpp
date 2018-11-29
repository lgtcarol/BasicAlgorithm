// 面试题38：字符串的排列
// 题目：输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，
// 则打印出由字符a、b、c所能排列出来的所有字符串abc、acb、bac、bca、cab和cba。

#include <cstdio>
/**
回溯思想还是很明显的，本步选后面任一字符交换（for循环控制有序），进入下一层，递归返回时恢复本步(便于同等状态进for) 
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

// ====================测试代码====================
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


