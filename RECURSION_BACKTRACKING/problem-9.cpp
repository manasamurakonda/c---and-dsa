// checking if a string is a palindrome using recursion

#include<bits/stdc++.h>
using namespace std;

bool palindrome(string s,int n,int i)
{
    if(i>=(n/2))
        return true;
    if(s[i]!=s[n-1-i])
        return false;
    return palindrome(s,n,i+1);
}
int main()
{
    string s;
    cout<<"enter a string: ";
    cin>>s;
    int n = s.size();
    cout<<palindrome(s,n,0);
    return 0;
}