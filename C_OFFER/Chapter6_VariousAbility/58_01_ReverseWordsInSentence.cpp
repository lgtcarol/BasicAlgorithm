// 面试题58（一）：翻转单词顺序
// 题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
// 为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，
// 则输出"student. a am I"。

#include <cstdio>
#include "Utilities\StringUtil.cpp"
#include <string>
#include <string.h>
using namespace std; 
/**
1. Reverse函数和数组逆序一样，区别就是不用数组下标而是头尾两个 指针即可（注意传递指针作为形参）
2. ERROR：在以空格作为单词处理的区分单位时，未考虑刚开始若为空格的情况。 
3. 关于库版本 https://www.cnblogs.com/xiongyunqi/p/4389301.html
   一般一个C++的老标准带“.h”扩展名的库文件，与新标准后的标准库中都有一个不带“.h”扩展名的相对应，
   区别除了后者的好多改进之外，还有一点就是后者的东东都塞进了“std”名字空间中。但唯独string特别
   其中<cstring>是与C标准库的<string.h>相对应 
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

    // 翻转整个句子
    Reverse(pBegin, pEnd);

    // 翻转句子中的每个单词
    pBegin = pEnd = pData;
    while(*pBegin != '\0')
    {
        if(*pBegin == ' ') //lgt忽略的情况！ 
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

// ====================测试代码====================
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

// 功能测试，句子中有多个单词
void Test1()
{
    char input[] = "I am a student.";
    char expected[] = "student. a am I";

    Test("Test1", input, expected);
}

// 功能测试，句子中只有一个单词
void Test2()
{
    char input[] = "Wonderful";
    char expected[] = "Wonderful";

    Test("Test2", input, expected);
}

// 鲁棒性测试
void Test3()
{
    Test("Test3", NULL, NULL);
}

// 边界值测试，测试空字符串
void Test4()
{
    Test("Test4", "", "");
}

// 边界值测试，字符串中只有空格
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
