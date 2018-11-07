// ������13�������˵��˶���Χ
// ��Ŀ��������һ��m��n�еķ���һ�������˴�����(0, 0)�ĸ��ӿ�ʼ�ƶ�����
// ÿһ�ο��������ҡ��ϡ����ƶ�һ�񣬵����ܽ�������������������λ֮��
// ����k�ĸ��ӡ����磬��kΪ18ʱ���������ܹ����뷽��(35, 37)����Ϊ3+5+3+7=18��
// �������ܽ��뷽��(35, 38)����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�

//ͨ��������Ѱ���ִ��Ļ���˼·���������ձ��⣬���£�����Ϊ�׺��Ե�
//1.���������� 2.�ݹ麯���βκͷ���ֵ��� 3.visited�������� �����ʼ����
//4.�ݹ麯��������ƻ򷵻ط�ʽȷ�� 5.������Ҫ��ʱ��ر����Ǽǣ�
//(ע�⣺ĳЩ��¼ֵ���Է���ֵ�����βη��أ��費��Ҫ���أ���ô��ֵ���ݻ������ô���)

//����������
//1. �����ǰ�Ҫ������Ŀ�꣬һ�������в���Ҫ��������ͬʱ�����ִ����漰�����ָ�������Ӧ��λ������̽ 
//2. ���������������ܵ����λ�ã����ظ�������ƥ���true or false
//3. ����Ҫ���ܴﵽ�ķ������������Ǵ��޶��������Ǵ�Ŀ��������ֻ��λ���йأ�����Ҫλ���ϵľ���ֵ���ʶ������ϲ�������� 
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
	//�ֱ��row��col��ȡ������Ӻ�
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
 // ====================���Դ���====================
void test(const char* testName, int threshold, int rows, int cols, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(movingCount(threshold, rows, cols) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// ������ж���
void test1()
{
    test("Test1", 5, 10, 10, 21);
}

// ������ж���
void test2()
{
    test("Test2", 15, 20, 20, 359);
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void test3()
{
    test("Test3", 10, 1, 100, 29);
}

// ����ֻ��һ�У��������ܵ������з���
void test4()
{
    test("Test4", 10, 1, 10, 10);
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void test5()
{
    test("Test5", 15, 100, 1, 79);
}

// ����ֻ��һ�У��������ܵ������з���
void test6()
{
    test("Test6", 15, 10, 1, 10);
}

// ����ֻ��һ��һ��
void test7()
{
    test("Test7", 15, 1, 1, 1);
}

// ����ֻ��һ��һ��
void test8()
{
    test("Test8", 0, 1, 1, 1);
}

// �����˲��ܽ�������һ������
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
 /**�����ܽ᣺
 1. new����������[],���ǣ���
 2. �߽�ֵ�����ǿ��㣬Ҫ��ϸ������������>=��������ôλ��֮�͵���ֵthrehold��Ȼ����ȡ��0.�򲻺ϸ�����������threhold<0,�����ʹ��������ͨ��
 3. �������Ϊ�ݹ��������ӡ���ɷ��ʵ����꣬�������ݹ����ĵ��ù��̡� 
 4. �����ӡ��debug, ������С��Χ����ȡ������Ƭ�ν����߼���֤�� 
 */
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
