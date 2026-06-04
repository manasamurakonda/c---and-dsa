// median of two sorted arrays
// leetcode - 4
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // brute -> merging two sorted arrays and finding median
        /*int n1 = nums1.size(),n2 = nums2.size();
        vector<int> temp;
        int l=0,r=0;
        while(l<n1 && r<n2)
        {
            if(nums1[l]<=nums2[r])
            {
                temp.push_back(nums1[l]);
                l++;
            }
            else{
                temp.push_back(nums2[r]);
                r++;
            }
        }
        while(l<n1)
        {
            temp.push_back(nums1[l]);
            l++;
        }
        while(r<n2)
        {
            temp.push_back(nums2[r]);
            r++;
        }
        int size = n1+n2;
        int mid;
        mid = floor(size/2);
        if(size%2==0)
        {
            return (temp[mid]+temp[mid-1])/(double)2;
        }
        else return temp[mid];*/

        // better -> optimizing space (getting rid of extra array)
        /*int n1 = nums1.size(),n2 = nums2.size();
        int ind1 = -1,ind2 = -1;
        int sum = n1+n2;
        if(sum%2==0)
        {
            ind1 = sum/2;
            ind2 = (sum/2)-1;
        }
        else{
            ind1 = sum/2;
        }
        double median = 0;
        int l = 0,r=0,ind=0;
        while(l<n1 && r<n2)
        {
            if(nums1[l]<=nums2[r])
            {
                if(ind==ind1 || ind==ind2)
                {
                    median = median+nums1[l];
                }
                l++;
            }
            else{
                if(ind==ind1 || ind==ind2)
                    median = median+nums2[r];
                r++;
            }
            ind++;
        }
        while(l<n1)
        {
            if(ind==ind1 || ind==ind2)
                median = median+nums1[l];
            l++;
            ind++;
        }
        while(r<n2)
        {
            if(ind==ind1 || ind==ind2)
                median = median+nums2[r];
            r++;
            ind++;
        }
        if(sum%2==0)
            return median/(double)2;
        return median;*/


        // optimal -> pending
    }
};