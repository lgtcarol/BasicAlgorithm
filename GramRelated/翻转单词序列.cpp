class Solution {
public:
    string ReverseSentence(string str) {
        int len = str.size();
        int start = 0;
        for(int i = 0; i < len; i++)
        {
            if(str[i] == ' ')
            {
                reverse(str.begin()+start, str.begin()+i); //旋转单词。正好左闭右开
                start = i+1;//下个单词起始位置
            }
            if(i == len-1)//最后一个单词不再以空格作为翻转的标志
                reverse(str.begin()+start, str.begin()+i+1); //debug:或者写成str.end(),最后这个单词稍有不同
        }
        //整个字符串的翻转
        reverse(str.begin(), str.end());
        return str;
    }
};

