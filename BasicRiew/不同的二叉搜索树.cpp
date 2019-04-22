/**
  假设DP(n)表示n个节点组成不同二叉搜索树的种类数，分别考虑1到n作为根结点的情况。
(1) 根节点为1，则左子树必定为空，右子树为2...n个节点，那么种类数为1*DP[n-1]，也可以表示为DP[0]*DP[n-1]。
(2) 根节点为2，则左子节点为1，右子树为3...n个节点，即DP[1]*DP[n-2]
(3) 根节点为3，则左子节点为1,2，右子树为4...n个节点，即DP[2]*DP[n-3]
*/
class Solution {
public:
    int numTrees(int n) {
        long *dp = new long[n+1];
        for(int i = 0; i <= n; i++)
            dp[i] = 0;
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
                dp[i] += dp[j-1]*dp[i-j];
        }
        return dp[n];
    }
};
