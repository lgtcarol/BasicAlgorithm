/**从排好序的数组中删除指定元素且不可申请新空间*/
int removeDuplicates(int A[], int n)
{
    if(n == 0)
        return 0;
    int j =0 ;
    for(int i = 1; i < n; i++)//默认第一个元素不必删除，从1开始.有效从j=1开始修改
    {
        //当和前一个元素不等，当前元素才有资格被保存，且放到当前的下个位置.
        if(A[j] != A[i])
            A[++j] = A[i];
    }
    //由于j指向的当前存好的有效元素，故总长度需要加一（数组下标和长度的关系）
    return j+1；
}

//变体:若允许出现两次（仍旧有序数组）
int removeDuplicates(int A[], int n)
{
    if(n == 0)
        return 0;
    int j = 0;
    int num = 0;
    for(i = 1; i < n; i++)
    {
        //相比于只允许出现一次，增加一个计数当相等时若次数允许，按照不重复的hli
        if(A[j] == A[i])
        {
            num++;
            if(num < 2)
                A[++j] = A[i];
        }
        else
        {
            //注意此处对新元素计数器的重置
            A[++j] = A[i];
            num = 0;
        }
    }
    return j+1;
}
