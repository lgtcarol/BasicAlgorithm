package greedy;

public class NonDecreaseAnswer {
	public boolean checkPossibility(int[] nums) {
		int cnt = 0;
		for(int i = 1; i < nums.length; i++) {
			if(nums[i] < nums[i-1]) {
				cnt++;
				if(i-2 >= 0 && nums[i-2]>nums[i])
					nums[i] = nums[i-1];//i-2位置处值更大，故修改i值
				else
					nums[i-1] = nums[i];//i处值更大则修改i-1值
			}//综上两种情况，修改的趋势是使数据呈增大
		}
		return cnt <= 1;//只进入不符合模块一次
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int nums[] = {0,2,3,3,2,4};
		NonDecreaseAnswer t = new NonDecreaseAnswer();
		System.out.println(t.checkPossibility(nums));
	}

}
