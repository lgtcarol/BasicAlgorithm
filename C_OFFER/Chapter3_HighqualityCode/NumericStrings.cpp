#include <stdio.h>
bool scanUnsignedInteger(const char** str);
bool scanInteger(const char** str)
{
	//attention: *str才是我们要移动的指针 
	if(**str=='-' || **str=='+')
		(*str)++;
	return scanUnsignedInteger(str);//解决正负后，若得到一个纯数则可得到一个数 
}
bool scanUnsignedInteger(const char** str)
{
	//通常判断字串是否为整数，需知道判断谁，而此处显然不知道何处终止
	//按照规则指针有移动则认为我们得到了一个纯数，如何能按此规则局部局部的移动完串，显然也可行
	const char *start = *str;
	while(**str != '\0' && **str >= '0' && **str <= '9') 
		(*str)++;
	return (*str - start)>0;
}
bool isNumeric (const char* str)
{
	if(str == NULL)
		return false;
	bool numeric = scanInteger(&str); //要修改的值是指针故用到二级指针 
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
// ====================测试代码====================
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
//思想上：不过是简单的字符串线性遍历过程，遍历中做的事情就算去匹配规则，而本题需要自己去总结出规则
//实现上：不过是指针的移动和指针内容得比较，再加上情况考虑得完整性（逻辑的 与或 而已，举例子debug可以的）
//连递归什么的都不存在，就是总结规则-->逻辑代码实现--->逻辑完整性，不要怕！ 
