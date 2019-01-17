// 面试题66：构建乘积数组
// 题目：给定一个数组A[0, 1, …, n-1]，请构建一个数组B[0, 1, …, n-1]，其
// 中B中的元素B[i] =A[0]×A[1]×… ×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

#include <cstdio>
#include <vector>

using namespace std;
/** 
NOTE: 相比lgt解法，模板解法仅用了O(n)+1辅助空间，而java解法用了O(3n)
       且在C[]和D[]的构造上，lgt同时构造，模板则依次构造
自己实现这两种，尤其lgt用C实现！ 
*/
void BuildProductionArray(const vector<double>& input, vector<double>& output)
{
    int length1 = input.size(); // A数组长度 
    int length2 = output.size();

    if(length1 == length2 && length2 > 1)
    {
        output[0] = 1;
        for(int i = 1; i < length1; ++i)
        {
            output[i] = output[i - 1] * input[i - 1];//矩阵最后一行C[i] 
        }

        double temp = 1;
        for(int i = length1 - 2; i >= 0; --i)
        {
            temp *= input[i + 1];//temp为当前循环中i的i+1,相当于依次产生矩阵D中元素，从n-2开始因n-1为temp=1 
            output[i] *= temp;//output[i]记录的恰为C[i]，而temp恰为D[i] 
        }
    }
}
/**lgt: 更符合分析的解法 java
public class Solution{
	public int[] multiply(int[] A){
		int[] result = null;
		if(A==NULL || A.length==0)
			return result;
			
		result = new int[A.length];
		int[] C = new int[A.length];
		C[0] = 1;
		int[] D = new int[A.length];
		D[A.length-1] = 1;
		
		
		for(int i = 1; i < A.length; i++){ 
		//特别注意此处D[]，因它是自下而上生成！不要和计算所用的C[i]*D[i]搞混 
		//由于迭加逻辑的不同，C[]和D[]中元素不可能同时产生 
			C[i] = C[i-1] * A[i-1];
			D[A.length-1-i] = D[A.length-1-(i-1)]*A[A.length-1-(i-1)];
		}
		
		for(int i = 0; i < A.length; i++){
			result[i] = C[i] * D[i];
	    }
	    return result;
    }
}
 
*/
//================= Test Code =================
static bool EqualArrays(const vector<double>& input, const vector<double>& output)
{
    int length1 = input.size();
    int length2 = output.size();

    if(length1 != length2)
        return false;

    for(int i = 0; i < length1; ++i)
    {
        if(abs(input[i] - output[i]) > 0.0000001)
            return false;
    }

    return true;
}

static void test(char* testName, const vector<double>& input, vector<double>& output, const vector<double>& expected)
{
    printf("%s Begins: ", testName);

    BuildProductionArray(input, output);
    if(EqualArrays(output, expected))
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

static void test1()
{
    // 输入数组中没有0
    double input[] = { 1, 2, 3, 4, 5 };
    double output[] = { 0, 0, 0, 0, 0 };
    double expected[] = { 120, 60, 40, 30, 24 };

    test("Test1", vector<double>(input, input + sizeof(input) / sizeof(double)),
        vector<double>(output, output + sizeof(output) / sizeof(double)),
        vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
}

static void test2()
{
    // 输入数组中有一个0
    double input[] = { 1, 2, 0, 4, 5 };
    double output[] = { 0, 0, 0, 0, 0 };
    double expected[] = { 0, 0, 40, 0, 0 };

    test("Test2", vector<double>(input, input + sizeof(input) / sizeof(double)),
        vector<double>(output, output + sizeof(output) / sizeof(double)),
        vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
}

static void test3()
{
    // 输入数组中有两个0
    double input[] = { 1, 2, 0, 4, 0 };
    double output[] = { 0, 0, 0, 0, 0 };
    double expected[] = { 0, 0, 0, 0, 0 };

    test("Test3", vector<double>(input, input + sizeof(input) / sizeof(double)),
        vector<double>(output, output + sizeof(output) / sizeof(double)),
        vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
}

static void test4()
{
    // 输入数组中有正、负数
    double input[] = { 1, -2, 3, -4, 5 };
    double output[] = { 0, 0, 0, 0, 0 };
    double expected[] = { 120, -60, 40, -30, 24 };

    test("Test4", vector<double>(input, input + sizeof(input) / sizeof(double)),
        vector<double>(output, output + sizeof(output) / sizeof(double)),
        vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
}

static void test5()
{
    // 输入输入中只有两个数字
    double input[] = { 1, -2 };
    double output[] = { 0, 0 };
    double expected[] = { -2, 1 };

    test("Test5", vector<double>(input, input + sizeof(input) / sizeof(double)),
        vector<double>(output, output + sizeof(output) / sizeof(double)),
        vector<double>(expected, expected + sizeof(expected) / sizeof(double)));
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}
