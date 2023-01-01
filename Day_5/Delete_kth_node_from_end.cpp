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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    if(head == NULL || K==0)
        return head;
    LinkedListNode<int>* dummy = new LinkedListNode<int>(-1);
    dummy->next = head;
    LinkedListNode<int>* fast = dummy;
    LinkedListNode<int>* slow = dummy;
    int n = K; 
    for(int i=1;i<=K;i++){
        fast = fast->next;
    }
    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    LinkedListNode<int>* target = slow->next;
    slow->next = slow->next->next;
    target->next = NULL;
    delete(target);
    return dummy->next;
}
