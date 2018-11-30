#include <cstdio>
#include "Utilities\Array.cpp"


bool CheckInvalidArray(int* numbers, int length)
{
    g_bInputInvalid = false;
    if(numbers == NULL && length <= 0)
        g_bInputInvalid = true;

    return g_bInputInvalid;
}

bool CheckMoreThanHalf(int* numbers, int length, int number)
{
    int times = 0;
    for(int i = 0; i < length; ++i)
    {
        if(numbers[i] == number)
            times++;
    }
 
    bool isMoreThanHalf = true;
    if(times * 2 <= length)
    {
        g_bInputInvalid = true;
        isMoreThanHalf = false;
    }

    return isMoreThanHalf;
}

// ====================方法1====================
/**
1. 若排好序则自然好数，而且排序是必要的至少要归类
2. 从排序的思路降低开销，二分思路是好的，快排在此思路上每轮固定一个数字且知道相对大小（尤其这种第几大的问题含有相对关系） 
3. 排好序观察目标在哪儿？发现n/2处必然是
4. 综合上述思路，快排直到定位到n/2，然后检查其出现具有至少一般数组长度 
*/
int MoreThanHalfNum_Solution1(int* numbers, int length)
{
    if(CheckInvalidArray(numbers, length))
        return 0;
 
    int middle = length >> 1;
    int start = 0;
    int end = length - 1;
    int index = Partition(numbers, length, start, end);
    while(index != middle)
    {
        if(index > middle)
        {
            end = index - 1;
            index = Partition(numbers, length, start, end);
        }
        else
        {
            start = index + 1;
            index = Partition(numbers, length, start, end);
        }
    }
 
    int result = numbers[middle];
    if(!CheckMoreThanHalf(numbers, length, result))
        result = 0;

    return result;
}




/**
??拿实例确实毫无压力发现正确，实际有点不同元素碰撞消掉的感觉
每次times减为0就记录一个新的元素到result，然后又用result开始进行消，最后一个标为result的元素说明数量优势？！ 
*/ 
// ====================方法2====================
int MoreThanHalfNum_Solution2(int* numbers, int length)
{
    if(CheckInvalidArray(numbers, length))
        return 0;
 
    int result = numbers[0];
    int times = 1;
    for(int i = 1; i < length; ++i)
    {
        if(times == 0)
        {
            result = numbers[i];
            times = 1;
        }
        else if(numbers[i] == result)
            times++;
        else
            times--;
    }
 
    if(!CheckMoreThanHalf(numbers, length, result))
        result = 0;
 
    return result;
}

