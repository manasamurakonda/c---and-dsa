#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
int main()
{
    // writing into a file
    ofstream fout;
    fout.open("output.txt"); // file lekapothey create chesi open chesthundhi
    fout << "hello file handling....from manasa";
    fout.close();
    // reading from file
    ifstream fin;
    fin.open("output.txt");
    char c;
    while(!fin.eof()){
        c = fin.get();
        cout << c;
    }
    fin.close();
    // writing values of vector into a file
    fout.open("vector.txt");
    vector<int> arr = {1,3,4,5,2,3,4,5};
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++)
    {
        fout << arr[i] << " ";
    }
    fout.close();
    // reading from file using getline
    string s;
    cout << endl;
    fin.open("getline.txt");
    while(getline(fin,s)){
        cout << s << endl;
    }
    return 0;
}