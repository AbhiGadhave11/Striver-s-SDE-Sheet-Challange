#include <bits/stdc++.h> 
class Queue {
    private:
    int _front = 0;
    int rear = 0;
    vector<int>v;
public:
    Queue() {
        
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() 
    {
        if(_front == rear)
            return true;
        return false;
        // Implement the isEmpty() function
    }

    void enqueue(int data) {
        v.push_back(data);
        rear++;
        // Implement the enqueue() function

    }

    int dequeue() {
        if(_front == rear)
            return -1;
        int no = v[_front];
        v[_front] = -1;
        return no;
        // Implement the dequeue() function
    }

    int front() {
        return v[_front];
        // Implement the front() function
    }
};
