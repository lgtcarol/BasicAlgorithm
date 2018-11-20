// 面试题29：顺时针打印矩阵
// 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

#include <cstdio>
/**
(1)框架倒能理清楚，但就是框架+换4个情况+每种情况不完全同。建议：框架和处理分开来写，书写理思路就是个反复的过程，多一个反复点都会增加负担。
(2)能知道每种操作的适用情况时（甚至就是一个独立模块的功能)，直接用if-条件去约束而不企图程序自适应，要知道你连自己设计的逻辑是否完备都不缺定。所以脚踏实地些。
(3)while并没有for好用，尤其是你的循环索引要在下一步去用。因为while跳出时是不满足的，这意味你需要修改到合适的值；同时，while不便于检查索引的范围，又增加了不必要的思维繁琐。 
(4)对于有规律的行走，若在每次变化后的周期内都有一个固定点则一切都很清楚。此题的（start,start）则是基线，只需描述出其在每轮的值，其他值依它而变即可！ 
*/

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start);
void printNum(int number);//重复的语句提出来做函数 

void PrintMatrixClockwisely(int** numbers, int columns, int rows)
{
	if(numbers == NULL || columns <= 0 || rows <= 0)
        return;

    int start = 0;
    while(start*2 < columns && start*2<rows)
	{
		PrintMatrixInCircle(numbers, columns, rows, start);
		start++;
	} 
} 

void PrintMatrixInCircle(int** n, int columns, int rows, int start)
{
	int endX = columns-1-start;
	int endY = rows-1-start;
	//从左到右 
	for(int i = start; i <= endX; i++)
	{
		int num = n[start][i];
		printNum(num);
	}
	//从上到下
	if(start < endY)
	{
		//用for简单：终止条件一目了然，while还自己带入判别逻辑徒增负担 
		for(int i = start+1; i <= endY; i++)
		{
		
			int num = n[i][endX];
			printNum(num);
		}
	}
	//从右到左，endX>start且endY>start才有意义 
	if(endX>start && endY>start)
	{
		for(int i = endX-1; i >= start; i--)
		{
			int num = n[endY][i];
			printNum(num);
		} 
	} 
	if(endX>start && endY-1>start) //由于矩形顶角打印的归属问题。基于前三边处理逻辑，该条边若有两个值，显然也是不能执行的，故判断条件稍有不同
	{
		for(int i = endY-1; i > start; i--)
		{
			int num = n[i][start];
			printNum(num);
		 } 
	} 
}
void printNum(int number)
{
   	printf("%d\t", number);
}










































// ====================测试代码====================
void Test(int columns, int rows)
{
    printf("Test Begin: %d columns, %d rows.\n", columns, rows);

    if(columns < 1 || rows < 1)
        return;

    int** numbers = new int*[rows];
    for(int i = 0; i < rows; ++i)
    {
        numbers[i] = new int[columns];
        for(int j = 0; j < columns; ++j)
        {
            numbers[i][j] = i * columns + j + 1;
        }
    }

    PrintMatrixClockwisely(numbers, columns, rows);
    printf("\n");

    for(int i = 0; i < rows; ++i)
        delete[] (int*)numbers[i];

    delete[] numbers;
}

int main(int argc, char* argv[])
{
    /*
    1    
    */
    Test(1, 1);

    /*
    1    2
    3    4
    */
    Test(2, 2);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
    Test(4, 4);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    21   22   23   24   25
    */
    Test(5, 5);

    /*
    1
    2
    3
    4
    5
    */
    Test(1, 5);

    /*
    1    2
    3    4
    5    6
    7    8
    9    10
    */
    Test(2, 5);

    /*
    1    2    3
    4    5    6
    7    8    9
    10   11   12
    13   14   15
    */
    Test(3, 5);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    17   18   19   20
    */
    Test(4, 5);

    /*
    1    2    3    4    5
    */
    Test(5, 1);

    /*
    1    2    3    4    5
    6    7    8    9    10
    */
    Test(5, 2);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14    15
    */
    Test(5, 3);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    */
    Test(5, 4);
    return 0;
}
// lgt：最初的混乱思路 
//void PrintMatrixClockwisely(int **nums, int cols, int rows)
//{
//	if(nums == NULL || cols <= 0 || rows <= 0)
//		return ;
//	int circle = rows/2;
//	int flag = 0;
//	
//	int inc = 0; //增量 
//	for(int cnt=0; cnt <= circle; cnt++)
//	{
//		int row = 0+inc; 
//		int col = 0+inc;
//		printf("%d\t", nums[row][col]);
//		col++;
//		while(col < cols-inc)
//		{
//			flag = 1;
//			printf("%d\t", nums[row][col]);
//			col++;
//		}
//		if(flag == 1)
//		{
//			col--;
//			flag = 0;
//		}
//		row++;
//		while(row < rows-inc)
//		{
//			flag = 1;
//			printf("%d\t", nums[row][col]);
//			row++;
//		}
//		if(flag == 1)
//		{
//			row--;
//			flag = 0;
//		}
//		col--;
//		while(col >= 0+inc)
//		{
//			flag = 1;
//			printf("%d\t", nums[row][col]);
//			col--;
//		}
//		if(flag == 1)
//		{
//			col++;
//			flag = 0;
//		}
//		row--;
//		while(row > 0+inc)
//		{
//			printf("%d\t", nums[row][col]);
//			row--;
//		}
//		inc++;
//	}
//}





































