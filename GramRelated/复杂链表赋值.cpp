/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        RandomListNode *cur = pHead;
        //step1:创建节点
        while(cur != NULL)
        {
             RandomListNode* node = new RandomListNode(0);
             node->label = cur->label;
             //将复制的节点放到原节点的后边
             node->next = cur->next;
             cur->next = node;
             cur = node->next;
        }
        //step2:赋值random域
        cur = pHead;
        RandomListNode* node;
        while(cur != NULL)
        {
            node = cur->next;
            if(cur->random != NULL)
                node->random = cur->random->next;
            cur = node->next;
        }
        //step3:赋值next域，同时相当于剥离
        cur = pHead;
        RandomListNode *head = cur->next;
        cur->next = head->next; //相当于删除新链表中节点
        RandomListNode *tmp = head;//在新链表上进行移动添加节点
        cur = cur->next;
        while(cur != NULL)
        {
            tmp->next = cur->next; //Debug:赋值next域是赋值，指针该往后移动要往后移动，思路要清楚！
            tmp = tmp->next; 
            cur->next = tmp->next;
            cur = cur->next;
        }
        return head;
    }
};
