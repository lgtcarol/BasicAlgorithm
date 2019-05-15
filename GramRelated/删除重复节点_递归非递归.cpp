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
     /**
    循环做法：链表问题请先明确你需要几个指针，各指针的功能及变化情况！
    切忌糊涂，比如pre的next都不修改，这是个链表操作常规本质啊
    */
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        if(pHead->next == NULL)
            return pHead;
        ListNode *newH = new ListNode(0); 
        ListNode *pre = newH;
        ListNode *cur = pHead;
        bool flag = false;
        while(cur!= NULL)
        {
           
            while(cur->next && cur->val == cur->next->val)
            {
                flag = true;//标记当前节点是否重复
                cur = cur->next;
            }
            if(flag){
                pre->next = cur->next;   //出来时的cur是个重复节点
                cur = cur->next;
                flag = false;
            }
            else    
            {
                pre->next = cur;
                pre = cur;
                cur = cur->next;
            }     
        }
        return newH->next;
    }

};
