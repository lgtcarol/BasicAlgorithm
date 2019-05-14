
/**
动态规划的递推公式：
f(n) = 0                     n = 1
f(n) = 1                     n = 2
f(n) = 2                     n = 3    
f(n) = max{dp(i) * dp(n-i)}  n > 3, 1<=i<=n-1
时间复杂度：O(N^2)，空间复杂度：O(N)
*/
    int integerBreak(int n)
    {
        if(n < 2)
            return 0;
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        int dp[n+1] = {0};//每个下标对应该长度下的最大乘积
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4; i <= n; i++)
        {
            //由于至少切一刀，要使得乘积大时的最好选择为从中间，故切时的最大选择为半值
            for(int j = 1; j <= i/2; j++)
            {
                int p = dp[j]*dp[i-j];//记录所有子结构的解，从中选择最优结果
                if(dp[i] < p)
                    dp[i] = p;//直接逐步记录max即可
            }
        }
        return dp[n];
    }
 /**
 贪心解法:
 当 n>=5 时，尽可能多剪长度为 3 的绳子；当 n=4 时，剪成两段长度为 2 的绳子
 时间复杂度：O(1)，空间复杂度：O(1)
 */  
    int integerBreak(int n)
    {
        if(n < 2) return 0;
        if(n == 2) return 1;
        if(n == 3) return 2;
        int n3 = n/3; // 切成 3 的数量
        //Debug:要识别出是否有4，这个判断与目标不等价，反例如n=5
//        if(n - (n3-1)*3 > 3)
//            n3 -= 1;
        if(n%3 == 1)
            n3--;
        int n2 = (n-n3*3)/2; // 切成 2 的数量
        return (int)pow(3,n3)*(int)pow(2,n2);
    }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
