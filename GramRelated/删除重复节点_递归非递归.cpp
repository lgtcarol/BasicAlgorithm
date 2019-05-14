class Solution {
public:
    //递归思路：以一个节点作为处理单位，若为重复节点不断next直到找到非重复节点，从而作为新pHead;
    //若不为重复节点则本节点的next=递归调用本身的next；
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead==NULL)
            return NULL;
        if(pHead->next == NULL)
            return pHead;
        ListNode *current;
        if(pHead->next->val == pHead->val)
        {
            current = pHead->next->next;
            while(current != NULL && current->val==pHead->val)
                current = current->next;
            return deleteDuplication(current);
        }  
        else
        {
            current = pHead->next;
            pHead->next = deleteDuplication(current);
            return pHead;
        }
    }

};
