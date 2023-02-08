#include<bits/stdc++.h>>
class Queue {
    // Define the data members(if any) here.
    private:
    stack<int>input;
    stack<int>output;
    public:

    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        input.push(val);
    }

    int deQueue() {
        if(input.size()==0 && output.size() == 0)
            return -1;
        if(output.size() != 0)
        {
            int no = output.top();
            output.pop();
            return no;
        }
        else{
            while(input.size() != 0)
            {
                output.push(input.top());
                input.pop();
            }
            int no = output.top();
            output.pop();
            return no;

        }
    }

    int peek() 
    {
        if(input.size()==0 && output.size() == 0)
            return -1;
        if(output.size() != 0)
        {
            int no = output.top();
            
            return no;
        }
        else{
            while(input.size() != 0)
            {
                output.push(input.top());
                input.pop();
            }
            int no = output.top();
            
            return no;

        }
        
    }

    bool isEmpty() {
        if(input.size()==0 && output.size() == 0)
            return true;
        else
            return false;
        
    }
};
