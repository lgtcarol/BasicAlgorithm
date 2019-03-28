
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null��
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
		//1. �һ� 
		while(s != NULL && f != NULL && s != f)
		{
			s = s->next;
			f = f->next->next;
		}
		if(s == NULL || f == NULL)
			return NULL;   //�����޻�
		//2. ���нڵ���Ŀ
		int cnt = 0;         // ���л��������ȵĵ��ڻ��� 
		do
		{
			f = f->next->next;
			s = s->next;
			cnt++;
		}while(s != f); 	//�������ٴ�����ʱ�պ����������� 
		//3. �������λ��
		f = pHead;
		s = pHead;
		while(cnt > 0)
		{
			f = f->next;	
			cnt--;
		}

		while(f != s)         //�ٴ������ĵط������ 
		{
			f = f->next;
			s = s->next;
		}
		 result = s;
		 return result;
    }
};
