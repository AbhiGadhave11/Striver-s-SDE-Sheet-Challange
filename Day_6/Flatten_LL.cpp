#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/

Node *MergeTwo(Node *a,Node *b)
{
    Node *dummy = new Node(-1);
    Node * temp = dummy;
    while(a!= NULL && b!= NULL)
    {
        if(a->data < b->data)
        {
            temp->child = a;
            a = a->child;
            temp = temp->child;
        }
        else
        {
            temp->child = b;
            b = b->child;
            temp = temp->child;
        }
    }
    if(a != NULL)
        temp->child = a;
    else
        temp->child = b;
    return dummy->child;
}

Node* flattenLinkedList(Node* root) 
{
	if(root==NULL || root->next == NULL)
        return root;
    root->next = flattenLinkedList(root->next);
    root = MergeTwo(root,root->next);
    return root;
}
