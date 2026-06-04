// GFG - count inversions
class Solution {
  public:
    int merge(vector<int> &arr,int left,int mid,int right)
    {
        int inversions = 0;
        int i,j;
        i=left,j=mid+1;
        vector<int> temp;
        while(i<=mid && j<=right)
        {
            if(arr[i]<=arr[j])
            {
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                inversions = inversions + (mid-i+1);
                j++;
            }
        }
        while(i<=mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=right)
        {
            temp.push_back(arr[j]);
            j++;
        }
        int x = 0;
        for(int i=left;i<=right;i++)
        {
            arr[i] = temp[x++];
        }
        return inversions;
    }
    int mergeSort(vector<int> &arr,int left,int right)
    {
        int inversions = 0;
        if(left<right)
        {
            int mid = (left+right)/2;
            inversions += mergeSort(arr,left,mid);
            inversions += mergeSort(arr,mid+1,right);
            inversions += merge(arr,left,mid,right);
        }
        return inversions;
    }
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return mergeSort(arr,0,n-1);
    }
};