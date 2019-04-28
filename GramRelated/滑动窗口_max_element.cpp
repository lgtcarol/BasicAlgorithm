class Solution {
    //C++ STL中的max_element(first, end, cmp)返回容器中的最大值
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        int count = num.size()-size+1;//窗口总数
        vector<int> result;
        if(size==0 || num.size()==0){
            return result;
        }
        for(int i =0;i<count;i++){//遍历每个窗口，借助STL函数的得到窗口最大值
            int max_number = *max_element(num.begin()+i, num.begin()+i+size); //依旧左闭右开 
            result.push_back(max_number);
        }
        return result;
    }
};
