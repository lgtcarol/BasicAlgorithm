class Solution {
    int *b = new int [2*100000]; //未知data长度情况下的辅助变量
    long long  cnt = 0;
public:
//    Solution():cnt(0)
//    {
//        for(int i = 0; i < 2*100000; i++)
//            b[i] = 0;
//    }
    int InversePairs(vector<int> data) {
        //直接转为归并排序问题
        sort(data, 0, data.size()-1);
        return  cnt%1000000007;
    }
    //copy
    void sort(vector<int> &a, int low ,int high)
    {
        //递归划分&合并过程
        if(low < high)
        {
            int mid = (low+high)/2;
            sort(a, low, mid);
            sort(a, mid+1, high);
            merge(a, low, mid, high);
        }
    }
    void merge(vector<int> &a, int low, int mid, int high)
    {
        int i, j, k;
        //把原数先复制到辅助数组中，注意所有的下标都在[low,high]区间
        for(k = low; k <= high; k++)
            b[k] = a[k];
        //从各段最后一位倒着合并
        for(i=mid, j=high, k=high; i>=low&&j>mid&&k>=low; k--)
        {
            if(b[i] > b[j])
            {
                cnt += j-mid;
                a[k] = b[i--];
            }
            else
            {
                a[k] = b[j--];
            }
        }
        //不论哪端剩余，都不再符合逆序要求，直接复制回原数组
        while(i >= low)
            a[k--] = b[i--];
        while(j > mid)
            a[k--] = b[j--];
    }
};
