#include <algorithm>
#include <iostream>
using namespace std;

/**
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*/
class Solution {
	string s;
	string tmp;
	int strlen;
	vector<string> ret; //全局 
	vector<int> used;
	
	void dfs(int step){
		if(step == strlen)
		{
			ret.push_back(tmp);//每找到一个结果，则放入最终的数组中。 
			return;
		 } 
		 for(int i = 0; i < strlen; i++)//枚举当前层的所有选择 （for描述的是同级） 
		{
			if(used[i]) //全排列，用过的不用 
				continue;
			if(i > 0 && s[i] == s[i-1] && !used[i-1]) //对于重复字符的处理 
				continue;
			tmp[step] = s[i];
			used[i] = 1; //本步选定，进入下步 
			dfs(step+1);
			used[i] = 0; //对于未从本步出去的自然不该标记 
		}
	}
public:
    vector<string> Permutation(string str) {
        if(str.empty())
        	return vector<string>();
        
        s = str;
        strlen = s.length();
        
        sort(s.begin(), s.end());
        tmp.resize(strlen, '\0'); //辅助变量初始化 
        used.resize(strlen, 0);
        
        dfs(0);
        return ret;
    }
};
int main(void)
{
	string test = "ab";
	Solution T;
	vector<string> ret = T.Permutation(test);
	for(auto it = ret.begin(); it != ret.end(); it++)
		cout  << *it << ' ';
	cout << endl;
	return 0;	
} 
