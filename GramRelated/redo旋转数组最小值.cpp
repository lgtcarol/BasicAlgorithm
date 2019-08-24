    int minNumberInRotateArray(vector<int> rotateArray) {   
        if(rotateArray.empty())
            return 0;
        int lo = 0;
        int hi = rotateArray.size()-1;
        if(rotateArray[lo] < rotateArray[hi])
            return rotateArray[lo];
        while(lo+1 < hi)
        {
            int mid = (lo+hi)/2;
            //low mid high本就将数组分成区间,先以index=high作为target进行二分查找定位
            //且由于hi的游标式移动，不妨就用hi = len-1的情况理顺走势
            if(rotateArray[mid] > rotateArray[hi])//说明mid目前在前半段，目标区间需要右移
                lo = mid;
            else if(rotateArray[mid] < rotateArray[hi])//说明在后半段，目标区间左移(往中间靠)
                hi = mid;
            else       //既选index=hi作为枢纽，则不断调节hi即可
                hi--;
        }
        return rotateArray[hi];
    }
//纯粹自己的理解！（后知后觉：lo++ 或 hi-- 的最终目的和lo=mid hi=mid其实相同，只不过看自己能否理解到位）
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0)
            return 0;
        if(rotateArray.size()== 1)
            return rotateArray[0];
        int len = rotateArray.size();
        int lo = 0;
        int hi = len-1;
        while(lo+1<=hi)
        {
            int mid = (lo+hi)/2;
            if(rotateArray[mid] < rotateArray[hi])
                hi--;
            else if(rotateArray[mid] > rotateArray[hi])
                lo++;
            else
                hi--; //之前总过不了，是因为缺少考虑这种情况

        }
        return rotateArray[lo];
    }
};
