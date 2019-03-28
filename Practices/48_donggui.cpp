#include <algorithm>
#include <iostream>
#include <vector> 
#include <set>
using namespace std;

//method1:暴力 
int longestSubstringWithoutDuplication(const string& s) 
{
	if(s.size() == 0)
		return 0;
	int max = 0;
	string maxS;
	for(int i = 0; i < s.length(); i++ )
	{
		string tmp = s.substr(i,1);
		int cnt = 1;
		for(int j = i+1; j < s.length(); j++)
		{
			if(tmp.find(s[j],0) < j) //说明重复 
				break; 
			cnt++;
			tmp+=s[j];
		}
		if(max < cnt)
		{
			max = cnt;
			maxS = tmp;
		}
	}
		cout << "the longest you find:" << maxS << endl;
		return max;

	return max; 
}

//method2: 数据结构set可以降低为n^2
//笔记：连续insert相同元素 size不会变化 
int longestSubstringWithoutDuplication(const string &s)
{
	int max = 0;
	int olen = 0;
	int j = 0; 
	for(int i = 0; i < s.length(); i++)
	{
		set<int> ss;
		ss.insert(s[i]);
		for(j = i+1; j<s.length(); j++)
		{
			olen = ss.size();
			ss.insert(s[j]);
			if(ss.size()< olen+1)
				break;
		}
		if(j== s.length())
			olen += 1; //结束原因不一样时的检查 
		if(olen > max)
			max = olen;
	}
	return max;
} 
//method3:动态规划（先确定问题，想表达式） 
int longestSubstringWithoutDuplication(const string &s)
{
	//在你的设计过程中需要哪些变量
	if(s.empty())
		return 0;
	int len = s.length();
	vector<int> fun(len, 1); //公式表达用 //对于每个位置的初始函数值是1 
	vector<int> visited(26, -1); //公式中的条件判断需要辅助，上次的访问状态
	//难点：东归只考虑本步和前步，那怎么叫访问过 
	//易错点：东归根基元素初始化
	visited[s[0]-'a'] = 0; //动态规划一定要注意：由于下标从1开始执行动归，那么第一个位置的基础信息呢？！ 
	for(int i = 1; i < len; i++)
	{
		//对x进行基本判断
		int pre = visited[s[i]-'a'];  //未访问变量一般是负数 
		if(pre<0 || i-pre > fun[i-1] )
			fun[i] = fun[i-1]+1;
		else
			fun[i] = i-pre;
		visited[s[i] - 'a'] = i; //东归经常涉及本步骤的状态或记录变量修改 
	} 
	int max = -1;
	for(int i = 0; i < len; i++)
	{
		if(fun[i] > max)
			max = fun[i];
	}
	return max;
} 


int main() {
    cout << longestSubstringWithoutDuplication("abcacfrar") << endl;  // 4
    cout << longestSubstringWithoutDuplication("acfrarabc") << endl;  // 4
    cout << longestSubstringWithoutDuplication("arabcacfr") << endl;  // 4
    cout << longestSubstringWithoutDuplication("aaaa") << endl;       // 1 
    cout << longestSubstringWithoutDuplication("abcdefg") << endl;    // 7 
    cout << longestSubstringWithoutDuplication("a") << endl;           // 1
    cout << longestSubstringWithoutDuplication("aaabbbccc") << endl;  // 2
    cout << longestSubstringWithoutDuplication("abcdcba") << endl;    // 4
    cout << longestSubstringWithoutDuplication("abcdaef") << endl;    // 6
    
//	set<int> s;
//	s.insert(1);
//	s.insert(1);
//	cout << s.size();
    return 0;
}




































