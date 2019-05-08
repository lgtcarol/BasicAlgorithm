//思路一：先排序，再分组统计
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int length = numbers.size();
        if (length==0)
            return 0;
        //先排序
        sort(numbers.begin(),numbers.end());
        int num = numbers[0];
        int max_count = 1;
        int count = 0;
        for(int i = 1;i<length;i++)
        {
            //比较得相邻元素等否，一旦不等立马清零
            //核心思想：有点类似分组统计最大值了，因为先进行排序
            if(numbers[i] != numbers[i-1]){
                if(count > max_count)
                {
                    max_count = count;
                    num = numbers[i-1];
                }
                count = 1;
            }
            else
                count++;
        }
        if(max_count > length/2) //采用整个过程中出现得最大值来区分满足条件
            return num;
        else
            return 0;
    }
};
//思路二:莫尔投票法
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int length = numbers.size();
        if (length==0)
            return 0;
        //利用Boyer-Moore Majority Vote 算法
        int curNum = numbers[0];
        int cnt = 1;
        for(int i = 1;i<length;i++)
        {
            if(numbers[i] != curNum)
                cnt--;
            else
                cnt++;
            if(cnt == 0)
            {
                curNum = numbers[i];//换值
                cnt = 1;
            }
        }
        if(cnt > 0)
        {
            int accur = 0；
            for(int i = 1;i<length;i++)
            {
                if(numbers[i] == curNum)
                    accur++;
            }
            if(accur >= length/2)
                return curNum;
            else
                return 0;
        }
        else
            return 0;
    }
};
