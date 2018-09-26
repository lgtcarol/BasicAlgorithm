package greedy;

public class PlaceFlowerAnswer {

	public boolean canPlaceFlowers(int[] flowerbed, int n) {
		int cnt = 0;
		/**
		 * 思维起点：在算法设计初期就应该通过列举正常示例，极端示例来选择合适的思路。如本题若举例合适就应在初期意识到置1的前后都应该考虑
		 * 本答案的pre和next都相当于flag，即两者都满足时考虑放置
		 * 三元运算符用来解决：第一个和最后一个元素分别没有前驱和后继，从常理即可想到其前驱或后继视作0即可。实际限制该位置能否放置的是int[1]和int[length-2]
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
		 * 判决条件的转换：n--至0其实并不足以描述该问题的解；完备解描述应为：可放置的花>=N则解true,否则解false
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
