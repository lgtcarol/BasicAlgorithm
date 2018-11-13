#include <cstdio>
#include "Utilities/List.cpp"
ListNode* MeetingNode(ListNode* pHead)
{
	/*�ѵ㣺�ж������л�����ָ��������*/
	ListNode *pSlow = NULL, *pQuick = NULL;
	if(pHead == NULL)
		return NULL;
	pSlow = pHead->m_pNext; 
	if(pSlow == NULL)//�����ڵ��Ҷ���Ϊ�ɻ�
		return NULL;
	pQuick = pSlow->m_pNext;

	while(pQuick!=NULL && pSlow!=NULL)
	{
		if(pSlow == pQuick)
			return pSlow;
		pSlow = pSlow->m_pNext;
		pQuick = pQuick->m_pNext;
		//???�ж�Ϊ����pQuick���ȵ�ĩβ���������pQuick��pSlow������Ϊ�� 
		if(pQuick != NULL)
			pQuick = pQuick->m_pNext;	 
	}
	return NULL; 
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	/*ͻ�ƣ����˼·���������Ҫ������һ���Ծ�Ҫ������Ϊ���Ŀ����������в���
	  ��ظĵ�����һ�α������������֧����������������Ҫ���Ϊ�˼����ķ�֧�걸�����Ʊ�ͬʱ��������֤������Ŀ�꽫����һ��˼�����������������һ�㿼���걸�ԡ�
	            �ⲻ���Ǽ����⸴�ӻ�����Ϊ��˼ά���ˣ�
	  Ҫ�󣺵�˼���з�֧�������ﵽ�򵥵�����֧�Ϳ��ǰ�������˼·! 
	*/
	
	//step1:��������ڻ� 
	ListNode *meetNode = MeetingNode(pHead);
	if(meetNode == NULL)
		return NULL;
	//step2:�ҵ��û�����
	ListNode *testP = meetNode->m_pNext;
	int loopLen = 1;
	 while(testP != meetNode)
	 {
	 	testP = testP->m_pNext;
	 	loopLen ++;
	 }
	 //step3���������loopLen�Ŀ���ָ��
	 ListNode *s = pHead;
	 ListNode *q = pHead;
	 for(int i = 0; i < loopLen; i++)
	 	q = q->m_pNext;
	while(q != s)
	{
		q = q->m_pNext;
		s = s->m_pNext;	
	} 
	return s;
}
// ==================== Test Code ====================
void Test(const char* testName, ListNode* pHead, ListNode* entryNode)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    if(EntryNodeOfLoop(pHead) == entryNode)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// A list has a node, without a loop
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);

    Test("Test1", pNode1, NULL);

    DestroyList(pNode1);
}

// A list has a node, with a loop
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ConnectListNodes(pNode1, pNode1);

    Test("Test2", pNode1, pNode1);

    delete pNode1;
    pNode1 = NULL;
}

// A list has multiple nodes, with a loop 
void Test3()
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
    ConnectListNodes(pNode5, pNode3);

    Test("Test3", pNode1, pNode3);

    delete pNode1;
    pNode1 = NULL;
    delete pNode2;
    pNode2 = NULL;
    delete pNode3;
    pNode3 = NULL;
    delete pNode4;
    pNode4 = NULL;
    delete pNode5;
    pNode5 = NULL;
}

// A list has multiple nodes, with a loop 
void Test4()
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
    ConnectListNodes(pNode5, pNode1);

    Test("Test4", pNode1, pNode1);

    delete pNode1;
    pNode1 = NULL;
    delete pNode2;
    pNode2 = NULL;
    delete pNode3;
    pNode3 = NULL;
    delete pNode4;
    pNode4 = NULL;
    delete pNode5;
    pNode5 = NULL;
}

// A list has multiple nodes, with a loop 
void Test5()
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
    ConnectListNodes(pNode5, pNode5);

    Test("Test5", pNode1, pNode5);

    delete pNode1;
    pNode1 = NULL;
    delete pNode2;
    pNode2 = NULL;
    delete pNode3;
    pNode3 = NULL;
    delete pNode4;
    pNode4 = NULL;
    delete pNode5;
    pNode5 = NULL;
}

// A list has multiple nodes, without a loop 
void Test6()
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

    Test("Test6", pNode1, NULL);

    DestroyList(pNode1);
}

// Empty list
void Test7()
{
    Test("Test7", NULL, NULL);
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

    return 0;
}






















