// // Candy
// // Solved
// // Hard
// // Topics
// // premium lock icon
// // Companies
// // There are n children standing in a line. Each child is assigned a rating
// // value given in the integer array ratings.

// // You are giving candies to these children subjected to the following
// // requirements:

// // Each child must have at least one candy.
// // Children with a higher rating get more candies than their neighbors.
// // Return the minimum number of candies you need to have to distribute the
// // candies to the children.

// // Example 1:

// // Input: ratings = [1,0,2]
// // Output: 5
// // Explanation: You can allocate to the first, second and third child with 2,
// 1,
// // 2 candies respectively. Example 2:

// // Input: ratings = [1,2,2]
// // Output: 4
// // Explanation: You can allocate to the first, second and third child with 1,
// 2,
// // 1 candies respectively. The third child gets 1 candy because it satisfies
// the
// // above two conditions.

// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         // Concept of Slope
//         int size = ratings.size();
//         if (size == 0)
//             return 0;

//         int sum = 1;
//         int i = 1;
//         while (i < size) {
//             if (ratings[i] == ratings[i - 1]) {
//                 sum++;
//                 i++;
//             }
//             // increasing slope
//             int peak = 1;
//             while (i < size && ratings[i] > ratings[i - 1]) {
//                 peak++;
//                 sum += peak;
//                 i++;
//             }
//             // decreasing slope
//             int down = 1;
//             while (i < size && ratings[i] < ratings[i - 1]) {
//                 sum += down;
//                 down++;
//                 i++;
//             }
//             if (down > peak) {
//                 sum += down - peak;
//             }
//         }
//         return sum;
//     }
// };