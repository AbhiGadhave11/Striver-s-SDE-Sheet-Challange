class Node
{
    public:
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int key,int value)
    {
        this->key = key;
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
};
class LRUCache {
public:
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    unordered_map<int,Node*>uobj;
    int size = 0,cap = 0;
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void InsertNode(Node *node)
    {
        Node *temp = head->next;
        head->next = node;
        node->prev = head;
        temp->prev = node;
        node->next = temp;
    }
    void DeleteNode(Node *node)
    {
        Node *delprev = node->prev;
        Node *delnext = node->next;
        delnext->prev = delprev;
        delprev->next = delnext;
        node->next = node->prev= NULL;
    }
    
    int get(int key) 
    {
        if(uobj.find(key) != uobj.end())
        {
            Node *res = uobj[key];
            int val =res->value;
            Node *newNode = new Node(key,res->value);
            DeleteNode(res);
            uobj.erase(key);
            InsertNode(newNode);
            uobj[key] = head->next;
            
            return val;
        }
        else
            return -1;
        
    }
    
    void put(int key, int value) 
    {
        if(uobj.find(key) != uobj.end())
        {
            Node *res = uobj[key];
            int val =res->value;
            Node *newNode = new Node(key,value);
            DeleteNode(res);
            uobj.erase(key);
            InsertNode(newNode);
            uobj[key] = newNode;
        
            
        }
        else if(cap>=size)
        {
            Node *res = tail->prev;
            Node *newNode = new Node(key,value);
            DeleteNode(res);
            uobj.erase(res->key);
            InsertNode(newNode);
            uobj[key] = newNode;
            
        }
        else
        {
            Node *newNode = new Node(key,value);
            InsertNode(newNode);
            uobj[key] = newNode;
            cap++;
        }
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
