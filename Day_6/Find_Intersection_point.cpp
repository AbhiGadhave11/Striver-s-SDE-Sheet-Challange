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

int findIntersection(Node *HeadA, Node *HeadB)
{
    Node *a = HeadA;
    Node *b = HeadB;
    while(a != b){
        if(a!= NULL)
            a = a->next;
        else
            a = HeadB;
        if(b!= NULL)
            b = b->next;
        else 
            b = HeadA;
    }
    if(a==NULL )
        return -1;
    return a->data;
}
