#include <cstdio>
#include "Utilities\BinaryTree.cpp"
#include <stack>
#include <queue>
//QUESTION: 既然先交换左右子为何还要用栈？直接进行层次遍历逐个节点进行镜像即可啊。从结果来看用queue和stack没区别 
using namespace std;
/**
(1) 树结构的基本操作就是遍历，主流递归，非递归有其需求特点。从对象属性特征找角度不妨一试 
(2) 这种递归+指针应该作图，逻辑和直观感觉差距很大。如：交换两个节点，形象直观的只是两个节点交换，其儿子怎么继续操作很难思考，以为是此问题复杂\\
    实质画图就发现在交换树中两个节点时其实是两个分支的交换。
(3) 关于返回值的判断不必言之过早。在考虑到函数的操作以及递归的整个流程就发现，在函数内部已进行所需的操作无需带返回值。 
*/
void MirrorIteratively(BinaryTreeNode* p);
void MirrorRecursively(BinaryTreeNode *p)
{
	if(p != NULL)
	{
		BinaryTreeNode *t = p->m_pLeft;
		p->m_pLeft = p->m_pRight;
		p->m_pRight = t;
		MirrorRecursively(p->m_pLeft);
		MirrorRecursively(p->m_pRight);
	} 
	return ;
}

//void MirrorIteratively(BinaryTreeNode* pRoot)
//{
//    if(pRoot == NULL)
//        return;
//
//    std::stack<BinaryTreeNode*> stackTreeNode;
//    stackTreeNode.push(pRoot);
//
//    while(stackTreeNode.size() > 0)
//    {
//        BinaryTreeNode *pNode = stackTreeNode.top();
//        stackTreeNode.pop();
//
//        BinaryTreeNode *pTemp = pNode->m_pLeft;
//        pNode->m_pLeft = pNode->m_pRight;
//        pNode->m_pRight = pTemp;
//
//        if(pNode->m_pLeft)
//            stackTreeNode.push(pNode->m_pLeft);
//
//        if(pNode->m_pRight)
//            stackTreeNode.push(pNode->m_pRight);
//    }
//}

void MirrorIteratively(BinaryTreeNode* p)
{
	BinaryTreeNode *s = p;
	if(p == NULL)
		return ;
	queue<BinaryTreeNode *> qTree;
	qTree.push(p);
	while(qTree.size() > 0)
	{
		p = qTree.front();
		qTree.pop();
		BinaryTreeNode *t = p->m_pLeft;
		p->m_pLeft = p->m_pRight;
		p->m_pRight = t;
		if(p->m_pLeft)
			qTree.push(p->m_pLeft);
		if(p->m_pRight)
			qTree.push(p->m_pRight);
	}
	
} 

// ====================测试代码====================
// 测试完全二叉树：除了叶子节点，其他节点都有两个子节点
//            8
//        6      10
//       5 7    9  11
void Test1()
{
    printf("=====Test1 starts:=====\n");
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

    PrintTree(pNode8);

    printf("=====Test1: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test1: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);

    DestroyTree(pNode8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个左子结点
//            8
//          7   
//        6 
//      5
//    4
void Test2()
{
    printf("=====Test2 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode8, pNode7, NULL);
    ConnectTreeNodes(pNode7, pNode6, NULL);
    ConnectTreeNodes(pNode6, pNode5, NULL);
    ConnectTreeNodes(pNode5, pNode4, NULL);

    PrintTree(pNode8);

    printf("=====Test2: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test2: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);

    DestroyTree(pNode8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个右子结点
//            8
//             7   
//              6 
//               5
//                4
void Test3()
{
    printf("=====Test3 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode8, NULL, pNode7);
    ConnectTreeNodes(pNode7, NULL, pNode6);
    ConnectTreeNodes(pNode6, NULL, pNode5);
    ConnectTreeNodes(pNode5, NULL, pNode4);

    PrintTree(pNode8);

    printf("=====Test3: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test3: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);

    DestroyTree(pNode8);
}

// 测试空二叉树：根结点为空指针
void Test4()
{
    printf("=====Test4 starts:=====\n");
    BinaryTreeNode* pNode = NULL;

    PrintTree(pNode);

    printf("=====Test4: MirrorRecursively=====\n");
    MirrorRecursively(pNode);
    PrintTree(pNode);

    printf("=====Test4: MirrorIteratively=====\n");
    MirrorIteratively(pNode);
    PrintTree(pNode);
}

// 测试只有一个结点的二叉树
void Test5()
{
    printf("=====Test5 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);

    PrintTree(pNode8);

    printf("=====Test4: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test4: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

































