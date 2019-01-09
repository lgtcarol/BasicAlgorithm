
// 面试题54：二叉搜索树的第k个结点
// 题目：给定一棵二叉搜索树，请找出其中的第k大的结点。

#include <cstdio>
#include "Utilities/BinaryTree.cpp"
/**
1. 本题虽然知道用中序遍历，但本节点如何体现？
2. k 是以形参还是返回值方式 
3. Note: 没做到递归遍历树的活学活用，建议参考其他解法 。在返回值上多做考虑 
*/

const BinaryTreeNode* KthNodeCore(const BinaryTreeNode* p, unsigned int& k);
const BinaryTreeNode* KthNode(const BinaryTreeNode* p, unsigned int k)
{
	if(p == NULL || k == 0)
		return NULL;
	return KthNodeCore(p, k);
}
const BinaryTreeNode* KthNodeCore(const BinaryTreeNode* p, unsigned int& k)
{
	const BinaryTreeNode* target = NULL;
	if(p->m_pLeft != NULL)
		target = KthNodeCore(p->m_pLeft, k);
	if(target == NULL) //未找到目标节点 
	{
		if(k == 1)
			target = p; //当前节点即为目标
		k--; 
	}
	if(target==NULL && p->m_pRight!=NULL)
		target = KthNodeCore(p->m_pRight, k);
	return target;
	//反思：递归函数想知道各子步骤实现了什么，追踪target发现实际有效更改唯有一处：target=p
	//       所以target到底记录了什么也一步了然 
}


// ====================测试代码====================
void Test(const char* testName, const BinaryTreeNode* pRoot, unsigned int k, bool isNull, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    const BinaryTreeNode* pTarget = KthNode(pRoot, k);
    if((isNull && pTarget == NULL) || (!isNull && pTarget->m_nValue == expected))
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void TestA()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    Test("TestA0", pNode8, 0, true, -1);
    Test("TestA1", pNode8, 1, false, 5);
    Test("TestA2", pNode8, 2, false, 6);
    Test("TestA3", pNode8, 3, false, 7);
    Test("TestA4", pNode8, 4, false, 8);
    Test("TestA5", pNode8, 5, false, 9);
    Test("TestA6", pNode8, 6, false, 10);
    Test("TestA7", pNode8, 7, false, 11);
    Test("TestA8", pNode8, 8, true, -1);

    DestroyTree(pNode8);

    printf("\n\n");
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
void TestB()
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

    Test("TestB0", pNode5, 0, true, -1);
    Test("TestB1", pNode5, 1, false, 1);
    Test("TestB2", pNode5, 2, false, 2);
    Test("TestB3", pNode5, 3, false, 3);
    Test("TestB4", pNode5, 4, false, 4);
    Test("TestB5", pNode5, 5, false, 5);
    Test("TestB6", pNode5, 6, true, -1);

    DestroyTree(pNode5);

    printf("\n\n");
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
void TestC()
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

    Test("TestC0", pNode1, 0, true, -1);
    Test("TestC1", pNode1, 1, false, 1);
    Test("TestC2", pNode1, 2, false, 2);
    Test("TestC3", pNode1, 3, false, 3);
    Test("TestC4", pNode1, 4, false, 4);
    Test("TestC5", pNode1, 5, false, 5);
    Test("TestC6", pNode1, 6, true, -1);

    DestroyTree(pNode1);

    printf("\n\n");
}

// There is only one node in a tree
void TestD()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    Test("TestD0", pNode1, 0, true, -1);
    Test("TestD1", pNode1, 1, false, 1);
    Test("TestD2", pNode1, 2, true, -1);

    DestroyTree(pNode1);

    printf("\n\n");
}

// empty tree
void TestE()
{
    Test("TestE0", NULL, 0, true, -1);
    Test("TestE1", NULL, 1, true, -1);

    printf("\n\n");
}

int main(int argc, char* argv[])
{
    TestA();
    TestB();
    TestC();
    TestD();
    TestE();
}
