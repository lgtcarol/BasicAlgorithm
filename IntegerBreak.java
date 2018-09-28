package dynamicplan;

public class IntegerBreak {
	/**解法一：导出动态规划表达式，用数组形式进行动态规划
	public int integerBreak(int n) {
		int[] dp = new int[n+1];
		dp[1] = 1;
		for(int i = 2; i <= n; i++) {
			for(int j = 1; j <= i-1; j++) {
				dp[i] = Math.max(dp[i], Math.max(j*dp[i-j], j*(i-j)));
			}
		}
		return dp[n];
	}
	*/
	//通过枚举分析得到：从n=5开始呈现规律https://blog.csdn.net/seagal890/article/details/79474473
	public int integerBreak(int n) {
		int result = 1;
		if (n == 2 || n == 3)
			return n-1;
		if(n == 4)
			return n;
		while(n > 4) {
			result *= 3;
			n-=3;
		}
		return result*n;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		IntegerBreak t = new IntegerBreak();
		System.out.println(t.integerBreak(10));
	}

}
