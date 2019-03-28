/*
输入一个链表，反转链表后，输出新链表的表头。
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

//class Solution {
//public:
//    ListNode* ReverseList(ListNode* pHead) {
//		if(pHead == NULL)
//			return NULL;
//		//尝试递归的思路，失败！
//		//正常使用迭代
//		 ListNode h;
//		 ListNode* originP = pHead;
//		 ListNode* newP = pHead; 
//		 bool flag = false;
//		 while(originP != NULL)
//		 {
//		 	newP = originP;
//		 	originP = originP->next;
//		 	//首次进入 
//		 	if(flag == false)
//			{
//				h->next = newP; 
//				newP->next = NULL;
//				flag = true;
//				continue;
//			}
//			//将新下来的节点插入到h开头的链表 
//		 	newP->next = h->next;
//		 	h->next = newP;
//		 }
//		 return h; 
//    }
//};

//学习递归思路
class Solution{
public:
	ListNode *ReverseList(ListNode* head){
		if (head == NULL || head->next == NULL)
			return head;
		auto nxt = head->next;
		head->next = NULL;
		auto new_head = ReverseList(nxt);
		nxt->next = head;
		return new_head;
	}
}; 
 
