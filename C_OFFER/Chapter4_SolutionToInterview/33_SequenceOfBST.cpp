/**
(1)递归出口不止在函数返回能体现，在深入递归处也能清楚这样走下去会有终点（要有意识在此处看到深入不可行的地方，如此才能尽量避免递归死循环同时也是思路清晰的体现）
(2)二叉树由于其结构（或者说问题特点）通常是逻辑与的递归设计
(3)NOTE:先深入剖析问题描述，寻找有用信息和联系，然后在结合问题本身和目标寻找整体思路。如：后序遍历有个定点是root位置已知，还有规律存在的左右孩子 
(4)!!!NOTE: 把数组看成指针是个很必要的思路，当然跟本题的问题结构有关，但这个思路直接关系到递归框架 
*/
#include <cstdio>
bool VerifySquenceOfBST(int s[], int len)
{
	if(s==NULL || len<=0)
		return false;
	int r = s[len-1];
	//类似qSort的划分思想，分块递归解决
	int i = 0;
	for(; i < len-1; i++)
	{
		if(s[i] > r)
			break;	
	} 
	//显然此处出来的一定是右子开始处
	int j = i;
	for(; j < len-1; j++)
	{
		if(s[j] < r)
			return false;//尽管是对称的处理，但此处是返回注意区别。	
	} 
	//递归准备
	int len1 = i;
	int len2 = j-i;  
	return  VerifySquenceOfBST(s, len1) && VerifySquenceOfBST(s+i, len2);
	//ATTENTION:显然能看出来len1或len2是会为0的，而若如此递归函数返回无法再深入继续 
}

// ====================测试代码====================
void Test(const char* testName, int sequence[], int length, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(VerifySquenceOfBST(sequence, length) == expected)
        printf("passed.\n");
    else
        printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    int data[] = {4, 8, 6, 12, 16, 14, 10};
    Test("Test1", data, sizeof(data)/sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2()
{
    int data[] = {4, 6, 7, 5};
    Test("Test2", data, sizeof(data)/sizeof(int), true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test3()
{
    int data[] = {1, 2, 3, 4, 5};
    Test("Test3", data, sizeof(data)/sizeof(int), true);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test4()
{
    int data[] = {5, 4, 3, 2, 1};
    Test("Test4", data, sizeof(data)/sizeof(int), true);
}

// 树中只有1个结点
void Test5()
{
    int data[] = {5};
    Test("Test5", data, sizeof(data)/sizeof(int), true);
}

void Test6()
{
    int data[] = {7, 4, 6, 5};
    Test("Test6", data, sizeof(data)/sizeof(int), false);
}

void Test7()
{
    int data[] = {4, 6, 12, 8, 16, 14, 10};
    Test("Test7", data, sizeof(data)/sizeof(int), false);
}

void Test8()
{
    Test("Test8", NULL, 0, false);
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

    return 0;
}





















