
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> MergeIntArrays(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> mergedArr(nums1.size() + nums2.size());
    std::merge(nums1.begin(), nums1.end(), 
        nums2.begin(), nums2.end(), mergedArr.begin());
    return mergedArr;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    // Merge the two arrays
    vector<int> mergedArr = MergeIntArrays(nums1, nums2);
    
    // Get the median based on arr size
    double medianVal;
    int mergedArrSize = mergedArr.size();
    if (mergedArrSize % 2 == 0)
    {
        pair<int, int> midIndices = {mergedArrSize/2, mergedArrSize/2 - 1};
        medianVal = (mergedArr[midIndices.first] + mergedArr[midIndices.second])/2.0;
    }
    else
    {
        medianVal = mergedArr[(mergedArrSize-1)/2];
    }
    return medianVal;
}

int main()
{
    vector<int> arr1 = {1, 2};
    vector<int> arr2 = {3, 4};
    
    cout << findMedianSortedArrays(arr1, arr2);

    return 0;
}
