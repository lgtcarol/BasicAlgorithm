// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
#include<cstdio>
int MinInOrder(int *nums, int index1, int index2);
int Min(int* nums, int len)
{
	if(nums == NULL || len <= 0)
		return 0;
	int index1 = 0;
	int index2 = len-1;
	//int mid = (index1 + index2)/2;
    int mid = index1;//必须做此初始化，因为旋转数组并不保证头一定尾 
	while(nums[index1] >= nums[index2])//这个属于大多数情况，但有个特例：若旋转长度为0则数组升序即nums[index1]为最小 
	{
		if(index2 - index1 == 1)
			return nums[index2];
		mid = (index1 + index2)/2;

		if(nums[index1] == nums[mid]&& nums[mid] == nums[index2])//此情况你不知道该往哪边缩小范围，所以直接线性遍历 
		{
 		//notes:犯了低级语法错误：nums[index1] == nums[mid] == == nums[index2]显然不存在啊 
			return MinInOrder(nums, index1, index2);
		} 
		if(nums[index1] >= nums[mid])//最小值在index1~mid间 
			index2 = mid;
		if(nums[index1] <= nums[mid])//最小值在mid~index2间 
			index1 = mid;	
	}
	//Notes:while循环虽然有函数出口，但暗含的逻辑是所有的情况应该要进while
	//而实际分析出来当旋转长度为0时并不进while，那函数返回值多少呢？故逻辑完整性！！ 
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
// ====================测试代码====================
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
    // 典型输入，单调升序的数组的一个旋转
    int array1[] = { 3, 4, 5, 1, 2 };
    Test(array1, sizeof(array1) / sizeof(int), 1);

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    Test(array2, sizeof(array2) / sizeof(int), 1);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    Test(array3, sizeof(array3) / sizeof(int), 1);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = { 1, 0, 1, 1, 1 };
    Test(array4, sizeof(array4) / sizeof(int), 0);

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = { 1, 2, 3, 4, 5 };
    Test(array5, sizeof(array5) / sizeof(int), 1);

    // 数组中只有一个数字
    int array6[] = { 2 };
    Test(array6, sizeof(array6) / sizeof(int), 2);

    // 输入nullptr
    Test(NULL, 0, 0);

    return 0;
}
