package greedy;

import java.util.Arrays;
import java.util.Comparator;;

public class MinArrowBurstBalloons {
	public int findMinArrowShots(int[][] points) {
		int ret = 1;
		if(points.length == 0)
			return 0;
/**
 * ����һ��ʹ��ʵ��Comparator�ӿڵ���������ڼ����ⲿʵ�֣�
 *        ���ֶԵȲ������ڼ����ڲ�ʵ�֣���implements Comparable����дcompareTo
		Arrays.sort(points, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0]-b[0];
			}
		});
*/
// ���򷨶��� �������java8�ṩ�������ԣ���������
		Arrays.sort(points,(a,b)->(a[1]-b[1]));
//*�����б�һ���жϴ�end�ͱ�start�Ƿ��ཻ
		int curPos = points[0][1];
		for(int i = 1; i < points.length; i++) {
			if(points[i][0] <= curPos)
				continue;
			curPos = points[i][1];
			ret++;
		}

//�����б�������ư����ҵ�˼·�����޶���end���� x.start<= end <=x.end������������©��
//        ����˼·��ֱ�Ӻ������Ŀ�������޶������������������չ�����ú��ޱ߼ʡ�
//		for(int i = 0; i < points.length-1; i++) {
//			if(points[i][1] >= points[i+1][0] && points[i][1] <= points[i+1][1])
//				continue;
//			ret++;
//		}
//ʵ�����������ж����������⣬�Լ�û�������������ʵ������ʽ����ȷ�ⷨ ������ʾ��һ��˳�������±��ƶ����Ǻ��߶��������õ�i��i+1
//		�Ƚϣ��߼����Ͻ�ͬʱ������Խ�磻����curPos��ʹ�ú���ͬʱҲ�Ǳ���ġ�
		
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
