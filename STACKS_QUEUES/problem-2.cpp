// min stack
// leetcode - 155

// brute->storing pair in stack tc-o(1) sc-o(2n)
/*class MinStack {
public:
    MinStack() {
        
    }
    stack<pair<int,int>> st;
    void push(int val) {
        if(st.empty())
            st.push({val,val});
        else
            st.push({val,min(val,st.top().second)});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {

        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};*/


// optimal -> using formula 2*val-mini = newval  tc-o(1) sc-o(n)
class MinStack {
public:
    MinStack() {
        
    }
    stack<long long> st;
    long long mini = INT_MAX;
    void push(long long val) {
        if(st.empty())
        {
            mini = val;
            st.push(val);
        }
        else{
            if(val<mini)
            {
                st.push(2*val-mini);
                mini = val;
            }
            else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.top()<mini)
        {
            mini = 2*mini-st.top();
            st.pop();
        }
        else st.pop();
    }
    
    int top() {
        if(st.top()<mini)
            return mini;
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};