// 面试题48：最长不含重复字符的子字符串
// 题目：请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子
// 字符串的长度。假设字符串中只包含从'a'到'z'的字符。
#include <string>
#include <iostream>

/**
本题的传统解法和递归设计都很值得体味
对比下此类动规思路的设计！ 
*/ 

// 方法一：蛮力法
bool hasDuplication(const std::string& str, int position[]);
int longestSubstringWithoutDuplication_1(const std::string& str)
{
	int longest = 0;
	int* position = new int[26];
	for(int start = 0; start < str.length(); ++start)
	{
		for(int end = start; end < str.length(); ++end)
		{
			int count = end - start + 1;
			//NOTE:自己觉得需要三层循环是没有将（判断子串中是否有重复）拉出去
			//      同时由于忽略substr使得直接控制字串的end导致循环设计时思路上的复杂性，因在跳出循环需要多些思考 
			const std::string& substring = str.substr(start, count);//不仅仅是逐个遍历，这是字符串
			if(!hasDuplication(substring, position))
			{
				if(count > longest)
					longest = count;
			} 	 
			else
                break;
		} 
	} 
	delete[] position;
	return longest; 
} 

bool hasDuplication(const std::string& str, int position[])
{
	for(int i = 0; i < 26; ++i)
		position[i] = -1;
		
	for(int i = 0; i < str.length(); ++i)
	{
		int indexInPosition = str[i] - 'a';//因用了桶排序，而每个待哈希值是个字母转换为相应数字 
		if(position[indexInPosition] >= 0)
            return true;//初始值为-1，现发现原桶被占用 
        position[indexInPosition] = indexInPosition;//相应元素放到相应桶内，显然元素至少是0 
	}
	return false; 

}
// 方法二：动态规划
int longestSubstringWithoutDuplication_2(const std::string& str)
{
	int curLength = 0;
    int maxLength = 0;
    
	int* position = new int[26];
    for(int i = 0; i < 26; ++i)
        position[i] = -1;
	for(int i = 0; i < str.length(); ++i)
	{
		int prevIndex = position[str[i] - 'a'];//直接获得在桶中的位置 
		//NOTE：若未出现过(子式 1)或上次出现的位置在有效长度外 (子式 2.2) 
		if(prevIndex < 0 || i - prevIndex > curLength) 
			++curLength;
		else
		{
			if(curLength > maxLength)//正常更新 
                maxLength = curLength;
            //NOTE:递归子式 2.1 
            curLength = i - prevIndex; 
		} 	 
		//NOTE:不同于桶排序中桶中元素的意义，此时原桶-1代表首次出现，而非-1则代表出现位置 
		position[str[i] - 'a'] = i; 
	}
	//最后一步未检查是否需要更新
	if(curLength > maxLength)
        maxLength = curLength;

    delete[] position;
    return maxLength; 
}

// ====================测试代码====================
void testSolution1(const std::string& input, int expected)
{
    int output = longestSubstringWithoutDuplication_1(input);
    if(output == expected)
        std::cout << "Solution 1 passed, with input: " << input << std::endl;
    else
        std::cout << "Solution 1 FAILED, with input: " << input << std::endl;
}

void testSolution2(const std::string& input, int expected)
{
    int output = longestSubstringWithoutDuplication_2(input);
    if(output == expected)
        std::cout << "Solution 2 passed, with input: " << input << std::endl;
    else
        std::cout << "Solution 2 FAILED, with input: " << input << std::endl;
}

void test(const std::string& input, int expected)
{
    testSolution1(input, expected);
    testSolution2(input, expected);
}

void test1()
{
    const std::string input = "abcacfrar";
    int expected = 4;
    test(input, expected);
}

void test2()
{
    const std::string input = "acfrarabc";
    int expected = 4;
    test(input, expected);
}

void test3()
{
    const std::string input = "arabcacfr";
    int expected = 4;
    test(input, expected);
}

void test4()
{
    const std::string input = "aaaa";
    int expected = 1;
    test(input, expected);
}

void test5()
{
    const std::string input = "abcdefg";
    int expected = 7;
    test(input, expected);
}

void test6()
{
    const std::string input = "aaabbbccc";
    int expected = 2;
    test(input, expected);
}

void test7()
{
    const std::string input = "abcdcba";
    int expected = 4;
    test(input, expected);
}

void test8()
{
    const std::string input = "abcdaef";
    int expected = 6;
    test(input, expected);
}

void test9()
{
    const std::string input = "a";
    int expected = 1;
    test(input, expected);
}

void test10()
{
    const std::string input = "";
    int expected = 0;
    test(input, expected);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}












































