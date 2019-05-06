/**
思路一：采用双层循环，累积时空过A[i]很简单，但很多重复的相乘
思路二：参考书中的矩阵，每个元素按index=i分成两部分，则累积关系可建立在相邻元素间。
*/
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int length = A.size();
        vector<int> B(length);
        if(length < 0)
            return B;
        B[0] = 1;
        //既然ndex=i将数组分为两部分，那就先计算B中每个元素的部分值（由矩阵看比较明了）
         for(int i = 1; i < length; i++) //计算下三角
         {
             B[i] = B[i-1]*A[i-1];
         }
         int temp = 1;//矩阵右下角是1
         for(int i = length-2; i >= 0; i--) //计算上三角
         {
             temp *= A[i+1];
             B[i] *= temp; //拼接两部分得到最终结果.
         }
        return B;
    }
};


