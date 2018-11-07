#include <stdio.h>
#include <stdlib.h>
long long Fibonacci_Solution1(unsigned int n)
{
	if (n <= 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		return Fibonacci_Solution1(n-1) + Fibonacci_Solution1(n-2);
	//direct iterative lead to 重复！ 
}
long long Fibonacci_Solution2(unsigned int n)
{
	if (n <= 0)
		return 0;
	else if(n == 1)
		return 1;
	else
	{
		long long x1 = 0;
		long long x2 = 1;
		long long next = 0;
		for(int i = 2; i <= n; i++)//你丫，居然能把for循环初始值和控制条件的逻辑执行顺序搞混！！！ 
		{
			next = x1 + x2;
			x1 = x2;
			x2 = next;
		} 
		return next;
	}
}

void Test(int n, int expected)
{
    if(Fibonacci_Solution1(n) == expected)
        printf("Test for %d in solution1 passed.\n", n);
    else
        printf("Test for %d in solution1 failed.\n", n);

    if(Fibonacci_Solution2(n) == expected)
        printf("Test for %d in solution2 passed.\n", n);
    else
        printf("Test for %d in solution2 failed.\n", n);

//    if(Fibonacci_Solution3(n) == expected)
//        printf("Test for %d in solution3 passed.\n", n);
//    else
//        printf("Test for %d in solution3 failed.\n", n);
}

int main(int argc, char* argv[])
{
    Test(0, 0);
    Test(1, 1);
    Test(2, 1);
    Test(3, 2);
    Test(4, 3);
    Test(5, 5);
    Test(6, 8);
    Test(7, 13);
    Test(8, 21);
    Test(9, 34);
    Test(10, 55);

    Test(40, 102334155);

    return 0;
}
