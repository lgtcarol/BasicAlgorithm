#include <cstdio>
#include <math.h>
/**
Note: 在动态规划思路和其数组记录上绕不过！
思路一： 整体框架(第二步)+核心递归过程（第一步）
思路二： 待续。。。 
*/

int g_maxValue = 6;
// ====================方法二====================
void Probability(int number, int* pProbabilities);
void Probability(int original, int current, int sum, int* pProbabilities);
void PrintProbability_Solution1(int number)
{
	if(number < 1)
        return;
    int maxSum = number * g_maxValue;
    int* pProbabilities = new int[maxSum - number + 1];//没必要申请maxSum，和至少是number 
    for(int i = number; i <= maxSum; ++i)
        pProbabilities[i - number] = 0;
    int curSum = 0; 
    Probability(number,number,curSum,pProbabilities);//第一步也是核心步骤: 统计各sum出现次数

 
    int total = pow((double)g_maxValue, number); //第二步 : 计算概率 
    for(int i = number; i <= maxSum; ++i)
    {
        double ratio = (double)pProbabilities[i - number] / total;
        printf("%d: %e\n", i, ratio);
    }
 
    delete[] pProbabilities;
} 
/**
同名函数的重载，其实合并一起更好理解见https://www.cnblogs.com/AndyJee/p/4686208.html
此处比模板算法 稍有区别 
*/
//lgt总结：共number个骰子，每个骰子共6种取值。参数current控制骰子个数，第47行完成每个骰子的状态遍历 
void Probability(int original, int current, int sum,  int* pProbabilities)
{
    if(current == 0)//形参current取遍0-(current-1)共number次  
    {
        pProbabilities[sum - original]++;
    }
    else
    {
        for(int i = 1; i <= g_maxValue; ++i)//本骰子遍历6种取值，以后original-1个一样的操作
        {
            Probability(original, current - 1, i + sum, pProbabilities);
        }
    }
} 

// ====================方法二====================
void PrintProbability_Solution2(int number)
{
    if(number < 1)
        return;

    int* pProbabilities[2];
    pProbabilities[0] = new int[g_maxValue * number + 1];
    pProbabilities[1] = new int[g_maxValue * number + 1];
    for(int i = 0; i < g_maxValue * number + 1; ++i)
    {
        pProbabilities[0][i] = 0;
        pProbabilities[1][i] = 0;
    }
 
    int flag = 0;
    for (int i = 1; i <= g_maxValue; ++i) 
        pProbabilities[flag][i] = 1; 
    
    for (int k = 2; k <= number; ++k) 
    {
        for(int i = 0; i < k; ++i)
            pProbabilities[1 - flag][i] = 0;

        for (int i = k; i <= g_maxValue * k; ++i) 
        {
            pProbabilities[1 - flag][i] = 0;
            for(int j = 1; j <= i && j <= g_maxValue; ++j) 
                pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
        }
 
        flag = 1 - flag;
    }
 
    double total = pow((double)g_maxValue, number);
    for(int i = number; i <= g_maxValue * number; ++i)
    {
        double ratio = (double)pProbabilities[flag][i] / total;
        printf("%d: %e\n", i, ratio);
    }
 
    delete[] pProbabilities[0];
    delete[] pProbabilities[1];
}

// ====================测试代码====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);
    
    printf("Test for solution1\n");
    PrintProbability_Solution1(n);

    printf("Test for solution2\n");
    PrintProbability_Solution2(n);

    printf("\n");
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(4);
    
    Test(11);

    Test(0);

    return 0;
}





































