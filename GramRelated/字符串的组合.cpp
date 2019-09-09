#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
#include<assert.h>

void Combination(char *string ,int number,vector<char> &result);
/**
剑指上思路:在求n个字符的长度为m的组合时，我们把n个字符分成两部分：第一个字符和其余所有的字符。
          将该问题分为了两个子问题，分别求n-1个字符中长度为m-1的组合，以及求n-1个字符中长度为m的组合。
*/
void Combination(char *str)
{
    if(str == NULL)
        return;
    //不像全排列那样返回的是str,因每个元素都会用到
    //而组合是在str参考下，新生成vec并往里面放元素，根据限定的子集长度按要求返回.
    vector<char> res;
    int i, len=strlen(str);
    for(i = 1; i <= len; i++)
    {
        //参数2则为当前组合中元素个数1-n
        Combination(str, i, res);
    }
}
//核心思路：当前元素放入res或不放入,进入str+1层
void Combination(char *str, int number, vector<char> &res)
{
    if(str == NULL)//已经遍历到字符串尾部了
        return;
    if(number == 0)//达到当前组合数长度的要求，程序出口
    {
        static int num = 1;
        printf("第%d个组合\t", num++);
        vector<char>::iterator iter = res.begin();
        for(; iter!=res.end(); ++iter)
            printf("%c", *iter);
        printf("\n");
        return ;
    }
    if(*str == '\0')
        return;
    res.push_back(*str);//当前元素加入子集合
    Combination(str+1, number-1, res);
    res.pop_back();
    Combination(str+1, number, res);
}

int main(void)
{
	char str[] = "abc";
	Combination(str);
	return 0;
}
