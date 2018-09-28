package dynamicplan;

import java.awt.List;
import java.util.ArrayList;
import java.util.Arrays;

public class PerfectSquares {
	/**�ⷨһ �������˶�̬�滮�ı��ʽ
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
	/**�ⷨ���������뵽�Ķ�̬�滮˼��:i����ȫƽ�����ǴӺ�i��������ȫƽ����dp[j]��dp[i-j]֮�ͣ�Ȼ��ȡ��С
	 * �� dp[i] ����洢�� i ����������ƽ����������ʽΪ��dp[i] = Math.max(dp[j] + dp[i-j], dp[i])
	public int numSquares(int n) {
		int[] dp = new int[n+1];
		Arrays.fill(dp, Integer.MAX_VALUE);
		dp[1] = 1;
		for( int i = 1; i <= n; i++) {
			int sqr = (int)Math.sqrt(i);
			if(sqr*sqr == i)
				dp[i] = 1;//��i�������ƽ������dp[i]��1
			else//��1��ʼ�������к�Ϊi��dp,ʹ��dp[i]ȡ����С
				for(int j = 1; j <= i/2; j++)
					dp[i] = Math.min(dp[j]+dp[i-j], dp[i]);
		}
		return dp[n];
	}
	*/
	//https://blog.csdn.net/happyaaaaaaaaaaa/article/details/51584790
	//�ⷨ��:�ӽⷨ���и�������������ƽ���������Կ���һ����ͨ������һ������ƽ����
	//����ʽ�ͱ�Ϊ�ˣ�dp[i + j * j] = Math.min(dp[i] + 1, dp[i + j * j])
	//???�ԱȽⷨһ����Բ�ͬ�ó�ʼֵ�������ݹ�ʽ�治ͬ��
	    public int numSquares(int n) {
	        int[] dp = new int[n+1];
	        Arrays.fill(dp, Integer.MAX_VALUE);
	        for(int i = 0; i * i <= n; i++) 
	            dp[i * i] = 1;
	        for(int i = 1; i <= n; i++) {  //ѡ����һ����Ϊ i
	            for(int j = 1; i + j * j <= n; j++) {  //ѡ����һ����Ϊ j*j
	                dp[i + j * j] = Math.min(dp[i] + 1, dp[i + j * j]);  //��С�������
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
