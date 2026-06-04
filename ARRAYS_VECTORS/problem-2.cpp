// find the second largest element in the array
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;
int main()
{
    int arr[] = {3,2,4,5,6,7,8,9,10,1};
    int size = sizeof(arr)/sizeof(int);
    // brute - > sort cheyyi (duplicates untey em peekuthav? aalochinchu....last element tho emanna compare chesthava?)
    /* sort(arr,arr+size);
    cout << "the second largest element is: " << arr[size-2] << endl; */
    // o(nlogn)

    //optimal - > two variables theesko
    int firstLargest , secondLargest;
    firstLargest = INT_MIN;
    secondLargest = INT_MIN;
    for(int i=0;i<size;i++)
    {
        if(arr[i]>firstLargest)
        {
            secondLargest = firstLargest;
            firstLargest = arr[i];
        }
        else if(arr[i] > secondLargest && arr[i] < firstLargest)
            secondLargest = arr[i];
    }
    // o(n)
    cout << "the second largest element is: " << secondLargest << endl;
}