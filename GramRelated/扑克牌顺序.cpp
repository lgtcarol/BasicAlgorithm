/**
锻炼分析能力：
大小王既然可代替任何数字，视作0即可
考虑除0外想要连续的必要条件：
(1)数字不能重复出现
(2)数字差距在5内
*/
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.empty())
            return 0;
        int len = numbers.size();
        int max = -1;
        int min = 14;
        int count[14] = {0}; //不排序，采用哈希方式
        for(int i = 0; i < len; i++)
        {
            count[numbers[i]]++; //哈希桶
            if(numbers[i] == 0) 
                continue;
            if(count[numbers[i]] > 1) //重复出现必不连续
                return false;
            if(numbers[i] > max)  //若想数字连续，哪怕是用0去填充，连续5个数的最大差距都在5内
                max = numbers[i];
            if(numbers[i] < min)
                min = numbers[i];
        }
        if(max - min < 5)
            return true;
        return false;
    }
};
