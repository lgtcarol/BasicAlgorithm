package greedy;

public class NonDecreaseAnswer {
	public boolean checkPossibility(int[] nums) {
		int cnt = 0;
		for(int i = 1; i < nums.length; i++) {
			if(nums[i] < nums[i-1]) {
				cnt++;
				if(i-2 >= 0 && nums[i-2]>nums[i])
					nums[i] = nums[i-1];//i-2λ�ô�ֵ���󣬹��޸�iֵ
				else
					nums[i-1] = nums[i];//i��ֵ�������޸�i-1ֵ
			}//��������������޸ĵ�������ʹ���ݳ�����
		}
		return cnt <= 1;//ֻ���벻����ģ��һ��
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int nums[] = {0,2,3,3,2,4};
		NonDecreaseAnswer t = new NonDecreaseAnswer();
		System.out.println(t.checkPossibility(nums));
	}

}
