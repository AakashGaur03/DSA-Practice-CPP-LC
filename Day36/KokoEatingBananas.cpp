// //  Koko Eating Bananas
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Koko loves to eat bananas. There are n piles of bananas, the ith pile has
// piles[i] bananas. The guards have gone and will come back in h hours.

// // Koko can decide her bananas-per-hour eating speed of k. Each hour, she
// chooses some pile of bananas and eats k bananas from that pile. If the pile
// has less than k bananas, she eats all of them instead and will not eat any
// more bananas during this hour.

// // Koko likes to eat slowly but still wants to finish eating all the bananas
// before the guards return.

// // Return the minimum integer k such that she can eat all the bananas within
// h hours.

// // Example 1:

// // Input: piles = [3,6,7,11], h = 8
// // Output: 4
// // Example 2:

// // Input: piles = [30,11,23,4,20], h = 5
// // Output: 30
// // Example 3:

// // Input: piles = [30,11,23,4,20], h = 6
// // Output: 23

// class Solution {
// public:

//     int maxiVal(vector<int>&arr,int n){
//         int maxVal=INT_MIN;
//         for(int i=0;i<n;i++){
//             maxVal = max(maxVal,arr[i]);
//         }
//         return maxVal;
//     }

//     bool canEatBanana(vector<int> &arr,int eatBanana,int hours,int n){
//         int i=0;
//         int k = 0;
//         for(int i=0;i<n;i++){
//             k += ceil((double)arr[i] / eatBanana);
//             if(k>hours) return false;
//         }
//         return true;

//     }

//     int minEatingSpeed(vector<int>& piles, int h) {
//         int n = piles.size();
//         int low = 1;
//         int high = maxiVal(piles,n);
//         while(low<=high){
//             int mid = low + (high-low)/2;
//             if(canEatBanana(piles,mid,h,n)){
//                 high = mid - 1;
//             }else{
//                 low = mid + 1;
//             }
//         }
//         return low;
//     }
// };