#include<bits/stdc++.h>
using namespace std;

class stck{
public:
    int arr[10];
    int tp = -1;
    void push(int x)
    {
        if(tp == 9)
            cout<<"stack is full"<<endl;
        else{
            tp++;
            arr[tp]=x;
            cout<<x<<" inserted succesfully"<<endl;
        }
    } 
    void pop()
    {
        if(tp==-1)
            cout<<"stack is empty"<<endl;
        else{
            tp--;
            cout<<"poped successfully"<<endl;
        }
    }
    int top()
    {
        if(tp==-1){
            cout<<"sack is empty";
            return -1;
        }
        else{
            cout<<"top element is: "<<arr[tp]<<endl;
            return arr[tp];
        }
    }
    int size()
    {
        return tp+1;
    }
    bool empty()
    {
        if(tp==-1)
            return true;
        return false;
    }
};

int main()
{
    stck st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.top();
    st.pop();
    st.size();
    if(st.empty())
        cout<<"stack is empty"<<endl;
    else
        cout<<"stack is not empty"<<endl;
    return 0;
}