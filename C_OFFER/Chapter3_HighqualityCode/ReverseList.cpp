#include <cstdio>
#include "Utilities/List.cpp"

ListNode* ReverseList(ListNode* pHead)
{
	//���� ��or���ڵ� ����ԭֵ 
	if(pHead==NULL || pHead->m_pNext==NULL)
		return pHead;
	ListNode *pre = pHead;
	ListNode *p = pHead->m_pNext;
	pre->m_pNext = NULL;
	if(p->m_pNext == NULL)
	{
		p->m_pNext = pre;
		return p;
	}
	ListNode *pNext = p->m_pNext;
	//��nextΪNULLʱ�Ͳ����ڶ�������ˣ�Ҳ�͸պý��� 
	while(pNext != NULL)
	{
	    p->m_pNext = pre;
		p = pNext;
		pre = p;
		pNext = p->m_pNext;
	}
	return p;
}
/* �ο��𰸣�û������ �գ����ڵ㣬���㣬���� 
   �ؼ�˼·����ģ����ת��ָ����̱㷢�֣��ѵ��ǰ�next�ȱ���������� 
ListNode* ReverseList(ListNode* pHead)
{
    ListNode* pReversedHead = NULL;
    ListNode* pNode = pHead;
    ListNode* pPrev = NULL;
    //С�᣺��˵pnext��ѭ���вŸ�ֵ����ֹ������Ȼ������pnow�ĽǶȼ�pNode 
    while(pNode != NULL)
    {
    	//��֤������ 
        ListNode* pNext = pNode->m_pNext;
		//��ʵ������������жϣ���pNext��ǰ�� 
        if(pNext == NULL)
            pReversedHead = pNode;
		//��ɹ�ϵ��ת 
        pNode->m_pNext = pPrev;
		//ָ��������� 
        pPrev = pNode;
        pNode = pNext;
    }

    return pReversedHead;
}

*/
// ====================���Դ���====================
ListNode* Test(ListNode* pHead)
{
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode* pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// ����������ж�����
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// ���������ֻ��һ�����
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// ���������
void Test3()
{
    Test(NULL);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}







