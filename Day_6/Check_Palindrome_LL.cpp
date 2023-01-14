#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int> *FindMiddle(LinkedListNode<int> *head)
{
    if(head==NULL||head->next==NULL || head->next->next == NULL)
        return head;
    LinkedListNode<int> *slow = head;
    LinkedListNode<int>*fast = head;
    while(fast!= NULL && fast->next!= NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        
    }
    return slow;
}
LinkedListNode<int> *Reverse(LinkedListNode<int> *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    LinkedListNode<int> *current = head;
    LinkedListNode<int> *magacha = NULL;
    LinkedListNode<int> *pudhacha = NULL;
    while(current != NULL)
    {
        pudhacha = current->next;
        current->next = magacha;
        magacha = current;
        current = pudhacha;
    }
    return magacha;
        
}
bool compare(LinkedListNode<int> *h1,LinkedListNode<int> *h2)
{
    if(h2==NULL )
        {
            if(h1->data == h1->next->data)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int flag = 1;
        LinkedListNode<int>  *temp = h1;
        LinkedListNode<int>  *temp1 = h2;
        int i = 0;
        while(temp!=NULL && temp1!=NULL)
        {
            
            if(temp->data != temp1->data)
            {
                flag = 0;
                i = 1;
                break;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
        return flag;
        
        
}
bool isPalindrome(LinkedListNode<int> *head) {
    if(head == NULL || head->next == NULL)
        return true;
    LinkedListNode<int> *mid = FindMiddle(head);
    LinkedListNode<int> *nHead = mid->next;
    mid->next = NULL;
    nHead = Reverse(nHead);
    LinkedListNode<int> *temp = head;
    LinkedListNode<int> *temp1 = nHead;
    bool flag = compare(head,nHead);
    
    return flag;

}
