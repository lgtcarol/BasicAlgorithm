package greedy;

public class BesTimeByStock {
/**
 * ��һ��ҲӦ�ᷢ���ܽ���ɣ�ʵ�ʻ�����ѧ���е�˼���ڣ�����ȫ�Ƿ��־��У���������̰�Ļ��Ƕ�̬�滮������Ҫ�͹۵�˼·�ģ�������Щ��֪����
 * �ڶ�����ѧ�����µķֽ�ɿ��� ʵΪ�ھֲ����ŵ�����±�֤ ȫ������
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
