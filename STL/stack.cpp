#include<iostream>
using namespace std;
#include<stack>
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.emplace(6);
    cout << st.size() << endl;
    /*while(!st.empty()){
        cout<< st.top() << " ";
        st.pop();
    }
    cout<< endl; */
    stack<int> st1;
    st1.swap(st);
    cout << st.size() << " " << st1.size() << endl;
    while(!st1.empty()){
        cout<< st1.top() << " ";
        st1.pop();
    }
    return 0;
}