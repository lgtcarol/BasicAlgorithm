// 面试题65：不用加减乘除做加法
// 题目：写一个函数，求两个整数之和，要求在函数体内不得使用＋、－、×、÷
// 四则运算符号。

#include <cstdio>

int Add(int num1, int num2)
{
    int sum, carry;
    do
    {
        sum = num1 ^ num2; //lgt:不考虑进位的各位累加 
        carry = (num1 & num2) << 1; // lgt: 通过总结累加中产生进位的逻辑表达（类似数字电路中真值表），发现与后左一意味 

        num1 = sum;
        num2 = carry;
    }
    while(num2 != 0);//NOTE:获取的进位carry竟作为循环条件，多次执行难道不会计算多次吗？
	//lgt解答：第一次carry逻辑产生没错，但显然在第二次循环到sum求解时只有原先为1的位会受影响，且该进位上也为1才会产生一次进位。（从亦或逻辑去考虑到底谁受影响） 

    return num1;
}

// ====================测试代码====================
void Test(int num1, int num2, int expected)
{
    int result = Add(num1, num2);
    if(result == expected)
        printf("%d + %d is %d. Passed\n", num1, num2, result);
    else
        printf("%d + %d is %d. FAILED\n", num1, num2, result);
}

int main(int argc, char* argv[])
{
    Test(1, 2, 3);
    Test(111, 899, 1010);

    Test(-1, 2, 1);
    Test(1, -2, -1);

    Test(3, 0, 3);
    Test(0, -4, -4);

    Test(-2, -8, -10);

    return 0;
}
