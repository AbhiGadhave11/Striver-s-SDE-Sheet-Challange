class MinStack {
    private:
    stack<long long>st;
    long long mini;
public:
    
    MinStack() {
        mini = INT_MAX;
        while(st.size() != 0)
            st.pop();
    }
    
    void push(int val) 
    {
        if(st.size() == 0)
        {
            mini = val;
            st.push(val);
        }
        else
        {
            if(val < mini)
            {
                long long no = (2*(long long)val);
                no = no - mini;
                st.push(no);
                mini = val;
            }
            else
                st.push(val);
        }
        
    }
    
    void pop() 
    {
        if(st.size() == 0)
            return ;
        long long no = st.top();
        st.pop();
        if(no < mini)
            mini = 2*mini*1LL - no;
        
    }
    
    int top() 
    {
        if(st.size() == 0)
            return -1;
        long long no = st.top();
        if(no < mini)
            return mini;
        return no;
        
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
