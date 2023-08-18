class MyQueue {
    stack<int> input,output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        input.push(x);
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
    }
    
    int pop() {
        int ele=input.top();
        input.pop();
        return ele;
        // if(output.empty()==0){
        //     int ele=output.top();
        //     output.pop();
        //     return ele;
        // }
        // while(!input.empty()){
        //     output.push(input.top());
        //     input.pop();
        // }
        // int ele=output.top();
        // output.pop();
        // return ele;
    }
    
    int peek() {
        return input.top();
        // if(!output.empty()) return output.top();
        // while(!input.empty()){
        //     output.push(input.top());
        //     input.pop();
        // }
        // return output.top();
    }
    
    bool empty() {
        return input.empty();
        // if(input.empty() and output.empty()) return true;
        // return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */