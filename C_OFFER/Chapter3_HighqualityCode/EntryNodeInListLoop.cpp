#include <cstdio>
#include "Utilities/List.cpp"
ListNode* MeetingNode(ListNode* pHead)
{
	/*难点：判断链表有环快慢指针相距多少*/
	ListNode *pSlow = NULL, *pQuick = NULL;
	if(pHead == NULL)
		return NULL;
	pSlow = pHead->m_pNext; 
	if(pSlow == NULL)//单个节点且独自为成环
		return NULL;
	pQuick = pSlow->m_pNext;

	while(pQuick!=NULL && pSlow!=NULL)
	{
		if(pSlow == pQuick)
			return pSlow;
		pSlow = pSlow->m_pNext;
		pQuick = pQuick->m_pNext;
		//???判断为空是pQuick会先到末尾，但如此则pQuick比pSlow慢两个为何 
		if(pQuick != NULL)
			pQuick = pQuick->m_pNext;	 
	}
	return NULL; 
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	/*突破：理出思路按步骤很重要，并非一次性就要处理完为达成目标所需的所有步骤
	  务必改掉：在一次遍历或检查中想分支处理掉所有情况，你要清楚为了检查你的分支完备性你势必同时举例子验证，即与目标将脱离一次思考，甚至你可能再深一层考虑完备性。
	            这不就是简单问题复杂化吗？因为你思维乱了！
	  要求：当思考中分支情况至多达到简单的三分支就考虑按步骤捋思路! 
	*/
	
	//step1:该链表存在环 
	ListNode *meetNode = MeetingNode(pHead);
	if(meetNode == NULL)
		return NULL;
	//step2:找到该环长度
	ListNode *testP = meetNode->m_pNext;
	int loopLen = 1;
	 while(testP != meetNode)
	 {
	 	testP = testP->m_pNext;
	 	loopLen ++;
	 }
	 //step3：设置相间loopLen的快慢指针
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






















