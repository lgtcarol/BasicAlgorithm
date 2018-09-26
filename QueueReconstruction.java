package greedy;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

public class QueueReconstruction {

    public int[][] reconstructQueue(int[][] people) {
        if (people == null || people.length == 0 || people[0].length == 0)
            return new int[0][0];
            
        Arrays.sort(people, new Comparator<int[]>() {//其实本题待排序的对象类型是个一维数组
            public int compare(int[] a, int[] b) {
                if (b[0] == a[0]) return a[1] - b[1];//h按照降序排列，k按照升序排列。
                return b[0] - a[0];
            }
        });//使用Comparator接口,重写接口中的排序方法compare（）方法，后者减前者是降序排
       // 另种方法是让待排序类实现Comparator接口并重写接口中的compareTo（）方法
        
        int n = people.length;
        ArrayList<int[]> temp = new ArrayList<>();//声明列表，利用add函数将二维数组转至List中
/**
 * 方法一：直接一步到位
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
 * 方法二：中转处理。利用list取出每个元素，并利用第二维的值进行比较移动（当你采用高级数据结构时，便应灵活的思考问题而不是二维的操作子单位要通过一维中的单个元素改变，然后再嵌套一层才能实现）
 *     显然只需读取第二维作为信息，那么List中的元素本就是int[]型，直接移动即可
 */
        for (int[] aPeople:people) {
        	if(people.length == aPeople[1]) {
        		temp.add(aPeople);
        	}else {
        		temp.add(aPeople[1],aPeople);
        	}
        }//假设此处按着第二个坐标重新排序，add函数会在相应坐标放当前元素，其余元素直接后移
        //之所以以为是List不会使用，实际是k值和第一次排序后与元素位置的对应关系忽略。依照k值进行索引的过程即完成
        // //从列表直接复制到二维数组作为输出
        int res[][]  = new int[people.length][2];
        for(int i = 0; i < temp.size(); i++)
        	res[i] = temp.get(i); 
      
        
 /**
  * 方法三：同为中转处理。区别体现在中转后的第三步，复制list到int[][]明显采用的低级数据结构逐个处理的思路
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
