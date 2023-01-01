#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* l1, Node<int>* l2)
{
    Node<int>* dummy = new Node<int>(-1);
    Node<int>*it = dummy;
    while(l1 != NULL && l2!= NULL)
    {
        if(l1->data < l2->data)
        {
             
            it->next = l1;
            it = it->next;
            l1 = l1->next;
        }
        else
        {
            it->next = l2;
            it = it->next;
            l2 = l2->next;
        }
    }
    while(l1 != NULL)
    {
        it->next = l1;
         it = it->next;
        l1 = l1->next;
    }
    while(l2 != NULL){
        it->next = l2;
         it = it->next;
        l2 = l2->next;
    }
    return dummy->next;
}
