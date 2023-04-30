class MinStack {
public:
    stack<long long> st;
    long long mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(long long val) {
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else if(val<mini){
            st.push((long long)2*val-mini);
            mini=val;
        }
        else
            st.push(val);
       
    }
    
    void pop() {
            
        if(st.top()<mini){
            mini=(long long)2*mini-st.top();
        }
        st.pop();
    }
    
    long long top() {
        if(st.top()<mini)
            return mini;
        else 
            return st.top();
    }
    
    long long getMin() {
        if(st.size()==0)
            return -1;
        else 
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