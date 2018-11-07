#include<cstdio>
struct Node{
	int m_nValue;
	struct Node *m_pLeft;
	struct Node *m_pRight;
	struct Node *m_pParent;
}; 
Node *GetNext(Node *p)//��p���¸� 
{
	Node *next = NULL;
	if(p == NULL)
		return NULL;
	if(p->m_pRight != NULL)
	{
		if(p->m_pRight->m_pLeft == NULL)
			next = p->m_pRight;
		else
		{
			//Ѱ��p������������߽ڵ�
			Node *q = p->m_pRight;
			while(q->m_pLeft != NULL)
				q = q->m_pLeft;
			next = q; 
		}	
	}	
	else
	{
		//����ΪL,��˵��LMR�����¸���M,��ʵ����Ҳ����R�����
		//��������M,����Ȼ������R����if���������Ϊ�ݹ�����µ�R,��ֱ�ӵ��Һ��Ӻͼ�ӵ��Һ��ӣ�
		//������R��ʵ��Ĭ����ΪҶ�Ӽ����R,��ͬ��û���Һ��ӣ�
		//����ΪL��R��������Ӧ��ϣ���ڴ����游�Ǳ��˵����ӣ�����R������������R��һֱ���游�ҵ�����û��Ϊ���˵�����
		Node *cur = p;
		Node *par = p->m_pParent;
		//����˼������һ���������Ȳ��ż��޸ģ�������������Ҳ���и����ԵĴ����������޸ģ��������Ƿ��߼�����һ�����һ��Ƭ����
		//�˴���Ҫ�ҵ���Ϊ���ӵĸ��ڵ㣬��whileѭ����Ӧ���ǣ���Ϊ���ӡ� 
		while(par!=NULL && par->m_pLeft!=cur) 
		{
			cur = par;
			par = par->m_pParent;
		}
		if(par == NULL)
			next = NULL;
		else
			next = par;
	}
	return next;
}
Node* CreateBinaryTreeNode(int value)
{
    Node* pNode = new Node();
    pNode->m_nValue = value;
    pNode->m_pLeft = NULL;
    pNode->m_pRight = NULL;
    pNode->m_pParent = NULL;

    return pNode;
}

void ConnectTreeNodes(Node* pParent, Node* pLeft, Node* pRight)
{
    if(pParent != NULL)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;

        if(pLeft != NULL)
            pLeft->m_pParent = pParent;
        if(pRight != NULL)
            pRight->m_pParent = pParent;
    }
}

void PrintTreeNode(Node* pNode)
{
    if(pNode != NULL)
    {
        printf("value of this node is: %d\n", pNode->m_nValue);

        if(pNode->m_pLeft != NULL)
            printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
        else
            printf("left child is null.\n");

        if(pNode->m_pRight != NULL)
            printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
        else
            printf("right child is null.\n");
    }
    else
    {
        printf("this node is null.\n");
    }

    printf("\n");
}

void PrintTree(Node* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != NULL)
    {
        if(pRoot->m_pLeft != NULL)
            PrintTree(pRoot->m_pLeft);

        if(pRoot->m_pRight != NULL)
            PrintTree(pRoot->m_pRight);
    }
}

void DestroyTree(Node* pRoot)
{
    if(pRoot != NULL)
    {
       Node* pLeft = pRoot->m_pLeft;
       Node* pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = NULL;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

void Test(const char* testName, Node* pNode, Node* expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    Node* pNext = GetNext(pNode);
    if(pNext == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void Test1_7()
{
    Node* pNode8 = CreateBinaryTreeNode(8);
    Node* pNode6 = CreateBinaryTreeNode(6);
    Node* pNode10 = CreateBinaryTreeNode(10);
    Node* pNode5 = CreateBinaryTreeNode(5);
    Node* pNode7 = CreateBinaryTreeNode(7);
    Node* pNode9 = CreateBinaryTreeNode(9);
    Node* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    Test("Test1", pNode8, pNode9);
    Test("Test2", pNode6, pNode7);
    Test("Test3", pNode10, pNode11);
    Test("Test4", pNode5, pNode6);
    Test("Test5", pNode7, pNode8);
    Test("Test6", pNode9, pNode10);
    Test("Test7", pNode11, NULL);

    DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test8_11()
{
    Node* pNode5 = CreateBinaryTreeNode(5);
    Node* pNode4 = CreateBinaryTreeNode(4);
    Node* pNode3 = CreateBinaryTreeNode(3);
    Node* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode3, NULL);
    ConnectTreeNodes(pNode3, pNode2, NULL);

    Test("Test8", pNode5, NULL);
    Test("Test9", pNode4, pNode5);
    Test("Test10", pNode3, pNode4);
    Test("Test11", pNode2, pNode3);

    DestroyTree(pNode5);
}

//        2
//         3
//          4
//           5
void Test12_15()
{
    Node* pNode2 = CreateBinaryTreeNode(2);
    Node* pNode3 = CreateBinaryTreeNode(3);
    Node* pNode4 = CreateBinaryTreeNode(4);
    Node* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode2, NULL, pNode3);
    ConnectTreeNodes(pNode3, NULL, pNode4);
    ConnectTreeNodes(pNode4, NULL, pNode5);

    Test("Test12", pNode5, NULL);
    Test("Test13", pNode4, pNode5);
    Test("Test14", pNode3, pNode4);
    Test("Test15", pNode2, pNode3);

    DestroyTree(pNode2);
}

void Test16()
{
    Node* pNode5 = CreateBinaryTreeNode(5);

    Test("Test16", pNode5, NULL);

    DestroyTree(pNode5);
}

int main(int argc, char* argv[])
{
    Test1_7();
    Test8_11();
    Test12_15();
    Test16();
}
//ע�⣺������֤��ԭ��ͬ�����ɣ����ڼ�����Դ��� 
