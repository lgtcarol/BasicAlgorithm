#include <stdio.h>
bool scanUnsignedInteger(const char** str);
bool scanInteger(const char** str)
{
	//attention: *str��������Ҫ�ƶ���ָ�� 
	if(**str=='-' || **str=='+')
		(*str)++;
	return scanUnsignedInteger(str);//������������õ�һ��������ɵõ�һ���� 
}
bool scanUnsignedInteger(const char** str)
{
	//ͨ���ж��ִ��Ƿ�Ϊ��������֪���ж�˭�����˴���Ȼ��֪���δ���ֹ
	//���չ���ָ�����ƶ�����Ϊ���ǵõ���һ������������ܰ��˹���ֲ��ֲ����ƶ��괮����ȻҲ����
	const char *start = *str;
	while(**str != '\0' && **str >= '0' && **str <= '9') 
		(*str)++;
	return (*str - start)>0;
}
bool isNumeric (const char* str)
{
	if(str == NULL)
		return false;
	bool numeric = scanInteger(&str); //Ҫ�޸ĵ�ֵ��ָ����õ�����ָ�� 
	if(*str == '.')
	{
		str++;
		numeric = scanUnsignedInteger(&str) || numeric;
	}
	if(*str=='e' || *str=='E')
	{
		str++;
		numeric = scanInteger(&str) && numeric;
	}
	return numeric && *str=='\0';
}
// ====================���Դ���====================
void Test(const char* testName, const char* str, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(isNumeric(str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}


int main(int argc, char* argv[])
{
//    Test("Test1", "100", true);
    Test("Test2", "123.45e+6", true);
    Test("Test3", "+500", true);
//    Test("Test4", "5e2", true);
//    Test("Test5", "3.1416", true);
//    Test("Test6", "600.", true);
    Test("Test7", "-.123", true);
    Test("Test8", "-1E-16", true);
    Test("Test9", "1.79769313486232E+308", true);
//
//    printf("\n\n");
//
//    Test("Test10", "12e", false);
//    Test("Test11", "1a3.14", false);
//    Test("Test12", "1+23", false);
//    Test("Test13", "1.2.3", false);
//    Test("Test14", "+-5", false);
//    Test("Test15", "12e+5.4", false);
//    Test("Test16", ".", false);
//    Test("Test17", ".e1", false);
//    Test("Test18", "e1", false);
//    Test("Test19", "+.", false);
//    Test("Test20", "", false);
//    Test("Test21", NULL, false);

    return 0;
}
//Note:
//˼���ϣ������Ǽ򵥵��ַ������Ա������̣������������������ȥƥ����򣬶�������Ҫ�Լ�ȥ�ܽ������
//ʵ���ϣ�������ָ����ƶ���ָ�����ݵñȽϣ��ټ���������ǵ������ԣ��߼��� ��� ���ѣ�������debug���Եģ�
//���ݹ�ʲô�Ķ������ڣ������ܽ����-->�߼�����ʵ��--->�߼������ԣ���Ҫ�£� 
