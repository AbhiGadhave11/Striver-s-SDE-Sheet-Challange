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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int>*current = head;
    LinkedListNode<int>* magacha = NULL;
    LinkedListNode<int>*pudhacha = NULL;
    while(current != NULL)
    {
        pudhacha = current->next;
        current->next = magacha;
        magacha = current;
        current = pudhacha;
    }
    return magacha;
}
