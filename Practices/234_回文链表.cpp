/*
时间O(n)
空间O(1)
attention:在自己有条件的情况下倾向于使用带头节点的链表。翻转时原链表用两个指针协作
0到<len, 经历len次
**/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next==NULL) //空链表或者单个节点视作循环
            return true;
        int len = 0;
        ListNode *t = head;
        while(t != NULL)
        {
            len++;
            t = t->next;
        }
        int mid; //记录局部翻转的起点
        if(len%2) //奇数
            mid = len/2+1;
        else
            mid = len/2;
        t = head;
        int cnt = 0;
        while(cnt < mid && t!= NULL )
        {
            cnt++;
            t = t->next;
        }//跳出循环时t指向翻转起点,显然t不会空
        ListNode *newhead = new ListNode(0);//让t依旧在原链表滑动
        newhead->next = NULL;
        //tnext = t->next;
        while(t != NULL)
        {
            ListNode *tnext = t->next; //原链就是有个指针保持不断即可
            t->next = newhead->next; //新链即完成头插入操作
            newhead->next = t;
            t = tnext;
        }
        ListNode *p = newhead->next;
        while(p != NULL)
        {
            if(p->val != head->val)
                return false;
            p = p->next;
            head = head->next;
        }
        return true;
    }
};
