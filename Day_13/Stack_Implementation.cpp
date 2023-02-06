#include <bits/stdc++.h> 
// Stack class.
class Stack {
private:

    vector<int>arr;
    int _top ;
    int size ;
public:
    
    Stack(int capacity) {
        arr.resize(capacity);
        _top = -1;
        size = capacity;
    }

    void push(int num) 
    {
        if(_top == size-1)
            return ;
        _top++;
        arr[_top] = num;
    }

    int pop() 
    {
        int no = arr[_top];
        _top--;
        return no;
        
    }
    
    int top() 
    {
        return arr[_top];
        
    }
    
    int isEmpty() 
    {
        if(_top == -1)
            return true;
        else
            return false;
        
    }
    
    int isFull() {
        if(_top == size-1)
            return true;
        else
            return false;
    }
    
};
