#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    queue<int>q;
   public:
    Stack() {
        
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() 
    {
        return q.size();

        
    }

    bool isEmpty() {
        return (q.size() == 0);
    }

    void push(int x) 
    {
        q.push(x);
        int _size = q.size();
        for(int i=0;i<_size-1;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if(q.size() == 0)
            return -1;
        int no = q.front();
        q.pop();
        return no;
        
    }

    int top() {
        if(q.size() == 0)
            return -1;
        return q.front();
    }
};
