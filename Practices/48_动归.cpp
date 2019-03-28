#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
//int longestSubstringWithoutDuplication(const string& s) {
//    if (s.length() < 1) return 0;
//    
//    int n = s.length();
//    
//    int maxLen = 0;
//    vector<int> dp(n, 1);        // 长度至少为 1
//    vector<int> book(26, -1);    // 模拟字典
//
//    // dp[0] = 1;
//    book[s[0] - 'a'] = 0;
//    for (int i=1; i < n; i++) {
//        int pre = book[s[i] - 'a'];
//        if (pre < 0 || i - pre > dp[i-1]) {
//            dp[i] = dp[i-1] + 1;
//            maxLen = max(dp[i], maxLen);
//        }
//        else {
//            maxLen = max(dp[i-1], maxLen);
//            dp[i] = i - pre;
//        }
//        book[s[i] - 'a'] = i;
//    }
//    
//    return maxLen;
//}

//暴力 
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


int main() {
	string maxS;
    cout << longestSubstringWithoutDuplication("abcacfrar") << endl;  // 4
    cout << longestSubstringWithoutDuplication("acfrarabc") << endl;  // 4
    cout << longestSubstringWithoutDuplication("arabcacfr") << endl;  // 4
    cout << longestSubstringWithoutDuplication("aaaa") << endl;       // 1 
    cout << longestSubstringWithoutDuplication("abcdefg") << endl;    // 7 
    cout << longestSubstringWithoutDuplication("") << endl;           // 0
    cout << longestSubstringWithoutDuplication("aaabbbccc") << endl;  // 2
    cout << longestSubstringWithoutDuplication("abcdcba") << endl;    // 4
    cout << longestSubstringWithoutDuplication("abcdaef") << endl;    // 6
    return 0;
}



































