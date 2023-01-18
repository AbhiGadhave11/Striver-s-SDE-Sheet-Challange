/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    private :
    ListNode *th = NULL;
    ListNode *tt = NULL;
    int length(ListNode *head)
    {
        ListNode *temp = head;
        int cnt  = 0;
        while(temp != NULL)
        {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
    void AddFirst(ListNode *node)
    {
        if(th == NULL && tt == NULL)
        {
            th = node;
            tt = node;
        }
        else
        {
            node->next = th;
            th = node;
        }
    }
public:
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head == NULL || head->next == NULL || k <= 1)
            return head;
        int len = length(head);
        ListNode *oh = NULL;
        ListNode *ot = NULL;
        ListNode *curr = head;
        while(len>=k)
        {
            int tempk = k;
            while(tempk-- != 0)
            {
                ListNode *forward = curr->next;
                curr->next = NULL;
                AddFirst(curr);
                curr = forward;
            }
            if(oh == NULL && ot == NULL)
            {
                oh = th;
                ot = tt;
            }
            else
            {
                ot->next = th;
                ot = tt;
            }
            len = len - k;
            tt = NULL;
            th = NULL;
                
        }
        if(curr != NULL)
        {
            ot->next = curr;
        }
        return oh;
        
    }
};
