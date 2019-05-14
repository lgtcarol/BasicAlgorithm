class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;
      //  int lo = 0;
        int lo = -1;    // 如果初始化为 0 将无法处理 n == 2 的情况，初始化为 -1 就可以了
        int hi = rotateArray.size()-1;
        //没有旋转
        if(rotateArray[lo] < rotateArray[hi])
            return rotateArray[lo];
        //唯一特殊得下标控制
        //此处二分法的思路内化：首先锁定被旋转后当前的位置区间，然后用hi--去逼近，最终返回下标为hi的值
        while(lo+1 < hi)
        {
            int mid = (lo + hi)/2;
            if(rotateArray[mid] > rotateArray[hi])
                lo = mid;
            else if(rotateArray[mid] < rotateArray[hi])
                hi = mid;
            else 
                hi--;
        }
        return rotateArray[hi];
    }
};
