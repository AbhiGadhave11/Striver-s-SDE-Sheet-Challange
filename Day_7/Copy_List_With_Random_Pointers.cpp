/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    private :
    void CopyList(Node *head)
    {
        Node *curr = head;
        while(curr != NULL)
        {
            Node *node = new Node(curr->val);
            Node *forward = curr->next;
            curr->next = node;
            node->next = forward;
            curr = forward;
        }
    }
    void CopyRandomPointers(Node *head)
    {
        Node *curr = head;
        while(curr != NULL)
        {
            if(curr->random != NULL)
            {
                Node *random = curr->random;
                curr->next->random = random->next;
            }
            curr = curr->next->next;
        }
    }
    Node *ExtractCopy(Node *head)
    {
        Node *dummy = new Node(-1);
        Node *prev = dummy;
        Node *curr = head;
        while(curr != NULL)
        {
            prev->next = curr->next;
            curr->next = curr->next->next;
            curr = curr->next;
            prev = prev->next;
        }
        return dummy->next;
    }
public:
    Node* copyRandomList(Node* head) 
    {
        CopyList(head);
        CopyRandomPointers(head);
        return ExtractCopy(head);
        
    }
};
