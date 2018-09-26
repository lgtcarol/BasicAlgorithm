package greedy;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

public class QueueReconstruction {

    public int[][] reconstructQueue(int[][] people) {
        if (people == null || people.length == 0 || people[0].length == 0)
            return new int[0][0];
            
        Arrays.sort(people, new Comparator<int[]>() {//��ʵ���������Ķ��������Ǹ�һά����
            public int compare(int[] a, int[] b) {
                if (b[0] == a[0]) return a[1] - b[1];//h���ս������У�k�����������С�
                return b[0] - a[0];
            }
        });//ʹ��Comparator�ӿ�,��д�ӿ��е����򷽷�compare�������������߼�ǰ���ǽ�����
       // ���ַ������ô�������ʵ��Comparator�ӿڲ���д�ӿ��е�compareTo��������
        
        int n = people.length;
        ArrayList<int[]> temp = new ArrayList<>();//�����б�����add��������ά����ת��List��
/**
 * ����һ��ֱ��һ����λ
        for (int i = 0; i < n; i++)
            tmp.add(people[i][1], new int[]{people[i][0], people[i][1]});

        int[][] res = new int[people.length][2];
        int i = 0;
        for (int[] k : tmp) {
            res[i][0] = k[0];
            res[i++][1] = k[1];
        }
*/
        
/**
 * ����������ת��������listȡ��ÿ��Ԫ�أ������õڶ�ά��ֵ���бȽ��ƶ���������ø߼����ݽṹʱ����Ӧ����˼����������Ƕ�ά�Ĳ����ӵ�λҪͨ��һά�еĵ���Ԫ�ظı䣬Ȼ����Ƕ��һ�����ʵ�֣�
 *     ��Ȼֻ���ȡ�ڶ�ά��Ϊ��Ϣ����ôList�е�Ԫ�ر�����int[]�ͣ�ֱ���ƶ�����
 */
        for (int[] aPeople:people) {
        	if(people.length == aPeople[1]) {
        		temp.add(aPeople);
        	}else {
        		temp.add(aPeople[1],aPeople);
        	}
        }//����˴����ŵڶ���������������add����������Ӧ����ŵ�ǰԪ�أ�����Ԫ��ֱ�Ӻ���
        //֮������Ϊ��List����ʹ�ã�ʵ����kֵ�͵�һ���������Ԫ��λ�õĶ�Ӧ��ϵ���ԡ�����kֵ���������Ĺ��̼����
        // //���б�ֱ�Ӹ��Ƶ���ά������Ϊ���
        int res[][]  = new int[people.length][2];
        for(int i = 0; i < temp.size(); i++)
        	res[i] = temp.get(i); 
      
        
 /**
  * ��������ͬΪ��ת����������������ת��ĵ�����������list��int[][]���Բ��õĵͼ����ݽṹ��������˼·
  *	   for(int i = 0; i < n; i++)
  *		{
  *			res[i][0] = tmp.get(i)[0];
  *			res[i][1] = tmp.get(i)[1];
  *		}
  */
        
        return res;
    }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int people[][] = {{7,0},{4,4}, {7,1}, {5,0}, {6,1}, {5,2}}; 
		QueueReconstruction q = new QueueReconstruction();
		int output[][] = q.reconstructQueue(people);
		
		for(int i = 0; i < output.length; i++)
		{
			for(int j = 0; j < output[0].length; j++)
				System.out.print(output[i][j]);
			System.out.println();
		}
	}

}
