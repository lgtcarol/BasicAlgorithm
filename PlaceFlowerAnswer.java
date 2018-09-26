package greedy;

public class PlaceFlowerAnswer {

	public boolean canPlaceFlowers(int[] flowerbed, int n) {
		int cnt = 0;
		/**
		 * ˼ά��㣺���㷨��Ƴ��ھ�Ӧ��ͨ���о�����ʾ��������ʾ����ѡ����ʵ�˼·���籾�����������ʾ�Ӧ�ڳ�����ʶ����1��ǰ��Ӧ�ÿ���
		 * ���𰸵�pre��next���൱��flag�������߶�����ʱ���Ƿ���
		 * ��Ԫ����������������һ�������һ��Ԫ�طֱ�û��ǰ���ͺ�̣��ӳ������뵽��ǰ����������0���ɡ�ʵ�����Ƹ�λ���ܷ���õ���int[1]��int[length-2]
		 * */
		for(int i = 0; i < flowerbed.length; i++) {
			if(flowerbed[i] == 1)
				continue;
			int pre= i == 0?0:flowerbed[i-1];
			int next = i == flowerbed.length-1?0:flowerbed[i+1];
			if(pre == 0 && next == 0) {
				cnt++;
				flowerbed[i] = 1;
			}
		}
		/**
		 * �о�������ת����n--��0��ʵ������������������Ľ⣻�걸������ӦΪ���ɷ��õĻ�>=N���true,�����false
		 * */
		return cnt >=n ;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] test = {1,0,0,0,0,1};
		PlaceFlowerAnswer t = new PlaceFlowerAnswer();
		System.out.println(t.canPlaceFlowers(test, 2));
	}

}
