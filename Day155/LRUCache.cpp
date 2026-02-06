// // LRU Cache
// // Solved
// // Medium
// // Topics
// // premium lock icon
// // Companies
// // Design a data structure that follows the constraints of a Least Recently
// Used
// // (LRU) cache.

// // Implement the LRUCache class:

// // LRUCache(int capacity) Initialize the LRU cache with positive size
// capacity.
// // int get(int key) Return the value of the key if the key exists, otherwise
// // return -1. void put(int key, int value) Update the value of the key if the
// // key exists. Otherwise, add the key-value pair to the cache. If the number
// of
// // keys exceeds the capacity from this operation, evict the least recently
// used
// // key. The functions get and put must each run in O(1) average time
// complexity.

// // Example 1:

// // Input
// // ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get",
// "get"]
// // [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// // Output
// // [null, null, null, 1, null, -1, null, -1, 3, 4]

// // Explanation
// // LRUCache lRUCache = new LRUCache(2);
// // lRUCache.put(1, 1); // cache is {1=1}
// // lRUCache.put(2, 2); // cache is {1=1, 2=2}
// // lRUCache.get(1);    // return 1
// // lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// // lRUCache.get(2);    // returns -1 (not found)
// // lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// // lRUCache.get(1);    // return -1 (not found)
// // lRUCache.get(3);    // return 3
// // lRUCache.get(4);    // return 4

// // Constraints:

// // 1 <= capacity <= 3000
// // 0 <= key <= 104
// // 0 <= value <= 105
// // At most 2 * 105 calls will be made to get and put.

// class Node {
// public:
//     int key;
//     int val;
//     Node* next;
//     Node* prev;

// public:
//     Node(int key1, int val1) {
//         key = key1;
//         val = val1;
//         next = nullptr;
//         prev = nullptr;
//     }
// };

// class LRUCache {
// private:
//     int cap;
//     unordered_map<int, Node*> mpp;
//     Node* head;
//     Node* tail;

//     void deleteNodeDoubleLL(Node* node) {
//         if (node == head || node == tail) {
//             return;
//         }
//         Node* prev = node->prev;
//         Node* front = node->next;
//         prev->next = front;
//         front->prev = prev;
//         node->next = nullptr;
//         node->prev = nullptr;
//     }
//     void insertAfterHeadDoublyLL(Node* node) {
//         Node* temp = head->next;
//         head->next = node;
//         node->prev = head;
//         node->next = temp;
//         temp->prev = node;
//     }

// public:
//     LRUCache(int capacity) {
//         cap = capacity;
//         head = new Node(-1, -1);
//         tail = new Node(-1, -1);
//         head->next = tail;
//         tail->prev = head;
//     }

//     int get(int key) {
//         if (mpp.find(key) == mpp.end()) {
//             return -1;
//         }
//         Node* node = mpp[key];
//         deleteNodeDoubleLL(node);
//         insertAfterHeadDoublyLL(node);
//         return node->val;
//     }

//     void put(int key, int value) {
//         if (cap == 0)
//             return;
//         if (mpp.find(key) != mpp.end()) {
//             Node* node = mpp[key];
//             node->val = value;
//             deleteNodeDoubleLL(node);
//             insertAfterHeadDoublyLL(node);
//         } else {
//             if (mpp.size() == cap) {
//                 Node* lru = tail->prev;
//                 mpp.erase(lru->key);
//                 deleteNodeDoubleLL(lru);
//                 delete lru;
//             }
//             Node* node = new Node(key, value);
//             mpp[key] = node;
//             insertAfterHeadDoublyLL(node);
//         }
//     }
// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */