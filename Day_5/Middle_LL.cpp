#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

       class Node 
        { 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/

Node *findMiddle(Node *head) 
{
    Node *fast = head;
    Node *slow = head;
    while(fast != NULL && fast->next!= NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
    // Write your code here
}
