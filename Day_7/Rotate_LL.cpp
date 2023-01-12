#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/********************************

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

********************************/


Node *rotate(Node *head, int k) 
{
    if(head == NULL || k == 0 || head->next == NULL)
        return head;
    int len = 0;
    Node *temp = head;
    while(temp->next != NULL)
    {
        len++;
        temp = temp->next;
    }
    len++;
    
    if(len == k)
        return head;
    temp->next = head;
    k = k % len;
    k = len-k;
    temp = head;
    while(k--  != 1)
    {
        temp = temp->next;
        
    }
    head = temp->next;
    temp->next = NULL;
    return head;
    
    
}
