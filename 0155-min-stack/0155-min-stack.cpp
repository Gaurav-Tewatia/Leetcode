class MinStack {
    stack<int> st,minist;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minist.push(val);
        }else if(val<=minist.top()){
            st.push(val);
            minist.push(val);
        }else
            st.push(val);
    }
    
    void pop() {
        if(st.top()==minist.top()) minist.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minist.top();
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