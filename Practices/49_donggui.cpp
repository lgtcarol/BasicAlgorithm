#include <vector>
#include <iostream>
using namespace std;
/**
生成思路是东归可以理解。
dp[i] = min(乘2得来， 乘3生成， 乘5生成)
更新（相当于本步状态修改）：
	若乘2得本步，以生成有序数组中乘2的指标移动，由下个去生成
	同理，3
	同理，5
	
难点：生成机制中，用哪个丑数去生成下个数呢？
	  该数是乘2，乘3，还是乘5才是正确s的下个数字 
*/
class Solution {
	int min(int a, int b, int c)
	{
		int t;
		if(a< b)
			t = a;
		else
			t = b;
		if(t > c)
			return c;
		else
			return t;
	}
public:
    int GetUglyNumber_Solution(int index) {
    	int n = index;
    	vector<int> dp(n+1, 0); //保证下标和index刚好等 
    	int id2 = 1;
    	int id3 = 1;
    	int id5 = 1;
    	dp[1] = 1;//默认第一个是1 
    	for(int i = 2; i <=n; i++)
    	{
    		int newData = min(dp[id2]*2, dp[id3]*3, dp[id5]*5);
    		dp[i] = newData;
    		//难点：3个指针的更新问题 
    		if(newData == dp[id2]*2)
    			id2++;
    		if(newData == dp[id3]*3)
    			id3++;
    		if(newData == dp[id5]*5)
    			id5++;
		}
		return dp[n];
    }
}; 
int main(void)
{
	Solution T;
	cout << T.GetUglyNumber_Solution(2) << endl;
	cout << T.GetUglyNumber_Solution(3)<< endl;
	cout << T.GetUglyNumber_Solution(5)<< endl;
	return 0;	
} 
