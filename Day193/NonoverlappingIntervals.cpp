// // Non-overlapping Intervals
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Given an array of intervals intervals where intervals[i] = [starti, endi],
// // return the minimum number of intervals you need to remove to make the rest
// of
// // the intervals non-overlapping.

// // Note that intervals which only touch at a point are non-overlapping. For
// // example, [1, 2] and [2, 3] are non-overlapping.

// // Example 1:

// // Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// // Output: 1
// // Explanation: [1,3] can be removed and the rest of the intervals are
// // non-overlapping. Example 2:

// // Input: intervals = [[1,2],[1,2],[1,2]]
// // Output: 2
// // Explanation: You need to remove two [1,2] to make the rest of the
// intervals
// // non-overlapping. Example 3:

// // Input: intervals = [[1,2],[2,3]]
// // Output: 0
// // Explanation: You don't need to remove any of the intervals since they're
// // already non-overlapping.

// class Solution {
// public:
//     static bool comp(vector<int>& a, vector<int>& b) {
//         if (a[1] == b[1])
//             return a[0] < b[0]; // tie break by start
//         return a[1] < b[1];     // earliest finish time
//     }

//     int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//         int size = intervals.size();
//         if (size == 0) {
//             return 0;
//         }
//         sort(intervals.begin(), intervals.end(), comp);

//         int cnt =1;
//         int lastEndTime = intervals[0][1];
//         for(int i=0;i<size;i++){
//             if(intervals[i][0] >= lastEndTime){
//                 cnt++;
//                 lastEndTime = intervals[i][1];
//             }
//         }
//         return size - cnt;
//     }
// };