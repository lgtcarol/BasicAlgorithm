/**
（1）当dp[i - 1]> 0 时，那么dp[i] = dp[i - 1] + nums[i];
（2）当 dp[i - 1]<= 0 时，那么 dp[i] = nums[i]；
时间复杂度为O(n)，空间复杂度也为O(n)。
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int len = nums.size();
        if(len == 0)
            return 0;
        if(len == 1)
            return nums[0]; //边界值判断返回
        int *dp = new int[len];
        dp[0] = nums[0];
        int maxSum = dp[0]; //记录数组 & max值 初始化正确
        for(int i = 1; i < len; i++) //一位辅助，学习的方向自然向右即可，按相应规则转换
        {
            if(dp[i-1] < 0)
                dp[i] = nums[i];
            else
            {
                dp[i] = dp[i-1] + nums[i];
            }
            //更新最大和
            if(dp[i] > maxSum)
                maxSum = dp[i];
        }
        return maxSum;
    }
};
