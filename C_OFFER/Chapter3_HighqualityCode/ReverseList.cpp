#include <cstdio>
#include "Utilities/List.cpp"

ListNode* ReverseList(ListNode* pHead)
{
	//链表 空or单节点 返回原值 
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
	//当next为NULL时就不存在断链情况了，也就刚好结束 
	while(pNext != NULL)
	{
	    p->m_pNext = pre;
		p = pNext;
		pre = p;
		pNext = p->m_pNext;
	}
	return p;
}
/* 参考答案：没有区分 空，单节点，两点，其他 
   关键思路：简单模拟下转置指针过程便发现，难点是把next先保留否则断链 
ListNode* ReverseList(ListNode* pHead)
{
    ListNode* pReversedHead = NULL;
    ListNode* pNode = pHead;
    ListNode* pPrev = NULL;
    //小结：若说pnext在循环中才赋值则终止条件自然上升到pnow的角度即pNode 
    while(pNode != NULL)
    {
    	//保证不断链 
        ListNode* pNext = pNode->m_pNext;
		//其实大多数依靠此判断，因pNext在前面 
        if(pNext == NULL)
            pReversedHead = pNode;
		//完成关系逆转 
        pNode->m_pNext = pPrev;
		//指针迭代更新 
        pPrev = pNode;
        pNode = pNext;
    }

    return pReversedHead;
}

*/
// ====================测试代码====================
ListNode* Test(ListNode* pHead)
{
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode* pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// 输入的链表有多个结点
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

// 输入的链表只有一个结点
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入空链表
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







