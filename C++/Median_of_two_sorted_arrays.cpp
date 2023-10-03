//Question Link-https://leetcode.com/problems/median-of-two-sorted-arrays/description/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size()+nums2.size();
        vector<int>arr3(m);
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), arr3.begin());
        sort(arr3.begin(), arr3.end());
    double n;
        if(m%2!=0)
        n = arr3[m/2];
        else
        {
           
            n= arr3[m/2]+arr3[m/2-1];
            n=n/2;
           
        }

    return n;    
    }
    
};