// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

//通过矩阵中寻找字串的回溯思路，可以掌握本题，以下（）中为易忽略点
//1.输入参数检查 2.递归函数形参和返回值设计 3.visited数组申请 （与初始化）
//4.递归函数出口设计或返回方式确定 5.（符合要求时相关变量登记）
//(注意：某些记录值在以返回值还是形参返回，需不需要带回，那么是值传递还是引用传递)

//与上题区别：
//1. 上题是按要求搜索目标，一旦不可行不仅要结束本步同时回退字串（涉及变量恢复），对应的位置再试探 
//2. 本题是搜索所有能到达的位置，返回个数而非匹配的true or false
//3. 本题要求能达到的方格数，不论是从限定条件还是从目标来看都只与位置有关，不需要位置上的具体值（故而参数上并不需矩阵） 
#include <cstdio>
#include <cstring>
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited);
bool check(int row, int col, int threshold);
int movingCount(int threshold, int rows, int cols)
{
	if(threshold<0 || rows<1 || cols<1)
		return 0;
	bool *visited = new bool[rows*cols];
	for(int i = 0; i < rows * cols; ++i)
        visited[i] = false;
	int row = 0, col = 0;
	int cnt = movingCountCore(threshold, rows, cols, row, col, visited);
//	printf("return from core\n");
	delete[] visited;
	return cnt;
} 
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited)
{
	int cnt = 0;
	if(row>=0 && row<rows && col>=0 && col<cols && check(threshold, row, col) && visited[row*cols+col]==false)
	{
	//	printf("taging: (%d, %d)\t", row, col);
		visited[row*cols+col] = true;		
		cnt = 1 + movingCountCore(threshold, rows, cols, row-1, col, visited)+movingCountCore(threshold, rows, cols, row+1, col, visited)+\
		movingCountCore(threshold, rows, cols, row, col-1, visited)+movingCountCore(threshold, rows, cols, row, col+1, visited);
	
	} 
//	else
//	{
//			printf("something invalid\n");
//	}
	return cnt;
} 
bool check(int threshold, int row, int col)
{
	//分别从row和col获取数字相加和
	int sum1 = 0;
	int sum2 = 0;

	while(row > 0)
	{
		sum1 += row%10;
		row /= 10;
	 } 
	 while(col > 0)
	 {
	 	sum2 += col%10;
	 	col /= 10;
	 }
	 if(sum1+sum2 <= threshold)
	 	return true;
	else
		return false;
}
 // ====================测试代码====================
void test(const char* testName, int threshold, int rows, int cols, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(movingCount(threshold, rows, cols) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// 方格多行多列
void test1()
{
    test("Test1", 5, 10, 10, 21);
}

// 方格多行多列
void test2()
{
    test("Test2", 15, 20, 20, 359);
}

// 方格只有一行，机器人只能到达部分方格
void test3()
{
    test("Test3", 10, 1, 100, 29);
}

// 方格只有一行，机器人能到达所有方格
void test4()
{
    test("Test4", 10, 1, 10, 10);
}

// 方格只有一列，机器人只能到达部分方格
void test5()
{
    test("Test5", 15, 100, 1, 79);
}

// 方格只有一列，机器人能到达所有方格
void test6()
{
    test("Test6", 15, 10, 1, 10);
}

// 方格只有一行一列
void test7()
{
    test("Test7", 15, 1, 1, 1);
}

// 方格只有一行一列
void test8()
{
    test("Test8", 0, 1, 1, 1);
}

// 机器人不能进入任意一个方格
void test9()
{
    test("Test9", -10, 10, 10, 0);
}

int main(int agrc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();

    return 0;
}
 /**错误总结：
 1. new生成数组是[],不是（）
 2. 边界值本就是考点，要仔细。比如坐标是>=的数，那么位数之和的阈值threhold显然可能取到0.则不合格检验的条件是threhold<0,否则会使得样例不通过
 3. 这道题作为递归遍历，打印出可访问的坐标，便于理解递归程序的调用过程。 
 4. 输出打印法debug, 不断缩小范围，抽取出代码片段进行逻辑验证。 
 */
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
