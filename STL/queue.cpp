#include<iostream>
using namespace std;
#include<queue>
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.emplace(6);
    cout << q.size() << endl;
    /*while(!q.empty()){
        cout<< q.front() << " ";
        q.pop();
    }
    cout<< endl; */
    queue<int> q1;
    q1.swap(q);
    cout << q.size() << " " << q1.size() << endl;
    while(!q1.empty()){
        cout<< q1.front() << " ";
        q1.pop();
    }
    return 0;
}