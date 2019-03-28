#include <algorithm>
#include <iostream>
using namespace std;

//Learn:��̬�滮����ȷ�������ʽд�������߽��ʼ�� 
class Bonus {
public:
    int getMost(vector<vector<int>>& board) 
	{
        if (board.empty() || board[0].empty())
            return 0;

		int row = board.size();
		int col = board[0].size();
		vector<vector<int> > dp(row, vector<int>(col, 0));
		//1.���¶��ϵĶ����ʼ��
		dp[0][0] = board[0][0];
		for(int i=1; i<row; i++)
			dp[i][0] = dp[i-1][0] + board[i][0];
		for(int j=1; j<col; j++)
			dp[0][j] = dp[0][j-1] + board[0][j];
			
		for (int i = 0; i < row; i++)
		{
        	for (int j = 0; j < col; j++) 
			{
            	cout<< dp[i][j]<<" ";
        	}
        }
			
		//2.ÿ��������ѡ�����,���յõ�����Ľ� 
		for(int i = 1; i < row; i++)
			for(int j = 1; j < col; j++)
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + board[i][j];
		int res = dp[row-1][col-1];
	//	delete[][] dp;
		return res; 
	}
};

//class Bonus {
//public:
//    int getMost(vector<vector<int>>& board) {
//        if (board.empty() || board[0].empty())
//            return 0;
//        
//        int n = board[0].size();
//        vector<int> dp(n, 0);     // ע�ⲻ�� dp(0, n)
//        
//        for (auto& v: board) {
//            dp[0] += v[0];
//            for (int i=1; i<n; i++)
//                dp[i] = max(dp[i], dp[i-1]) + v[i];
//        }
//        
//        return dp[n-1];
//    }
//
//};
int main(void)
{
//
//	vector<string> ret = T.Permutation(test);
//	vector<vector<int> > arr(a, a+sizeof(a)/sizeof(int));
	vector<vector<int> > arr = {{1,10,3,8},{12,2,9,6},{5,7,4,11},{3,7,16,5}};
	Bonus T;
	cout << T.getMost(arr);
	return 0;	
} 
