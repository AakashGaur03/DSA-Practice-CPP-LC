// // // 540. Single Element in a Sorted Array
// // // Solved
// // // Medium
// // // Topics
// // // premium lock icon
// // // Companies
// // // You are given a sorted array consisting of only integers where every
// // element appears exactly twice, except for one element which appears
// exactly
// // once.

// // // Return the single element that appears only once.

// // // Your solution must run in O(log n) time and O(1) space.

// // // Example 1:

// // // Input: nums = [1,1,2,3,3,4,4,8,8]
// // // Output: 2
// // // Example 2:

// // // Input: nums = [3,3,7,7,10,11,11]
// // // Output: 10

// // class Solution {
// // public:
// //     int singleNonDuplicate(vector<int>& nums) {
// //         int res = 0;
// //         int n = nums.size();
// //         for(int i = 0;i<n;i++){
// //             res^=nums[i];
// //         }
// //         return res;
// //     }
// // };

// // 1 1 2 3 3 4 4 5 5 6  6
// // 0 1 2 3 4 5 6 7 8 9  10
// // mid = 5

// // 1 1 2 2 3 3 4 4 5 5 6 6 7
// // 0 1 2 3 4 5 6 7 8 9  10 11
// // l         l     m        H

// //  m = odd and same on right element in left
// //  m = even and same on left  element in left

// //  m = odd and same on left   element in right
// //  m = even and same on right element in right

// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         int low = 1;
//         int high = n-2;
//         if(nums.size()==1) return nums[0];
//         if(nums[0]!= nums[1]){
//             return nums[0];
//         }
//         if(nums[n-1]!= nums[n-2]){
//             return nums[n-1];
//         }
//         while(low<=high){
//             int mid = low + (high-low)/2;
//             bool isMidEven = mid%2==0;
//             if(nums[mid]!= nums[mid-1] && nums[mid]!=nums[mid+1]){
//                 return nums[mid];
//             }else if((isMidEven && nums[mid]==nums[mid-1]) || (!isMidEven &&
//             nums[mid]==nums[mid+1])){
//                 high = mid-1;
//             }else{
//                 low = mid+1;
//             }
//         }
//      return -1; // Never get here
//     }
// };