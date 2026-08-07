class MinStack {
public:
    stack<int>stk;
    stack<int>minStk;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(minStk.empty() || minStk.top() >= val)minStk.push(val);
    }
    
    void pop() {
        if(!minStk.empty() && minStk.top() == stk.top())minStk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
