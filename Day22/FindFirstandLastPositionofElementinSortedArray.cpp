// // Find First and Last Position of Element in Sorted Array
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given an array of integers nums sorted in non-decreasing order, find the
// starting and ending position of a given target value.

// // If target is not found in the array, return [-1, -1].

// // You must write an algorithm with O(log n) runtime complexity.

// // Example 1:

// // Input: nums = [5,7,7,8,8,10], target = 8
// // Output: [3,4]
// // Example 2:

// // Input: nums = [5,7,7,8,8,10], target = 6
// // Output: [-1,-1]
// // Example 3:

// // Input: nums = [], target = 0
// // Output: [-1,-1]

// class Solution {
// public:
// int lowerBound(vector<int> &arr,int size,int target){
//     int low = 0;
//     int high = size-1;
//     int ans=-1;
//     while(low<=high){
//         int mid = low + (high-low)/2;

//         if(arr[mid] >= target){
//             if(arr[mid]==target) ans = mid;
//             high=mid-1;
//         }else{
//             low = mid+1;
//         }
//     }
//     return ans;
// }
// int upperBound(vector<int> &arr,int size,int target){
//     int low = 0;
//     int high = size-1;
//     int ans=-1;
//     while(low<=high){
//         int mid = low + (high-low)/2;

//         if(arr[mid] <= target){
//             if(arr[mid]==target) ans = mid;
//             low=mid+1;
//         }else{
//             high = mid-1;
//         }
//     }
//     return ans;
// }
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int firstElement = lowerBound(nums,nums.size(),target);
//         if(firstElement == -1) return {-1,-1};
//         int lastElement = upperBound(nums,nums.size(),target);
//         return {firstElement,lastElement};
//     }
// };