class Solution {
public:
    bool IsOfBST(vector<int> &arr, int s, int e)
    {
        //Debug_1:递归程序出口之下标检查
        if(s > e)
            return false;
        int root = arr[e]; //找到根
        int i, j;
        bool left = true;
        bool right = true;

        for(i = s; i < e; i++)
            if(arr[i] > root)
                break;
        //找到左子树的(s,i-1)
        for(j = i; j < e; j++)
            if(arr[j] < root)
                return false; //无法正确划分为右子树
                
        //Debug_2:递归程序之基于有限元素的划分位置合理性
        if(s<=i-1)
            left = IsOfBST(arr, s, i-1);
        if(i<=e-1)
            right = IsOfBST(arr, i, e-1);
        return left&&right;
    }
    
    bool VerifySquenceOfBST(vector<int> sequence) {
        int len = sequence.size();
        if(len < 1)
            return false;
        return IsOfBST(sequence, 0, len-1);
    }
};
