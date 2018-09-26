package greedy;
//question:leetcode评判时对于给定的输入其数组下标从0起，那么其题中的定义从1开始怎么？
//我们假定平台通过控制实现从1开始考虑
public class NonDecreaseArray {
	public boolean checkPossibility(int[] nums) {
		boolean flag = false;
		int len = nums.length;
		if(len == 2 || len == 3)//有效元素即1个或者2个
			return true;
		for(int i = 1; i <= nums.length-2; i++)
		{
			if(flag == false && nums[i] > nums[i+1] ) {//有一次修改机会要么改i要么改i+1
				if(i == 1)
				{
					//不存在i-1，故单独处理直接取后者覆盖即可
					nums[i] = nums[i+1];
					flag = true;
					continue;
				}
				if(i == nums.length-2)//就剩两个元素，随意改即可
					return true;
				if(nums[i-1] <= nums[i+1]) {//拉高i
					flag = true;//仅有的一次机会已经使用
					nums[i] = nums[i+1];
				}
				else if(nums[i] <= nums[i+2]) {//拉高i+1
					nums[i+1] = nums[i];
					flag = true;
				}else
					return false;
				continue;
			}
			if(nums[i] > nums[i+1])//再次出现逆序
				return false;
		}
		return true;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int nums[] = {0,2,3,3,2,4};//我的默认处理是在0号位置补上。
		NonDecreaseArray t = new NonDecreaseArray();
		System.out.println(t.checkPossibility(nums));
	}

}
/**
 * 错误案例：{0,2,3,3,2,4}
 * 原因：对发现的逆序对如何修改理解不透彻，以为仅可以修改前者。其实为保持有序，修改前者保持i-1,i,i+1有序；修改后者保持i,i+1,i+2有序都有必要
 * 解决：目前因为举例太少，实则对有序的本质应多加思考。
 * */
//当发现逆反关系肯定修改前者。