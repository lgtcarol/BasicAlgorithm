package dynamicplan;

import java.awt.List;
import java.util.ArrayList;
import java.util.Arrays;

public class PerfectSquares {
	/**解法一 ：导出了动态规划的表达式
	public int numSquares(int n) {
		if(n < 0)
			return 0;
		int[] cntPerfectSquares = new int[n+1];
		Arrays.fill(cntPerfectSquares, Integer.MAX_VALUE);
		cntPerfectSquares[0] = 0;
		for(int i = 0; i <= n; i++)
			for( int j = 1; j*j <= i; j++)
				cntPerfectSquares[i] = Math.min(cntPerfectSquares[i], cntPerfectSquares[i-j*j]+1);
		return cntPerfectSquares[n];		
	}
	*/
	/**解法二：容易想到的动态规划思想:i的完全平方数是从和i的两个完全平方数dp[j]和dp[i-j]之和，然后取最小
	 * 用 dp[i] 数组存储第 i 个数的完美平方数。递推式为：dp[i] = Math.max(dp[j] + dp[i-j], dp[i])
	public int numSquares(int n) {
		int[] dp = new int[n+1];
		Arrays.fill(dp, Integer.MAX_VALUE);
		dp[1] = 1;
		for( int i = 1; i <= n; i++) {
			int sqr = (int)Math.sqrt(i);
			if(sqr*sqr == i)
				dp[i] = 1;//若i本身就是平方数则将dp[i]置1
			else//从1开始遍历所有和为i的dp,使得dp[i]取得最小
				for(int j = 1; j <= i/2; j++)
					dp[i] = Math.min(dp[j]+dp[i-j], dp[i]);
		}
		return dp[n];
	}
	*/
	//https://blog.csdn.net/happyaaaaaaaaaaa/article/details/51584790
	//解法三:从解法二中改良得所有完美平方数都可以看作一个普通数加上一个完美平方数
	//递推式就变为了：dp[i + j * j] = Math.min(dp[i] + 1, dp[i + j * j])
	//???对比解法一：针对不同得初始值，两个递归式真不同吗？
	    public int numSquares(int n) {
	        int[] dp = new int[n+1];
	        Arrays.fill(dp, Integer.MAX_VALUE);
	        for(int i = 0; i * i <= n; i++) 
	            dp[i * i] = 1;
	        for(int i = 1; i <= n; i++) {  //选定第一个数为 i
	            for(int j = 1; i + j * j <= n; j++) {  //选定另一个数为 j*j
	                dp[i + j * j] = Math.min(dp[i] + 1, dp[i + j * j]);  //从小到大查找
	            }
	        }
	        return dp[n];
	    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		PerfectSquares t = new PerfectSquares();
		System.out.println(t.numSquares(12));
	}

}
