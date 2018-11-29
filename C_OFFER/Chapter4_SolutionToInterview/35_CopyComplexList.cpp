// 面试题35：复杂链表的复制
// 题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复
// 制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个
// 结点外，还有一个m_pSibling 指向链表中的任意结点或者nullptr。

#include <cstdio>
#include "Utilities/ComplexList.cpp"
/** 【面试思路之将问题分解】 
(1) 有问题自身的问题，本链表含有两个节点，同下一题都是先解决一链 
(2) 不难发现思路入口，next指针好连接但是nextsibiling还没有生成啊，先建立单链表得到问题解对象，然后细化到问题的解 
(3) “复制”总是类似暴力搜索般的好想好用 
*/

void CloneNodes(ComplexListNode* pHead);
void ConnectSiblingNodes(ComplexListNode* pHead);
ComplexListNode* ReconnectNodes(ComplexListNode* pHead);

void CloneNodes(ComplexListNode* h) 
{
	if(h == NULL)
		return ;
	//忽略sibiling如果仅是单链表的复制呢。但还希望保持与待复制节点的对应关系因还有一个指针要建立
	ComplexListNode* o = h;
	while(o != NULL)
	{
		ComplexListNode* c = new ComplexListNode();
		//值复制，添加节点之链表修改，未处理置空
		c->m_nValue = o->m_nValue;
		c->m_pNext = o->m_pNext;
		o->m_pNext = c;
		c->m_pSibling = NULL; 
		o = c->m_pNext;//迭代前进 
	} 
}

void ConnectSiblingNodes(ComplexListNode* h)
{
	//原sibiling没动，现进行一对一复制到copy链上的sibiling
	ComplexListNode* o = h;
	while(o != NULL)
	{
		//copy链通过origin链的next完美移动
		ComplexListNode* c = o->m_pNext;
		if(o->m_pSibling != NULL) 
			c->m_pSibling = o->m_pSibling->m_pNext;//显然存在null风险 
		o = c->m_pNext; //从c取下一个才是origin上真正的下个节点 
	}
}

ComplexListNode* ReconnectNodes(ComplexListNode* h)
{
	//不关sibiling事儿，只是将逻辑上属于copy的节点从物理上的总链上删除
	ComplexListNode* o =  h;
	while(o != NULL)
	{
		ComplexListNode* c = o->m_pNext;
		if(c->m_pNext != NULL)
			o->m_pNext = c->m_pNext;//显然这步又无法保证，加入保证约束后则出现分支：满足怎样？不满足怎样？
		else
		{
			o->m_pNext = NULL;
			break; 
		} 
		c->m_pNext = o->m_pNext->m_pNext;//前面已经可以保证o->m_pNext不空 
		o = o->m_pNext;//迭代移动 
		//在此清楚一点：next指针若空是结束标志，不同于sibiling的乱指
		//而完美双节点链表中copy结尾则origin也结尾 
	} 
	return o;//由于指针值传递所以需要返回值？ 
}
ComplexListNode* Clone(ComplexListNode* pHead)
{
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}

// ====================测试代码====================
void Test(const char* testName, ComplexListNode* pHead)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    printf("The original list is:\n");
    PrintList(pHead);

    ComplexListNode* pClonedHead = Clone(pHead);

    printf("The cloned list is:\n");
    PrintList(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, NULL);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test1", pNode1);
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, NULL);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, pNode3);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test2", pNode1);
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, NULL);
    BuildNodes(pNode2, pNode3, pNode4);
    BuildNodes(pNode3, pNode4, NULL);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test3", pNode1);
}

// 只有一个结点
void Test4()
{
    ComplexListNode* pNode1 = CreateNode(1);
    BuildNodes(pNode1, NULL, pNode1);

    Test("Test4", pNode1);
}

// 鲁棒性测试
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


























