// 面试题50（一）：字符串中第一个只出现一次的字符
// 题目：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出
// 'b'。

#include <cstdio>
#include <string>

char FirstNotRepeatingChar(const char* s)
{
    if(s == NULL)
        return '\0';	
        
    int *bin = new int[256];
    const char* p = s;
    for(int i = 0; i<256; i++)
    	bin[i] = 0;
    while((*s) != '\0')
    {
    	bin[(*s)]++;
    	s++;
	}
	while((*p) != '\0') //按字符串遍历更节省时间 
	{
		if(bin[*p] == 1)
			return *p;
		p++; 
	}
	return '\0';
}



// ====================测试代码====================
void Test(const char* pString, char expected)
{
    if(FirstNotRepeatingChar(pString) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    // 常规输入测试，存在只出现一次的字符
    Test("google", 'l');

    // 常规输入测试，不存在只出现一次的字符
    Test("aabccdbd", '\0');

    // 常规输入测试，所有字符都只出现一次
    Test("abcdefg", 'a');

    // 鲁棒性测试，输入nullptr
    Test(NULL, '\0');

    return 0;
}
