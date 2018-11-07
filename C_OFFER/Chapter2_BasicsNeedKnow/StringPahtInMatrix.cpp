// ������12�������е�·��
// ��Ŀ�������һ�������������ж���һ���������Ƿ����һ������ĳ�ַ�������
// �ַ���·����·�����ԴӾ���������һ��ʼ��ÿһ�������ھ����������ҡ�
// �ϡ����ƶ�һ�����һ��·�������˾����ĳһ����ô��·�������ٴν���
// �ø��ӡ������������3��4�ľ����а���һ���ַ�����bfce����·����·���е���
// ĸ���»��߱�������������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ��
// �ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�
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
	//�����������Ҫ��¼��Щ�߹���Щû�У�����Ҫ�и�����visit����
	//��ʵ������ַ����Ļ�û��Ҫ֪�����ȣ��н����ַ����Ա�� 
	bool *visited = new bool[rows*cols]; //���ܾ�����ÿ��λ�ö�Ҫ�ԣ��ʶ�������Ȼ��ÿ��λ�ö���Ҫ 
	memset(visited, 0, rows*cols);//�ռ��ʼ�� 
	//���Ķ���ʼ��һ���ַ��أ�����
	int len = 0;//��ƥ���Ŀ�괮���ڼ�λ���أ� 

	for(int row = 0; row < rows; row++)
		for(int col = 0; col < cols; col++)
		{
			if(hasPathCore(matrix, rows, cols, str, row, col, len, visited)) //�˴���len��ʵ����0��Ҳ�Ǳ��ڵݹ�ṹ������ 
				return true;//�ҵ�һ���Ϳ��Է��� 
		} 
	delete[] visited;
	return false;
}
bool hasPathCore(const char* matrix,int rows, int cols, const char *str, int row, int col, int &len, bool *visited) 
{
	//���ݵĵݹ�˼·
	//1.�����ڿ��ߵ�����£����Ϊvisited���޸���Ӧֵ
	//2.ͬʱ�ڱ����ߵ�������²�Ҳ�����ߣ���˲���������������ϲ��Ĳ�������visited�ָ���len�ָ���
	//Notes:���ݵĵݹ���ǿ�������ģ��ܲ�����Ҫ���ϼ������ģ��ʶ���״̬����hasPath
	//Notes:���ǻ��ݣ�������õݹ�ʵ����ǿ���ݹ�ĳ��ڣ��������Ѱ��Ŀ�꣺��ƥ���ַ����ߵ�'\0' 
	if(str[len] == '\0')
		return true;
	bool hasPath = false;
	//���˲����� 
	if(row>=0 && row<rows && col>=0 && col<cols && (matrix[row*cols+col] == str[len])&& (!visited[row*cols+col]))
	{
		visited[row*cols+col] = true;
		len++;

		//��̽�²��Ƿ���·���� (��Ҳ�ǻ��ݷ�ͨ���ݹ���ʽʵ��ʱ�νӸ�����̽�Ĺؼ������²����)
		hasPath =  hasPathCore(matrix,rows,cols,str,row-1,col, len,visited) || hasPathCore(matrix,rows,cols,str,row+1,col, len,visited) \
		|| hasPathCore(matrix,rows,cols,str,row,col-1, len,visited) || hasPathCore(matrix,rows,cols,str,row,col+1, len,visited);
		//���²������ߣ������ϲ�������һ�� 
		if(hasPath == false)
		{
			visited[row*cols+col] = false;
			len--;
		}
	} 
	//����ֱ�ӷ���
	//Notes:�²��жϵ�ǰ��ʱ�������С����Դ������߼����ң�ֱ�ӽ��������²������߿�������
	//Notes:����������Ǳ�����
	//�������ݹ麯��ֻ����������ߣ��ʹӵ�36�е�if�������մ�����߼��䲢���½����42���Ǻ�ʱ�����أ�������ǵݹ�ķ�������޷��������ĵݹ���ô���ܷ���
	 
	return hasPath;
}
// ====================���Դ���====================
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
