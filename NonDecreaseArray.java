package greedy;
//question:leetcode����ʱ���ڸ����������������±��0����ô�����еĶ����1��ʼ��ô��
//���Ǽٶ�ƽ̨ͨ������ʵ�ִ�1��ʼ����
public class NonDecreaseArray {
	public boolean checkPossibility(int[] nums) {
		boolean flag = false;
		int len = nums.length;
		if(len == 2 || len == 3)//��ЧԪ�ؼ�1������2��
			return true;
		for(int i = 1; i <= nums.length-2; i++)
		{
			if(flag == false && nums[i] > nums[i+1] ) {//��һ���޸Ļ���Ҫô��iҪô��i+1
				if(i == 1)
				{
					//������i-1���ʵ�������ֱ��ȡ���߸��Ǽ���
					nums[i] = nums[i+1];
					flag = true;
					continue;
				}
				if(i == nums.length-2)//��ʣ����Ԫ�أ�����ļ���
					return true;
				if(nums[i-1] <= nums[i+1]) {//����i
					flag = true;//���е�һ�λ����Ѿ�ʹ��
					nums[i] = nums[i+1];
				}
				else if(nums[i] <= nums[i+2]) {//����i+1
					nums[i+1] = nums[i];
					flag = true;
				}else
					return false;
				continue;
			}
			if(nums[i] > nums[i+1])//�ٴγ�������
				return false;
		}
		return true;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int nums[] = {0,2,3,3,2,4};//�ҵ�Ĭ�ϴ�������0��λ�ò��ϡ�
		NonDecreaseArray t = new NonDecreaseArray();
		System.out.println(t.checkPossibility(nums));
	}

}
/**
 * ��������{0,2,3,3,2,4}
 * ԭ�򣺶Է��ֵ����������޸���ⲻ͸������Ϊ�������޸�ǰ�ߡ���ʵΪ���������޸�ǰ�߱���i-1,i,i+1�����޸ĺ��߱���i,i+1,i+2�����б�Ҫ
 * �����Ŀǰ��Ϊ����̫�٣�ʵ�������ı���Ӧ���˼����
 * */
//�������淴��ϵ�϶��޸�ǰ�ߡ�