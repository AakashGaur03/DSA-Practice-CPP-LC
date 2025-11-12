// // Sort an Array
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given an array of integers nums, sort the array in ascending order and
// return
// // it.

// // You must solve the problem without using any built-in functions in
// O(nlog(n))
// // time complexity and with the smallest space complexity possible.

// // Example 1:

// // Input: nums = [5,2,3,1]
// // Output: [1,2,3,5]
// // Explanation: After sorting the array, the positions of some numbers are
// not
// // changed (for example, 2 and 3), while the positions of other numbers are
// // changed (for example, 1 and 5). Example 2:

// // Input: nums = [5,1,1,2,0,0]
// // Output: [0,0,1,1,2,5]
// // Explanation: Note that the values of nums are not necessarily unique.

// class Solution {
// public:
//   int partitionIndex(vector<int> &nums, int low, int high) {
//     int i = low;
//     int j = high;
//     int partition = nums[low];
//     while (i < j) {
//       while (nums[i] <= partition && i < high) {
//         i++;
//       }
//       while (nums[j] > partition && j > low) {
//         j--;
//       }
//       if (i < j) {
//         swap(nums[i], nums[j]);
//       }
//     }
//     swap(nums[low], nums[j]);
//     return j;
//   }
//   void quickSort(vector<int> &nums, int low, int high) {
//     if (low < high) {
//       int partIdx = partitionIndex(nums, low, high);
//       quickSort(nums, low, partIdx - 1);
//       quickSort(nums, partIdx + 1, high);
//     }
//   }
//   vector<int> sortArray(vector<int> &nums) {
//     // Quick Sort
//     quickSort(nums, 0, nums.size() - 1);
//     return nums;
//   }
// };
