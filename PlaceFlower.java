package greedy;

public class PlaceFlower {
	public boolean canPlaceFlowers(int[] flowerbed, int n) {
		boolean flag = false;
		if (n == 0)
			return true;
		if (flowerbed.length == 1) {
			if(n == 1 && flowerbed[0] == 0)
				return true;
			
		}
		if(flowerbed[0] == 0 && flowerbed[1] == 0) {
			flowerbed[0] = 1;
			n--;
		}
			
		for(int i=0;n !=0 && i < flowerbed.length-1; i++) {
			if(flowerbed[i] == 1)
				flag = false;
			else {
				if(flag == true && flowerbed[i+1] != 1)
				{
					n--;
					flag = false;
				}
				else
					flag = true;
			}
		}
        //�����ڶ���0���¸�������õ��±�Ϊflowerbed.length-1��Ԫ��δ��ѭ���в����ж�
        if(flag == true && flowerbed[flowerbed.length-1] == 0){
            n--;
        }
		if(n == 0)
			return true;
		else
			return false;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int test[] = {0,0,0,0,0,1,0,0};
		PlaceFlower t = new PlaceFlower();
		System.out.println(t.canPlaceFlowers(test, 0));
/**
 * δͨ��������{1,0,0,0,0,1} 2
 * ԭ����placeʱֻ����ǰ���Ƿ�Ϊ�㣬�����˺���Ϊ1ͬ��������place
 * δͨ��������[0,0,1,0,1] 1
 * ԭ�� ����flag�ĳ�ʼֵ��Կ�ʼ��Ӱ��
 * δͨ��������{0} 0��{0}��1
 * ԭ��һ��δע�⵽��Ŀ�������nֵ���޶������Ƕ�n==0�Ŀ��Ǻ��ӣ�����flag���ñ�������ͺ��ԣ�������������δ��֪�¸�λ���Ƿ���Է��ã���ô�������ֻ��һ��λ�õ�����أ�
 * δͨ������:{0,0,0,0,0,1,0,0} 3
 * ԭ��ͬ��������flag���ͺ���ʹ�����һ��Ԫ����Ϊû���¸�Ԫ�ض��޷������ж�
 */
	}

}
/**
 * һ�ֱ�׼�ⷨ��
 * public boolean canPlaceFlowers(int[] flower)
 * */
