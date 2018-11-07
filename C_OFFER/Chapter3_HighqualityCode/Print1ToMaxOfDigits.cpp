// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。

#include <cstdio>
#include <cmath>
#include <cstring>
void Print1ToMaxOfNDigits(int n);
void Print1ToMaxOfNDigits_1(int n);
bool Increment(char *num);
void Print1ToMaxOfNDigits_2(int n);
void Print1ToMaxNDigitsRecursively(char *num, int n, int index);
void PrintNumber(char *num);

void Print1ToMaxOfNDigits(int n)
{
	if(n <= 0)
		return;
	//常规想法，根据数位n构成出该数，利用循环累加打印即可
	long long num = pow(10,n);
	for(long long i = 0; i < num; i++)
		printf("%lld \t", i);
}
//显然4字节int也只到21亿，即n=10，而本题并未说n的范围
//跳出思维陷阱：大整数问题！

void Print1ToMaxOfNDigits_1(int n)
{
	if(n <= 0)
		return;
	char *num = new char[n+1];//字符串结束标志
	memset(num, '0', n);//申请空间后的初始化！别忘 
	num[n] = '\0';
	
	//Notes:其实变量在引用型参数number中，Increment()所做的就是加一，并通过number带回改变。
	//套在while循环内部，每调用一次返回一个bool值。 
	while(!Increment(num))
	{
		PrintNumber(num);
	} 
	delete []num;
} 

bool Increment(char *num)
{
	//从本函数设计目标来看，需要知道何时打印完毕，即合适到达n位数
	bool isOverflow = false; 
	//模拟数字运算逃不掉进位借位，打印1~10^n数过程是累加借位过程 
	//为便于进位直接参与运算，设为int变量
	int nTakeOver = 0;
	int len = strlen(num);
	for(int i = len-1; i >= 0; i--)
	{
		int nSum = num[i] - '0' + nTakeOver;
		if(i == len-1)
			nSum++;//个位增一，但是仅一次？
		//Notes:是的！函数本身并非递归，但每调用该函数一次便实现一次加一，而这种改变通过引用参数带回 
		//借助返回后的while循环，实现多次自增，直到某次调用函数返回false，终止该函数的调用即终止加一过程
		//while(f())结构，f()返回false时类似递归函数的出口一般 
		
		//Notes:具象为现实操作，数据增一不就是在个位加一。
		//Notes:既通过string实现int问题，如何衔接？不就是'0'+真值 
		if(nSum >= 10)
		{
			if(i == 0){ 
				isOverflow = true;
				break; 
			} 
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				num[i] = '0' + nSum; 
			}
		} 
		else
		{
			//如果没有进位是可以直接结束加一过程的！所以是break 
			num[i] = '0' + nSum;
			break;
		}
	}
	 return isOverflow; 
}
void Print1ToMaxOfNDigits_2(int n)
{
	if( n <= 0)
		return;
	char *num = new char[n+1];
	memset(num, '0', n);
	num[n] = '\0';
	for(int i =0; i < 10 ;i++)
	{
		num[0] = i + '0';//列举的是数组下标0的情况 
		Print1ToMaxNDigitsRecursively(num, n, 0); //递归列举下标为0+1的情况 
	}
}
void Print1ToMaxNDigitsRecursively(char *num, int n, int index)
{
	printf("start of program ,index: %d \n",index);
	if(index == n-1)//n位数的最大下标到n-1 
	{
		//结合自下而上的实现方式亦或递归的栈属性，位数少的数先打印
		printf("begin return\t");
	//	num[index] = '\0'; 
		PrintNumber(num);
		return;	
	} 
	for(int i =0; i < 10 ;i++)
	{
		num[index+1] = i + '0';
//		printf("index:%d, %c ", index, num[index]); 
		Print1ToMaxNDigitsRecursively(num, n, index+1);
	}
}


void PrintNumber(char *num)
{
	bool start = false;
	int len = strlen(num);
//	printf("hello\n");
	for(int i = 0; i < len; i++)
	{
		if( num[i]!='0' && start==false )
			start = true;//开始打印 
		if(start == true)
			printf("%c", num[i]);
	}
	printf("\t");
}

// ====================测试代码====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);

  //  Print1ToMaxOfNDigits_1(n);
    Print1ToMaxOfNDigits_2(n);

    printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(0);
    Test(-1);

    return 0;
}
/**
solution1:在判断溢出后只设置了flag值却忘记跳出循环结束。注意每种情况操作的完整性
solution2:类似于排列树的思路，当前函数枚举对应的index和递归调用的index是相同的，而非我认为的index和index+1关系？！
(1)是因为若index+1进入最后一层则直接开始打印，即缺少该位的遍历.如n=2时我们只能打印出10-90，缺少对个位的遍历
(2)不过程序死循环是因为循环程序设计逻辑错误(覆盖情况不全)。如n=1时，index-1=0开始退出，而我们设计进入程序的最小index=1,永远取不到0，程序永远无法退出。

(3)递归程序设计还是要熟悉，看看这些打印的结果熟悉递归！ 
*/














