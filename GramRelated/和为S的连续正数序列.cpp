class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        int phigh = 2,plow=1;
        while(phigh > plow)
        {
            int curSum = ((plow+phigh)*(phigh-plow+1))>>1;
            if(curSum < sum)
                phigh++;
            if(curSum == sum)
            {
                vector<int> temp;
                for(int i = plow; i <= phigh; i++)
                {
                    temp.push_back(i);
                }
                result.push_back(temp);
                plow++; //切记：此处一定要往前看，不然状态不变进入死循环
            }
            if(curSum > sum)
                plow++;
        }
        return result;
    }
};
