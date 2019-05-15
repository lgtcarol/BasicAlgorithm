class Solution {
public:
    /**
    递归实现：处理单元是将pHead和pHead->next实现逆置，以pHead->next作为递归起点。
            出口为：NULL或单节点
            返回值为:递归结果（拿两个节点试一试就可get到合理处）
    */
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL || pHead->next==NULL)
            return pHead;
        ListNode *nxt = pHead->next;
        pHead->next = NULL; //当前节点作为结尾，尾部置NULL
        nxt->next = pHead; //当前节点的next指向当前节点
        ListNode *new_head = ReverseList(nxt); //当最后一个节点开始返回时，整个链表逐次返回，且最后一个节点成为最终的头节点
        return new_head;
    }
    /**
    循环实现：用cur还是cur->next作为循环终止的小技巧
    */
    //循环一：
     ListNode* ReverseList(ListNode* pHead) 
     {
        if(pHead==NULL || pHead->next==NULL)
            return pHead;
        ListNode *head = new ListNode(-1);
        ListNode *pre = pHead;
        while(pHead->next != NULL) //最后一个节点先不考虑
        {
            pre = pHead; //待插入节点
            pHead = pHead->next;//保持链表前进方向
            //头插入操作
            pre->next = head->next;
            head->next = pre;
        }
            pHead->next = head->next;
            head->next = pHead;
            return head->next;//返回真正的头节点
    }
    //循环二
     ListNode* ReverseList(ListNode* pHead)
     {
        if(pHead==NULL || pHead->next==NULL)
            return pHead;
        ListNode *head = new ListNode(-1);
        ListNode *pre = pHead;
        while(pHead != NULL) //把唯一影响的节点单独用if进行隔离处理,即Pre指向最后一个节点时，pHead不再next
        {
            pre = pHead; //待插入节点
            if(pHead)
                pHead = pHead->next;//保持链表前进方向
            //头插入操作
            pre->next = head->next;
            head->next = pre;
        }
           // pHead->next = head->next;
            //head->next = pHead;
            return head->next;//返回真正的头节点
    }
};
