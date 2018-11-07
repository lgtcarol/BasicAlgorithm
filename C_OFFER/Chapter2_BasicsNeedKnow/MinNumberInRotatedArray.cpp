// ������11����ת�������С����
// ��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
// ����һ����������������һ����ת�������ת�������СԪ�ء���������
#include<cstdio>
int MinInOrder(int *nums, int index1, int index2);
int Min(int* nums, int len)
{
	if(nums == NULL || len <= 0)
		return 0;
	int index1 = 0;
	int index2 = len-1;
	//int mid = (index1 + index2)/2;
    int mid = index1;//�������˳�ʼ������Ϊ��ת���鲢����֤ͷһ��β 
	while(nums[index1] >= nums[index2])//������ڴ������������и�����������ת����Ϊ0����������nums[index1]Ϊ��С 
	{
		if(index2 - index1 == 1)
			return nums[index2];
		mid = (index1 + index2)/2;

		if(nums[index1] == nums[mid]&& nums[mid] == nums[index2])//������㲻֪�������ı���С��Χ������ֱ�����Ա��� 
		{
 		//notes:���˵ͼ��﷨����nums[index1] == nums[mid] == == nums[index2]��Ȼ�����ڰ� 
			return MinInOrder(nums, index1, index2);
		} 
		if(nums[index1] >= nums[mid])//��Сֵ��index1~mid�� 
			index2 = mid;
		if(nums[index1] <= nums[mid])//��Сֵ��mid~index2�� 
			index1 = mid;	
	}
	//Notes:whileѭ����Ȼ�к������ڣ����������߼������е����Ӧ��Ҫ��while
	//��ʵ�ʷ�����������ת����Ϊ0ʱ������while���Ǻ�������ֵ�����أ����߼������ԣ��� 
	return nums[mid];
}
int MinInOrder(int *nums, int index1, int index2)
{
	int min = nums[index1];
	for(int i = index1; i <= index2; i++)
	{
		if(nums[i] < min)
			min = nums[i];	
	}	
	return min;
}
// ====================���Դ���====================
void Test(int* numbers, int length, int expected)
{
    int result = 0;
    try
    {
        result = Min(numbers, length);

        for(int i = 0; i < length; ++i)
            printf("%d ", numbers[i]);

        if(result == expected)
            printf("\tpassed\n");
        else
            printf("\tfailed\n");
    }
    catch (...)
    {
        if(numbers == NULL)
            printf("Test passed.\n");
        else
            printf("Test failed.\n");
    }
}

int main(int argc, char* argv[])
{
    // �������룬��������������һ����ת
    int array1[] = { 3, 4, 5, 1, 2 };
    Test(array1, sizeof(array1) / sizeof(int), 1);

    // ���ظ����֣������ظ������ָպõ���С������
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    Test(array2, sizeof(array2) / sizeof(int), 1);

    // ���ظ����֣����ظ������ֲ��ǵ�һ�����ֺ����һ������
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    Test(array3, sizeof(array3) / sizeof(int), 1);

    // ���ظ������֣������ظ������ָպ��ǵ�һ�����ֺ����һ������
    int array4[] = { 1, 0, 1, 1, 1 };
    Test(array4, sizeof(array4) / sizeof(int), 0);

    // �����������飬��ת0��Ԫ�أ�Ҳ���ǵ����������鱾��
    int array5[] = { 1, 2, 3, 4, 5 };
    Test(array5, sizeof(array5) / sizeof(int), 1);

    // ������ֻ��һ������
    int array6[] = { 2 };
    Test(array6, sizeof(array6) / sizeof(int), 2);

    // ����nullptr
    Test(NULL, 0, 0);

    return 0;
}
