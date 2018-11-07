#include <cstdio>
bool matchCore(const char* str, const char *pattern);
bool match(const char* str, const char *pattern)
{
	if(str == NULL || pattern == NULL)
		return false;
	return matchCore(str, pattern);
}
//Note: str指针的移动代表匹配，pattern指针的移动代表模式（有限状态机）的转换 
bool matchCore(const char* str, const char *pattern)
{
	if(*str == '\0' && *pattern == '\0')
		return true;
	if(*pattern == '\0' && *str != '\0')//模式串完才是真的完，因模式串中a*可代码没有，但字符串是什么就是什么 
		return false;

	//Note:对于简单的一对一正常匹配而言，就是*的存在使匹配带来不确定状态（即产生状态机）。
	//Note:故思路显而易见以*作为讨论大类，而*的功效和前个字符捆绑，所以产生当前char+['*']这个思路 
	if(*(pattern+1) == '*') 
	{
		//pattern+2即意味进入模式串状态机的下个状态，pattern即进入自循环状态
		//str+1即意味匹配成功（这是逐个匹配，当然+1就足够）,str即未匹配对应为pattern的0匹配功能所以pattern+2(a*可匹配0个字符) 
		//若当前char匹配上且下个为*,一是下个str还是当前pattern(模式不动)，二是下个str不是当前pattern 
		if(*str==*pattern || (*str!='\0' && *pattern=='.'))
			return matchCore(str+1, pattern+2)||matchCore(str+1, pattern)||matchCore(str, pattern+2);
		else
			return matchCore(str, pattern+2);//当前字符匹配失效，自然发挥a*的0匹配功能 
	}
	else
	{
		if(*str==*pattern || (*str!='\0' && *pattern=='.'))
			return matchCore(str+1, pattern+1);
	}
	//下个字符为*则带来情况的不确定性，否则为普通的匹配过程 
	//Note：由于'.'的特性故要保证其不匹配'\0'  
	//Note: 其实能分析出模式串会先结束 
	return false;
	//if-else分析了匹配情况下的走势，其他一旦不匹配则立刻失败！ 
}

// ====================测试代码====================
void Test(const char* testName, const char* string, const char* pattern, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(match(string, pattern) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    Test("Test01", "", "", true);
    Test("Test02", "", ".*", true);
    Test("Test03", "", ".", false);
    Test("Test04", "", "c*", true);
    Test("Test05", "a", ".*", true);
    Test("Test06", "a", "a.", false);
    Test("Test07", "a", "", false);
    Test("Test08", "a", ".", true);
    Test("Test09", "a", "ab*", true);
    Test("Test10", "a", "ab*a", false);
    Test("Test11", "aa", "aa", true);
    Test("Test12", "aa", "a*", true);
    Test("Test13", "aa", ".*", true);
    Test("Test14", "aa", ".", false);
    Test("Test15", "ab", ".*", true);
    Test("Test16", "ab", ".*", true);
    Test("Test17", "aaa", "aa*", true);
    Test("Test18", "aaa", "aa.a", false);
    Test("Test19", "aaa", "a.a", true);
    Test("Test20", "aaa", ".a", false);
    Test("Test21", "aaa", "a*a", true);
    Test("Test22", "aaa", "ab*a", false);
    Test("Test23", "aaa", "ab*ac*a", true);
    Test("Test24", "aaa", "ab*a*c*a", true);
    Test("Test25", "aaa", ".*", true);
    Test("Test26", "aab", "c*a*b", true);
    Test("Test27", "aaca", "ab*a*c*a", true);
    Test("Test28", "aaba", "ab*a*c*a", false);
    Test("Test29", "bbbba", ".*a*a", true);
    Test("Test30", "bcbbabab", ".*a*a", false);

    return 0;
}
//感悟：模式串带来的随机性使得情况的分类着实是根据有限状态机进行的，思路是字符串可以走哪条分支。 
