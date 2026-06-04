#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//custom comparator
bool comparator(int a,int b)
{
    if(b<=a)
        return true;
    else
        return false;
}
int main()
{
    int arr[] = {3,23,2,5,67,34,34,34,2,3};
    vector<int> vec = {10,2,3,4,5,6,74,89,99,100};
    for(int i : arr)
    {
        cout<< i << " ";
    }
    cout << endl;
    for(int i : vec)
    {
        cout<< i << " ";
    }
    cout << endl;
    // sorting
    sort(arr,arr+10,greater<int>());
    sort(vec.begin(),vec.end(),comparator);
    for(int i : arr)
    {
        cout<< i << " ";
    }
    cout << endl;
    for(int i : vec)
    {
        cout<< i << " ";
    }
    cout << endl;
    // reverse
    reverse(arr,arr+10);
    reverse(vec.begin(),vec.end());
    for(int i : arr)
    {
        cout<< i << " ";
    }
    cout << endl;
    for(int i : vec)
    {
        cout<< i << " ";
    }
    cout << endl;
    // next_permutaion()
    string s = "manasa";
    next_permutation(s.begin(),s.end());
    cout << s << endl;
    next_permutation(s.begin(),s.end());
    cout << s << endl;
    next_permutation(s.begin(),s.end());
    cout << s << endl;

    // min(), max(), swap()
    int a,b;
    a = 10;
    b = 100;
    cout << min(a,b) << endl;
    cout << max(a,b) << endl;
    swap(a,b);
    cout << a << " " <<b <<endl;

    //max_element() min_element()
    cout << *(min_element(arr,arr+10)) << endl;
    cout << *(max_element(arr,arr+10)) << endl;
    cout << *(min_element(vec.begin(),vec.end())) << endl;
    cout << *(max_element(vec.begin(),vec.end())) << endl;
    
    // binary_search()
    cout << binary_search(arr,arr+10,10) << endl;
    cout << binary_search(vec.begin(),vec.end(),100) << endl;

    // counting set bits
    int x = 10;
    cout<< __builtin_popcount(x) << endl;
    return 0;
}