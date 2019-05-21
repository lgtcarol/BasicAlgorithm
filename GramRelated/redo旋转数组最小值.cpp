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
