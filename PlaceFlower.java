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
        //倒数第二是0，下个允许放置但下标为flowerbed.length-1的元素未在循环中参与判断
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
 * 未通过用例：{1,0,0,0,0,1} 2
 * 原因：在place时只考虑前面是否为零，忽略了后面为1同样不可以place
 * 未通过用例：[0,0,1,0,1] 1
 * 原因： 果真flag的初始值会对开始有影响
 * 未通过用例：{0} 0，{0}，1
 * 原因：一是未注意到题目对数组和n值得限定；二是对n==0的考虑忽视；三是flag作用本身存在滞后性，设置它本就是未告知下个位置是否可以放置，那么问题就是只有一个位置的情况呢？
 * 未通过用例:{0,0,0,0,0,1,0,0} 3
 * 原因：同上述三，flag的滞后性使得最后一个元素因为没有下个元素而无法正常判断
 */
	}

}
/**
 * 一种标准解法：
 * public boolean canPlaceFlowers(int[] flower)
 * */
