/**
（1）当 i == j 时，那么毫无疑问 dp[i][j] = true；
（2）当 i + 1 == j 时，那么 dp[i][j] 取决于 s[i] == s[j]；
（3）当 i + 1 < j 时，那么 dp[i][j] 取决于 dp[i + 1][j - 1] && s[i] == s[j]。
 时间复杂度为O(n^2)，空间复杂度为O(n^2)。
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len <= 1)
            return s;
        int st = 0, endi = 0;//记录最长回归串的起点，终点
       // bool dp[][] = new bool[len][len]; c++中二维数组申请是逐维申请的
       bool ** dp = new bool* [len];
       for(int i = 0; i < len; i++)
       {
           dp[i] = new bool[len];
       }
       int i, j;
       for(j = 0; j < len; j++)
       {
           dp[j][j] = true; //（1）
           //在二维矩阵中的行走方向是:各行对角线（1）,对角线向上平移一格的值可得（2），其他走势是斜上（3）
           for(i = 0; i < j; i++)
           {
                if(i+1 == j)
                    dp[i][j] = (s[i] == s[j]); //（2）
                else
                    dp[i][j] = (dp[i+1][j-1] && s[j]==s[i]); //（3）
                if(dp[i][j] && j-i > endi-st)
                {
                    st = i;
                    endi = j;
                }//更新保存最长结果
           }

       }
        return s.substr(st,endi-st+1);
    }
};
