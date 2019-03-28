
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
		if(pHead == NULL)
			return NULL; 
		ListNode* s = pHead;
		ListNode* f = pHead->next;
		ListNode* result = NULL;
		//1. 找环 
		while(s != NULL && f != NULL && s != f)
		{
			s = s->next;
			f = f->next->next;
		}
		if(s == NULL || f == NULL)
			return NULL;   //表中无环
		//2. 环中节点数目
		int cnt = 0;         // 若有环则二者相等的点在环内 
		do
		{
			f = f->next->next;
			s = s->next;
			cnt++;
		}while(s != f); 	//当二者再次相遇时刚好行走链长步 
		//3. 环的入口位置
		f = pHead;
		s = pHead;
		while(cnt > 0)
		{
			f = f->next;	
			cnt--;
		}

		while(f != s)         //再次相遇的地方是入口 
		{
			f = f->next;
			s = s->next;
		}
		 result = s;
		 return result;
    }
};
