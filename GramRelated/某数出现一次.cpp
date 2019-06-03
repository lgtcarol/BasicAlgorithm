class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //各bit求和
        int bitSum[32] = {0};
        for(int i = 0; i < nums.size(); i++)
        {
            //针对num[i]的逐bit读取
            int tmp = nums[i];
            unsigned int bitAss = 1;
            for(int index = 31; index >= 0; index--)
            {
                int bit = tmp&bitAss;
                //Debug:注意上式的结果并不是一个bit对应的值，所以逻辑的严谨性！
                if(bit != 0)
                    bitSum[index] += 1;
              //  bitSum[index] += tmp&bitAss;
                bitAss = bitAss<< 1;
            }
        }
        //各bit是3的倍数,找出fei倍数
        for(int i = 0; i < 32; i++)
        {
            if(bitSum[i]%3)
                bitSum[i] = 1;
            else
                bitSum[i] = 0;
        }
        //拼成仅出现一次的数
        int res = 0;
        for(int i = 0; i < 32; i++)
        {
        //    res = res*2+bitSum[i];
            //Debug:若用上面的乘法会导致整数越界，必须改为下面左移
            res <<= 1;
            res += bitSum[i];
        }
        return res;
    }
};
