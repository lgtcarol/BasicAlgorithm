package greedy;

import java.util.Arrays;
import java.util.Comparator;;

public class MinArrowBurstBalloons {
	public int findMinArrowShots(int[][] points) {
		int ret = 1;
		if(points.length == 0)
			return 0;
/**
 * 排序法一：使用实现Comparator接口的类对象属于集合外部实现；
 *        另种对等操作是在集合内部实现，即implements Comparable后重写compareTo
		Arrays.sort(points, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0]-b[0];
			}
		});
*/
// 排序法二： 借鉴尝试java8提供的新特性：匿名函数
		Arrays.sort(points,(a,b)->(a[1]-b[1]));
//*条件判别法一：判断此end和彼start是否相交
		int curPos = points[0][1];
		for(int i = 1; i < points.length; i++) {
			if(points[i][0] <= curPos)
				continue;
			curPos = points[i][1];
			ret++;
		}

//条件判别二：估计按照我的思路，即限定此end满足 x.start<= end <=x.end会出现情况的遗漏。
//        这种思路的直接后果：题目给定的限定情况不够分析，若扩展情况变得毫无边际。
//		for(int i = 0; i < points.length-1; i++) {
//			if(points[i][1] >= points[i+1][0] && points[i][1] <= points[i+1][1])
//				continue;
//			ret++;
//		}
//实验结果：不是判定条件的问题，自己没将问题抽象出合适的理解形式。正确解法 两点启示：一是顺着数组下标移动的是后者而不是我用的i和i+1
//		比较，逻辑不严谨同时还容易越界；而是curPos的使用和妙同时也是必须的。
		
		return ret;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MinArrowBurstBalloons test = new MinArrowBurstBalloons();
		int points[][] = new int[][]{{10,16},{2,8},{1,6},{7,12}};
		int result = test.findMinArrowShots(points);
		System.out.println(result);
	}

}
