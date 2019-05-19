
int GetMissingNumber(const int* numbers, int length)
{
    if(numbers == NULL || length <= 0)
        return -1;
    int left = 0;
    int right = length-1;
    while(left <= right)
    {
        int mid = (left+right)>>1;
        //缺失数字会导致：元素值!=下标
        //缺失值之前的会满足“等”,之后的会导致"不等"
        //为了定位缺失值，故前种情况右走，后种情况左走
        if(numbers[mid] != mid)
        {
            if(mid == 0 || numbers[mid-1] == mid-1)
                return mid;
            right = mid-1;
        }
        //一般前面没有缺失的数字轻松满足:元素值=下标，故往后寻找
        else
            left = mid+1;
    }
    if(left == length)
        return length;
 
    // 无效的输入，比如数组不是按要求排序的，
    // 或者有数字不在0到n-1范围之内
    return -1;
}
