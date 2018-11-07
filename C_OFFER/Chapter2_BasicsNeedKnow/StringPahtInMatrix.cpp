// 面试题12：矩阵中的路径
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
// 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
// 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
// A B T G
// C F C S
// J D E H
#include <cstdio>
#include <cstring>
#include <stack>
bool hasPathCore(const char* matrix,int rows, int cols, const char *str, int row, int col, int &len, bool *visited);
bool hasPath(const char *matrix, int rows, int cols, const char *str)
{
	if(matrix == NULL || rows < 1 || cols < 1 || str == NULL)
		return false;
	//回溯问题必须要记录哪些走过哪些没有，所以要有辅助的visit数组
	//其实如果是字符串的话没必要知道长度，有结束字符可以标记 
	bool *visited = new bool[rows*cols]; //可能矩阵中每个位置都要试，故而辅助自然是每个位置都需要 
	memset(visited, 0, rows*cols);//空间初始化 
	//从哪儿开始第一个字符呢？试呗
	int len = 0;//你匹配的目标串到第几位了呢？ 

	for(int row = 0; row < rows; row++)
		for(int col = 0; col < cols; col++)
		{
			if(hasPathCore(matrix, rows, cols, str, row, col, len, visited)) //此处的len其实都是0，也是便于递归结构的清晰 
				return true;//找到一条就可以返回 
		} 
	delete[] visited;
	return false;
}
bool hasPathCore(const char* matrix,int rows, int cols, const char *str, int row, int col, int &len, bool *visited) 
{
	//回溯的递归思路
	//1.本步在可走的情况下，标记为visited，修改相应值
	//2.同时在本步走的情况下下步也可以走，如此才算结束。否则撤销上步的操作（如visited恢复，len恢复）
	//Notes:回溯的递归是强调反馈的，能不能走要给上级反馈的，故而需状态变量hasPath
	//Notes:再是回溯，当其采用递归实现总强调递归的出口！如回溯则寻得目标：待匹配字符串走到'\0' 
	if(str[len] == '\0')
		return true;
	bool hasPath = false;
	//若此步可走 
	if(row>=0 && row<rows && col>=0 && col<cols && (matrix[row*cols+col] == str[len])&& (!visited[row*cols+col]))
	{
		visited[row*cols+col] = true;
		len++;

		//试探下步是否有路可走 (这也是回溯法通过递归形式实现时衔接各次试探的关键，即下步如何)
		hasPath =  hasPathCore(matrix,rows,cols,str,row-1,col, len,visited) || hasPathCore(matrix,rows,cols,str,row+1,col, len,visited) \
		|| hasPathCore(matrix,rows,cols,str,row,col-1, len,visited) || hasPathCore(matrix,rows,cols,str,row,col+1, len,visited);
		//因下步不可走，则撤销上步并回退一层 
		if(hasPath == false)
		{
			visited[row*cols+col] = false;
			len--;
		}
	} 
	//否则直接返回
	//Notes:下步判断的前提时本步可行。所以错因是逻辑混乱，直接将本步和下步的行走看作并行
	//Notes:错误的现象是崩溃！
	//分析：递归函数只是在往深的走，就从第36行的if来看按照错误的逻辑其并列下进入第42行那何时返回呢？这儿就是递归的法则，这儿无返回则深层的递归怎么可能返回
	 
	return hasPath;
}
// ====================测试代码====================
void Test(const char* testName, const char* matrix, int rows, int cols, const char* str, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(hasPath(matrix, rows, cols, str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//ABTG
//CFCS
//JDEH

//BFCE
void Test1()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "BFCE";

    Test("Test1", (const char*) matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//SEE
void Test2()
{
    const char* matrix = "ABCESFCSADEE";
    const char* str = "SEE";

    Test("Test2", (const char*) matrix, 3, 4, str, true);
}

//ABTG
//CFCS
//JDEH

//ABFB
void Test3()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "ABFB";

    Test("Test3", (const char*) matrix, 3, 4, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void Test4()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SLHECCEIDEJFGGFIE";

    Test("Test4", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void Test5()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEM";

    Test("Test5", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void Test6()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEEJIGOEM";

    Test("Test6", (const char*) matrix, 5, 8, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void Test7()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEMS";

    Test("Test7", (const char*) matrix, 5, 8, str, false);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void Test8()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAA";

    Test("Test8", (const char*) matrix, 3, 4, str, true);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void Test9()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAAA";

    Test("Test9", (const char*) matrix, 3, 4, str, false);
}

//A

//A
void Test10()
{
    const char* matrix = "A";
    const char* str = "A";

    Test("Test10", (const char*) matrix, 1, 1, str, true);
}

//A

//B
void Test11()
{
    const char* matrix = "A";
    const char* str = "B";

    Test("Test11", (const char*) matrix, 1, 1, str, false);
}

void Test12()
{
    Test("Test12", NULL, 0, 0, NULL, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();
    Test12();

    return 0;
}
