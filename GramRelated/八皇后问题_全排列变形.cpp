#include<iostream>
#include<cstdio>
using namespace std;

int g_number = 0; //所有的放置方法数目
void Permutation(int *, int , int);
void Print(int *, int );
//难点：对原始问题的稍加建模，如对行列冲突的处理
void EightQueen(void)
{
    const int queens = 8;
    int ColumnIndex[queens];//每个位置代表一行(定不同行),只要再约束下取值不同(定不同列)
    //针对此问题只需要对枚举的结果检查：是否有同斜线放置
    //各行皇后初始化
    for(int i = 0; i < queens; i++)
    {
        ColumnIndex[i] = i;
    }
    Permutation(ColumnIndex, queens, 0);//依据全排列思想，dfs逐层深入,参数二则为程序提供出口判断条件
}
//简单的判断而已
bool Check(int ColumnIndex[], int length)
{
    int i, j;
    for(i = 0; i < length; i++)
        for(j = i+1; j<length; j++)
    {
        if(i-j==ColumnIndex[i]-ColumnIndex[j] || j-i==ColumnIndex[i]-ColumnIndex[j])//在正、副对角线上
            return false;
    }
    return true;
}
void Permutation(int ColumnIndex[], int length, int index)
{
    if(index == length)//程序出口依然在遍历到末尾
    {
        if(Check(ColumnIndex, length))//唯一不同的地方则是增加结果的判断
        {
            g_number++;
            Print(ColumnIndex, length);
        }
    }
    else
    {
        for(int i = index; i < length; i++)
        {
            //全排列的从当前index的交换思路，雷同本层的枚举，但对每层枚举一个则dfs
            swap(ColumnIndex[index], ColumnIndex[i]);
            Permutation(ColumnIndex, length, index+1);
            swap(ColumnIndex[index], ColumnIndex[i]);
        }

    }
}

void Print(int ColumnIndex[], int length)
{
    printf("%d\n", g_number);
    for(int i = 0; i < length; i ++)
        printf("%d ", ColumnIndex[i]);
    printf("\n");
}


int main(void)
{
	EightQueen();
	return 0;
}
