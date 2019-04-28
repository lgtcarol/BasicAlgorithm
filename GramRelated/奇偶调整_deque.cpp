class Solution {
public:
//使奇数在前半部分，偶数在后半部分，且相对位置不变
//使用双端队列，奇数从后往前顺序扫描并push_front进队列，偶数从前往后扫并push_back进
void reOrderArray(vector<int> &array)
{
    deque<int> res;
    int len = array.size();
    for(int i = 0; i < len; i++)
    {
        if(array[len-i-1]%2 == 1)
            res.push_front(array[len-i-1]);
        if(array[i]%2 == 0)
            res.push_back(array[i]);
    }
    //复制法一：vector中类似copy的函数，参数为复制开始和结束的地方。
    //array.assign(res.begin(), res.end());
    //复制法二：可实现list,vector,queue间互拷贝，参数前两个为【s,e），第三个为拷贝到的地址
    array.resize(0);
    copy(res.begin(), res.end(), back_inserter(array));
}
};
//思路二：采用双指针，类似快排中的partition.
