#include <cstdio>
#include "Utilities\BinaryTree.cpp"

/** 
NOTE: ��Ϊ�ݹ�ṹ���ԣ����ӱ㲻�����������ϵ����� ���������������Ǿ��嵽ָ���޸�ʱ��Ȼ�����������һ���ڵ� 

(1) �������Ľṹ����ȫ���϶�̬�滮���ӽṹ��Ӧ�ô����ֺ�۵ĽǶȳ��������� �� ���ӡ������һ��󣬸���������ȫͬ���Ľⷨ
(2) �ȶ� ������ �� ˫���������������ڵ㣬���� ����=ǰ�������� ����=��̡�
	����õ� ����ǰ��ڵ� ���ĺ���ڵ㣨��Ҫǰ����
(3) ��������õ� ����ǰ������Ȼ�� 
(4) �� �� �Ҵ����Ƚ������˫���ٽ�������˫�� 
(5) ���⣺��Ϊ�ݹ��д��ݵĸ���������ÿ���ݹ鵥Ԫ�����һ���ڵ㣬��ô��������������з��ص�Ҳ��˫�����β�ڵ㣬��Ҫ�����ҵ�����ʼ�ڵ㡣 
*/
void ConvertNode(BinaryTreeNode *r, BinaryTreeNode **pL);
BinaryTreeNode *Convert(BinaryTreeNode *r)
{
	BinaryTreeNode *pL = NULL;
	ConvertNode(r, &pL);
	BinaryTreeNode *pH = pL;
	while(pH != NULL && pH->m_pLeft!=NULL) 
		pH = pH->m_pLeft;
	return pH;
}
void ConvertNode(BinaryTreeNode *r, BinaryTreeNode **pL)
{
	if(r == NULL)
		return ;
	BinaryTreeNode *pC = r;
	if(pC->m_pLeft != NULL)
		ConvertNode(pC->m_pLeft, pL);
	pC->m_pLeft = *pL;
	if((*pL) != NULL)
		(*pL)->m_pRight = pC;
	*pL = pC;
	if(pC->m_pRight != NULL)
		ConvertNode(pC->m_pRight, pL); 
}

// ====================���Դ���====================
void PrintDoubleLinkedList(BinaryTreeNode* pHeadOfList)
{
    BinaryTreeNode* pNode = pHeadOfList;

    printf("The nodes from left to right are:\n");
    while(pNode != NULL)
    {
        printf("%d\t", pNode->m_nValue);

        if(pNode->m_pRight == NULL)
            break;
        pNode = pNode->m_pRight;
    }

    printf("\nThe nodes from right to left are:\n");
    while(pNode != NULL)
    {
        printf("%d\t", pNode->m_nValue);

        if(pNode->m_pLeft == NULL)
            break;
        pNode = pNode->m_pLeft;
    }

    printf("\n");
}

void DestroyList(BinaryTreeNode* pHeadOfList)
{
    BinaryTreeNode* pNode = pHeadOfList;
    while(pNode != NULL)
    {
        BinaryTreeNode* pNext = pNode->m_pRight;

        delete pNode;
        pNode = pNext;
    }
}

void Test(const char* testName, BinaryTreeNode* pRootOfTree)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    PrintTree(pRootOfTree);

    BinaryTreeNode* pHeadOfList = Convert(pRootOfTree);

    PrintDoubleLinkedList(pHeadOfList);
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);

    Test("Test1", pNode10);

    DestroyList(pNode4);
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
void Test2()
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

    Test("Test2", pNode5);

    DestroyList(pNode1);
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
void Test3()
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

    Test("Test3", pNode1);

    DestroyList(pNode1);
}

// ����ֻ��1�����
void Test4()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    Test("Test4", pNode1);

    DestroyList(pNode1);
}

// ����û�н��
void Test5()
{
    Test("Test5", NULL);
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





























































































