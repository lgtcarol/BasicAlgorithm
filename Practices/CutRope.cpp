/**
Debug: 在子问题最优解记录的数组中，arr[2] = 2, 不是1
*/

class Solution {
public:
    int integerBreak(int n) 
    {
        
        //整体最优解依赖于各子问题的最优解，动态规划
		//自底向上递归，陷阱：i*(n-i) 和（n-i）*i相同 
		//首先，剪绳子是最优解问题，其次，大问题包含小问题，并且大问题的最优解包含着小问题的最优解，所以可以使用动态规划求解问题，并且从小到大求解，把小问题的最优解记录在数组中，求大问题最优解时就可以直接获取，避免重复计算。 
		
		//可解子问题直接返回
		if(n == 2) 
			return 1;
		if(n == 3)
			return 2;
		//申请数组存储子问题的最优解
		int* arr = new int[n+1];
        int max = 0;
		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 3;
		for(int i = 4; i <= n; i++)
		{
			max = 0;
			for(int j = 1; j <= i/2; j++)
			{
				int product  = arr[j]*arr[i-j];
				if(product > max)
					max = product; 
                //记得将从下面得到的子问题最优解进行记录
                arr[i] = max;
			}
		}   
       // max = arr[n];
        delete[] arr;
		return max;
    }    
};

/**
贪心算法：对数学有点要求 
当n>=5时，2(n-2)>n，3(n-3)>n，这就是说，将绳子剪成2和(n-2)或者剪成3和(n-3)时，乘积大于不剪的乘积，
因此需要把绳子剪成2或者3.剪成3乘积更大，优先剪3。余数1则借出一个3换为两个2，余数2则该2直接作为因子 
*/
class Solution{
public:
	int integerBreak(int n )
	{
		if(n <2)
			return 0;
		if(n == 2) 
			return 1;
		if(n == 3)
			return 2;
			
		int numOf3 = n/3;
		if(n%3 == 1)
		{
			numOf3 -= 1; 
		}
		int numOf2 = (n-numOf3*3)/2;
		return pow(3, numOf3)*pow(2, numOf2);
	}
}; 















