/*
����һ��������ת��������������ı�ͷ��
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
//		//���Եݹ��˼·��ʧ�ܣ�
//		//����ʹ�õ���
//		 ListNode h;
//		 ListNode* originP = pHead;
//		 ListNode* newP = pHead; 
//		 bool flag = false;
//		 while(originP != NULL)
//		 {
//		 	newP = originP;
//		 	originP = originP->next;
//		 	//�״ν��� 
//		 	if(flag == false)
//			{
//				h->next = newP; 
//				newP->next = NULL;
//				flag = true;
//				continue;
//			}
//			//���������Ľڵ���뵽h��ͷ������ 
//		 	newP->next = h->next;
//		 	h->next = newP;
//		 }
//		 return h; 
//    }
//};

//ѧϰ�ݹ�˼·
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
 
