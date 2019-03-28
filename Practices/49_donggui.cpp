#include <vector>
#include <iostream>
using namespace std;
/**
����˼·�Ƕ��������⡣
dp[i] = min(��2������ ��3���ɣ� ��5����)
���£��൱�ڱ���״̬�޸ģ���
	����2�ñ��������������������г�2��ָ���ƶ������¸�ȥ����
	ͬ��3
	ͬ��5
	
�ѵ㣺���ɻ����У����ĸ�����ȥ�����¸����أ�
	  �����ǳ�2����3�����ǳ�5������ȷs���¸����� 
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
    	vector<int> dp(n+1, 0); //��֤�±��index�պõ� 
    	int id2 = 1;
    	int id3 = 1;
    	int id5 = 1;
    	dp[1] = 1;//Ĭ�ϵ�һ����1 
    	for(int i = 2; i <=n; i++)
    	{
    		int newData = min(dp[id2]*2, dp[id3]*3, dp[id5]*5);
    		dp[i] = newData;
    		//�ѵ㣺3��ָ��ĸ������� 
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
