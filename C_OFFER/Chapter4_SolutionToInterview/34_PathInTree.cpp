/**
1.通用思路学习：
(1)设计递归函数进行回溯，入函数 为一个状态；出函数恢复 
(2)栈的思路（递归函数这个形式就可以满足），自己在每步记录关注的信息（比如为了在这步也可以打印之前所有 ）和为达到目标而不断更新的值
(3)若在本步想打印之前所有，在设置记录变量时stack并不适用，可以用vector(数据结构上的思考)
2.本题设计思路总结：
step1: 递归变量修改作为函数参数（本题修改两个：currentSum和path）
step2: 判断条件的满足性，满足后本步的后续显然也不能执行，本步返回
step3: 条件不满足继续进行深度遍历，NOTE:进行深下去显然不会只有一种选择不然也构不成回溯，回溯则是试探返回换路再试探过程。 
*/
#include <cstdio>
#include "Utilities\BinaryTree.cpp"
#include <vector>
//语法问题：path数组作为参数因为用vector，在此注意引用变量类型 
void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int currentSum);

void FindPath(BinaryTreeNode* r, int tarSum)
{
	if(r==NULL || tarSum==0)
		return ;
	std::vector<int> path;
	int curSum = 0;
	FindPath(r, tarSum, path, curSum);
	return; 
} 
//后期更改：curSum不必引用？ 是的，可能作者是一致减少大脑思考分支 
void FindPath(BinaryTreeNode* r, int tarSum, std::vector<int>& path, int curSum)
{
	curSum += r->m_nValue;
	path.push_back(r->m_nValue);
	
	//ATTENTION: 此题不是在每步都有资格判断是否满足的，必须是叶节点
	if(r->m_pLeft==NULL || r->m_pRight==NULL)
	{
		if(curSum == tarSum)
		{
			printf("A path is founded!\n");
			//迭代器遍历输出问题
			std::vector<int>::iterator iter = path.begin();
			for(; iter!=path.end(); iter++)
				printf("%d\t", *iter);
			printf("\n");	
	    }	
	} 
	if(r->m_pLeft != NULL)
		FindPath(r->m_pLeft, tarSum, path, curSum);
	if(r->m_pRight!=NULL)
		FindPath(r->m_pRight, tarSum, path, curSum);
	
	path.pop_back();
}

// ====================测试代码====================
void Test(const char* testName, BinaryTreeNode* pRoot, int expectedSum)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    FindPath(pRoot, expectedSum);

    printf("\n");
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// 有两条路径上的结点和为22
void Test1()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);

    printf("Two paths should be found in Test1.\n");
    Test("Test1", pNode10, 22);

    DestroyTree(pNode10);
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// 没有路径上的结点和为15
void Test2()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);

    printf("No paths should be found in Test2.\n");
    Test("Test2", pNode10, 15);

    DestroyTree(pNode10);
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
// 有一条路径上面的结点和为15
void Test3()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode3, NULL);
    ConnectTreeNodes(pNode3, pNode2, NULL);
    ConnectTreeNodes(pNode2, pNode1, NULL);

    printf("One path should be found in Test3.\n");
    Test("Test3", pNode5, 15);

    DestroyTree(pNode5);
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
// 没有路径上面的结点和为16
void Test4()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, NULL, pNode2);
    ConnectTreeNodes(pNode2, NULL, pNode3);
    ConnectTreeNodes(pNode3, NULL, pNode4);
    ConnectTreeNodes(pNode4, NULL, pNode5);

    printf("No paths should be found in Test4.\n");
    Test("Test4", pNode1, 16);

    DestroyTree(pNode1);
}

// 树中只有1个结点
void Test5()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    printf("One path should be found in Test5.\n");
    Test("Test5", pNode1, 1);

    DestroyTree(pNode1);
}

// 树中没有结点
void Test6()
{
    printf("No paths should be found in Test6.\n");
    Test("Test6", NULL, 0);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}













































