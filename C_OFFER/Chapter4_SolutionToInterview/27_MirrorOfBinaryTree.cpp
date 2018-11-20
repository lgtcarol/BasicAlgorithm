#include <cstdio>
#include "Utilities\BinaryTree.cpp"
#include <stack>
#include <queue>
//QUESTION: ��Ȼ�Ƚ���������Ϊ�λ�Ҫ��ջ��ֱ�ӽ��в�α�������ڵ���о��񼴿ɰ����ӽ��������queue��stackû���� 
using namespace std;
/**
(1) ���ṹ�Ļ����������Ǳ����������ݹ飬�ǵݹ����������ص㡣�Ӷ������������ҽǶȲ���һ�� 
(2) ���ֵݹ�+ָ��Ӧ����ͼ���߼���ֱ�۸о����ܴ��磺���������ڵ㣬����ֱ�۵�ֻ�������ڵ㽻�����������ô������������˼������Ϊ�Ǵ����⸴��\\
    ʵ�ʻ�ͼ�ͷ����ڽ������������ڵ�ʱ��ʵ��������֧�Ľ�����
(3) ���ڷ���ֵ���жϲ�����֮���硣�ڿ��ǵ������Ĳ����Լ��ݹ���������̾ͷ��֣��ں����ڲ��ѽ�������Ĳ������������ֵ�� 
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

// ====================���Դ���====================
// ������ȫ������������Ҷ�ӽڵ㣬�����ڵ㶼�������ӽڵ�
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

// ���Զ���������Ҷ�ӽ��֮�⣬���ҵĽ�㶼����ֻ��һ�����ӽ��
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

// ���Զ���������Ҷ�ӽ��֮�⣬���ҵĽ�㶼����ֻ��һ�����ӽ��
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

// ���Կն������������Ϊ��ָ��
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

// ����ֻ��һ�����Ķ�����
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

































