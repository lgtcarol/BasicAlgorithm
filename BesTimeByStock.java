package greedy;

public class BesTimeByStock {
/**
 * 第一：也应会发现总结规律（实际还有数学数列的思想在，不完全是发现就行）。不论是贪心还是动态规划总是需要客观的思路的，此题有些不知所措
 * 第二：数学规律下的分解可看到 实为在局部最优的情况下保证 全局最优
 */
	public int maxProfit(int[] prices) {
		int max = 0;
		int size = prices.length;
		for(int i = 0; i < size-1; ++i) {
			if(prices[i] < prices[i+1]) 
				max += prices[i+1]-prices[i];	
		}
		return max;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] a = {7,1,5,3,6,4};
		int [] b = {1,2,3,4,5};
		int [] c = {7,6,4,3,1};
		BesTimeByStock test = new BesTimeByStock();
		System.out.println(test.maxProfit(a));
		System.out.println(test.maxProfit(b));
		System.out.println(test.maxProfit(c));
	}
}
