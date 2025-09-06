// // 189. Rotate Array
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Hint
// // Given an integer array nums, rotate the array to the right by k steps,
// where k is non-negative.

// // Example 1:

// // Input: nums = [1,2,3,4,5,6,7], k = 3
// // Output: [5,6,7,1,2,3,4]
// // Explanation:
// // rotate 1 steps to the right: [7,1,2,3,4,5,6]
// // rotate 2 steps to the right: [6,7,1,2,3,4,5]
// // rotate 3 steps to the right: [5,6,7,1,2,3,4]
// // Example 2:

// // Input: nums = [-1,-100,3,99], k = 2
// // Output: [3,99,-1,-100]
// // Explanation:
// // rotate 1 steps to the right: [99,-1,-100,3]
// // rotate 2 steps to the right: [3,99,-1,-100]

// // Constraints:

// // 1 <= nums.length <= 105
// // -231 <= nums[i] <= 231 - 1
// // 0 <= k <= 105

// // Follow up:

// // Try to come up with as many solutions as you can. There are at least three
// different ways to solve this problem.
// // Could you do it in-place with O(1) extra space?

// class Solution {
// public:
//     void reverseArr(vector<int> &arr,int start,int end){
//         while(start<end){
//             swap(arr[start],arr[end]);
//             start++;
//             end--;
//         }
//     }
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k = k % n;
//         reverseArr(nums,0,n-k-1);
//         reverseArr(nums,n-k,n-1);
//         reverseArr(nums,0,n-1);
//     }
// };

// // void rotate(vector<int>& nums, int k) {
//         //     // Rotate Right
//     //     int n = nums.size();
//     //     k = k % n;
//     //     vector<int> temp;
//     //     // Store First n-k elements
//     //     for(int i = 0;i<n-k;i++){
//     //         temp.push_back(nums[i]);
//     //     }

//     //     // Place last k elements at there correct position
//     //     for(int i=0;i<k;i++){
//     //         nums[i] = nums[n-k+i];
//     //     }

//     //     // Place Temp varibales that is last n -k art correct position
//     //     for(int i=0;i<n-k;i++){
//     //         nums[k+i] = temp[i];
//     //     }

//     // }
// // }

// // void rotate(vector<int>& nums, int k) {
//     //     // Rotate Left
//     //     int n = nums.size();
//     //     k = k % n;
//     //     vector<int> temp;
//     //     // Store starting K elments in temp
//     //     for(int i = 0;i<k;i++){
//     //         temp.push_back(nums[i]);
//     //     }
//     //     // get post K elements at there right position
//     //     for(int i = 0; i <n-k; i++){
//     //         nums[i] = nums[i+k];
//     //     }
//     //     // Store temp at post k position
//     //     for(int i = 0;i<k;i++){ // because in temp there are at most k
//     elements
//     //         nums[n-k+i] = temp[i];
//     //     }

//     // }