#include <cstdio>
#include "Utilities/List.cpp"
ListNode* FindKthToTail(ListNode* head, unsigned int k) 
{
	if(head == NULL || k <= 0)
		return NULL;
	//������Ϊk-1������ָ��
	ListNode *quick = head;
	ListNode *slow = head;
	//��ָ���ߵ���k-1���ڵ㴦 ,���ݱ�ѭ���еĽ���������֪��ͨ�������������ǡ����k���ڵ�
	//��Ϊfor������ɱ�֤quick�����ٻ���һ���ڵ� 
	for(int i = 0; i < k-1; i++)
	{
		if(quick->m_pNext != NULL)
			quick = quick->m_pNext;
		else//˵������k���ڵ� 
			return NULL;
	}
	//��ָ��������ͬʱ�ƶ�֪����ָ���ߵ�����β����ǡ����ָ��ָ������k
	while(quick->m_pNext != NULL)
	{
		slow = slow->m_pNext;
		quick = quick->m_pNext;	
	} 
	return slow;
}
 // ====================���Դ���====================
// ����Ҫ�ҵĽ���������м�
void Test1()
{
    printf("=====Test1 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 4.\n");
    ListNode* pNode = FindKthToTail(pNode1, 2);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// ����Ҫ�ҵĽ���������β���
void Test2()
{
    printf("=====Test2 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 5.\n");
    ListNode* pNode = FindKthToTail(pNode1, 1);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// ����Ҫ�ҵĽ���������ͷ���
void Test3()
{
    printf("=====Test3 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 1.\n");
    ListNode* pNode = FindKthToTail(pNode1, 5);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// ���Կ�����
void Test4()
{
    printf("=====Test4 starts:=====\n");
    printf("expected result: NULL.\n");
    ListNode* pNode = FindKthToTail(NULL, 100);
    PrintListNode(pNode);
}

// ��������ĵڶ���������������Ľ������
void Test5()
{
    printf("=====Test5 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: NULL.\n");
    ListNode* pNode = FindKthToTail(pNode1, 6);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// ��������ĵڶ�������Ϊ0
void Test6()
{
    printf("=====Test6 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: NULL.\n");
    ListNode* pNode = FindKthToTail(pNode1, 0);
    PrintListNode(pNode);

    DestroyList(pNode1);
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
/*
Note: ������һ�α���֮����ָ������˼· 
**/

