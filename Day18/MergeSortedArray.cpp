// // Merge Sorted Array
// // Solved
// // Easy
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // You are given two integer arrays nums1 and nums2, sorted in non-decreasing
// order, and two integers m and n, representing the number of elements in nums1
// and nums2 respectively.

// // Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// // The final sorted array should not be returned by the function, but instead
// be stored inside the array nums1. To accommodate this, nums1 has a length of
// m + n, where the first m elements denote the elements that should be merged,
// and the last n elements are set to 0 and should be ignored. nums2 has a
// length of n.

// // Example 1:

// // Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// // Output: [1,2,2,3,5,6]
// // Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// // The result of the merge is [1,2,2,3,5,6] with the underlined elements
// coming from nums1.
// // Example 2:

// // Input: nums1 = [1], m = 1, nums2 = [], n = 0
// // Output: [1]
// // Explanation: The arrays we are merging are [1] and [].
// // The result of the merge is [1].
// // Example 3:

// // Input: nums1 = [0], m = 0, nums2 = [1], n = 1
// // Output: [1]
// // Explanation: The arrays we are merging are [] and [1].
// // The result of the merge is [1].
// // Note that because m = 0, there are no elements in nums1. The 0 is only
// there to ensure the merge result can fit in nums1.

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         vector<int> arr;
//         int lastRight = n-1;
//         int lastLeft = m-1;
//         int lastIndex = nums1.size()-1;
//         cout<<lastRight<< " " <<lastLeft<<" "<<lastIndex;

//         while(lastRight>=0 && lastLeft>=0){
//             if(nums1[lastLeft]>nums2[lastRight]){
//                 nums1[lastIndex] = nums1[lastLeft];
//                 lastLeft--;
//             }else{
//                 nums1[lastIndex] = nums2[lastRight];
//                 lastRight--;
//             }
//                 lastIndex--;
//         }
//         while(lastRight>=0){
//            nums1[lastIndex] = nums2[lastRight];
//             lastIndex--;
//             lastRight--;
//         }
//     }
// };

//     // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//     //     vector<int> arr;
//     //     int left = 0;
//     //     int right = 0;
//     //     while(left<m && right<n){
//     //         if(nums1[left]<nums2[right]){
//     //             arr.push_back(nums1[left]);
//     //             left++;
//     //         }else{
//     //             arr.push_back(nums2[right]);
//     //             right++;
//     //         }
//     //     }
//     //     while(left<m){
//     //          arr.push_back(nums1[left]);
//     //             left++;
//     //     }
//     //     while(right<n){
//     //          arr.push_back(nums2[right]);
//     //             right++;
//     //     }

//     //     for(int i =0;i<arr.size();i++){
//     //         nums1[i] = arr[i];
//     //     }

//     // }