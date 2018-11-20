// ������29��˳ʱ���ӡ����
// ��Ŀ������һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֡�

#include <cstdio>
/**
(1)��ܵ���������������ǿ��+��4�����+ÿ���������ȫͬ�����飺��ܺʹ���ֿ���д����д��˼·���Ǹ������Ĺ��̣���һ�������㶼�����Ӹ�����
(2)��֪��ÿ�ֲ������������ʱ����������һ������ģ��Ĺ���)��ֱ����if-����ȥԼ��������ͼ��������Ӧ��Ҫ֪�������Լ���Ƶ��߼��Ƿ��걸����ȱ�������Խ�̤ʵ��Щ��
(3)while��û��for���ã����������ѭ������Ҫ����һ��ȥ�á���Ϊwhile����ʱ�ǲ�����ģ�����ζ����Ҫ�޸ĵ����ʵ�ֵ��ͬʱ��while�����ڼ�������ķ�Χ���������˲���Ҫ��˼ά������ 
(4)�����й��ɵ����ߣ�����ÿ�α仯��������ڶ���һ���̶�����һ�ж������������ģ�start,start�����ǻ��ߣ�ֻ������������ÿ�ֵ�ֵ������ֵ�������伴�ɣ� 
*/

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start);
void printNum(int number);//�ظ����������������� 

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
	//������ 
	for(int i = start; i <= endX; i++)
	{
		int num = n[start][i];
		printNum(num);
	}
	//���ϵ���
	if(start < endY)
	{
		//��for�򵥣���ֹ����һĿ��Ȼ��while���Լ������б��߼�ͽ������ 
		for(int i = start+1; i <= endY; i++)
		{
		
			int num = n[i][endX];
			printNum(num);
		}
	}
	//���ҵ���endX>start��endY>start�������� 
	if(endX>start && endY>start)
	{
		for(int i = endX-1; i >= start; i--)
		{
			int num = n[endY][i];
			printNum(num);
		} 
	} 
	if(endX>start && endY-1>start) //���ھ��ζ��Ǵ�ӡ�Ĺ������⡣����ǰ���ߴ����߼�����������������ֵ����ȻҲ�ǲ���ִ�еģ����ж��������в�ͬ
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










































// ====================���Դ���====================
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
// lgt������Ļ���˼· 
//void PrintMatrixClockwisely(int **nums, int cols, int rows)
//{
//	if(nums == NULL || cols <= 0 || rows <= 0)
//		return ;
//	int circle = rows/2;
//	int flag = 0;
//	
//	int inc = 0; //���� 
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





































