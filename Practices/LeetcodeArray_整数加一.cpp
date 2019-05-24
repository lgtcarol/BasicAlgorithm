/*
题目：用向量表示的某整数+1的问题
解法：从数组最后一个元素诸位加一，直到数组最高位，若最够位产生进位则nsert一个1.
**/
vector<int> plusone(vector<int> &digits)
{
    vector<int> res(digits.size(), 0);
    int sum = 0;
    int one = 1;
    for(int i = digits.size()-1; i >= 0; i--)
    {
        sum = one+digits[i];
        one = sum/10;
        res[i] = sum%10;
    }
    if(one > 0)//最高位产生进位
        res.insert(res.begin(), one);
    return res;
}
