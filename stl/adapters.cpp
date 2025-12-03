#include <iostream>
#include <deque>
#include <stack>
#include <queue>
using namespace std;

// ========================================
// DEQUE, STACK, QUEUE, PRIORITY_QUEUE
// ========================================

int main() {
    cout << "=== STL ADAPTER CONTAINERS ===" << endl;
    
    // ========================================
    // DEQUE - DOUBLE-ENDED QUEUE
    // ========================================
    
    cout << "\n=== DEQUE (Double-Ended Queue) ===" << endl;
    
    deque<int> dq;
    
    // Push at both ends - O(1)
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(5);
    dq.push_front(1);
    
    cout << "Deque: ";
    for (int x : dq) cout << x << " ";
    cout << endl;
    
    // Access - O(1)
    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;
    cout << "dq[1]: " << dq[1] << endl;
    cout << "dq.at(2): " << dq.at(2) << endl;
    
    // Pop from both ends - O(1)
    dq.pop_front();
    dq.pop_back();
    
    cout << "After pop_front and pop_back: ";
    for (int x : dq) cout << x << " ";
    cout << endl;
    
    // Insert/Erase - O(n)
    dq.insert(dq.begin() + 1, 7);
    dq.erase(dq.begin());
    
    // Size
    cout << "Size: " << dq.size() << endl;
    
    // When to use deque
    cout << "\nWhen to use deque:" << endl;
    cout << "✓ Need push/pop at both ends" << endl;
    cout << "✓ Need random access" << endl;
    cout << "✓ Sliding window problems" << endl;
    cout << "✗ Frequent middle insertions (use list)" << endl;
    
    // ========================================
    // STACK - LIFO (Last In First Out)
    // ========================================
    
    cout << "\n=== STACK (LIFO) ===" << endl;
    
    stack<int> st;
    
    // Push - O(1)
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    
    cout << "Stack size: " << st.size() << endl;
    cout << "Top: " << st.top() << endl;
    
    // Pop - O(1)
    st.pop();
    cout << "After pop, top: " << st.top() << endl;
    
    // Empty check
    cout << "Is empty: " << (st.empty() ? "Yes" : "No") << endl;
    
    // Print all (destructive)
    cout << "Stack elements (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    
    // Stack with different underlying container
    stack<int, vector<int>> vecStack;  // Using vector
    stack<int, deque<int>> deqStack;   // Using deque (default)
    stack<int, list<int>> listStack;   // Using list
    
    // Common stack patterns
    cout << "\nCommon stack uses:" << endl;
    cout << "- Function call stack" << endl;
    cout << "- Undo/Redo operations" << endl;
    cout << "- Expression evaluation" << endl;
    cout << "- Backtracking algorithms" << endl;
    cout << "- DFS traversal" << endl;
    
    // ========================================
    // QUEUE - FIFO (First In First Out)
    // ========================================
    
    cout << "\n=== QUEUE (FIFO) ===" << endl;
    
    queue<int> q;
    
    // Push - O(1)
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    
    cout << "Queue size: " << q.size() << endl;
    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    
    // Pop - O(1)
    q.pop();
    cout << "After pop, front: " << q.front() << endl;
    
    // Empty check
    cout << "Is empty: " << (q.empty() ? "Yes" : "No") << endl;
    
    // Print all (destructive)
    cout << "Queue elements (front to back): ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    
    // Queue with different underlying container
    queue<int, deque<int>> deqQueue;   // Using deque (default)
    queue<int, list<int>> listQueue;   // Using list
    
    // Common queue uses
    cout << "\nCommon queue uses:" << endl;
    cout << "- BFS traversal" << endl;
    cout << "- Task scheduling" << endl;
    cout << "- Buffer management" << endl;
    cout << "- Level order traversal" << endl;
    
    // ========================================
    // PRIORITY_QUEUE - MAX HEAP (default)
    // ========================================
    
    cout << "\n=== PRIORITY_QUEUE (Max Heap by default) ===" << endl;
    
    priority_queue<int> pq;
    
    // Push - O(log n)
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(40);
    
    cout << "Priority queue size: " << pq.size() << endl;
    cout << "Top (max): " << pq.top() << endl;
    
    // Pop - O(log n)
    pq.pop();
    cout << "After pop, top: " << pq.top() << endl;
    
    // Print all (destructive, in descending order)
    cout << "Elements (max to min): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    
    // ========================================
    // MIN HEAP (Priority Queue)
    // ========================================
    
    cout << "\n=== MIN HEAP (Priority Queue) ===" << endl;
    
    priority_queue<int, vector<int>, greater<int>> minPQ;
    
    minPQ.push(30);
    minPQ.push(10);
    minPQ.push(50);
    minPQ.push(20);
    
    cout << "Min heap top (min): " << minPQ.top() << endl;
    
    cout << "Elements (min to max): ";
    while (!minPQ.empty()) {
        cout << minPQ.top() << " ";
        minPQ.pop();
    }
    cout << endl;
    
    // ========================================
    // CUSTOM COMPARATOR
    // ========================================
    
    cout << "\n=== CUSTOM COMPARATOR ===" << endl;
    
    // Custom comparator for pairs (sort by second element)
    auto cmp = [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;  // Min heap by second element
    };
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> customPQ(cmp);
    
    customPQ.push({1, 50});
    customPQ.push({2, 30});
    customPQ.push({3, 70});
    customPQ.push({4, 20});
    
    cout << "Custom PQ (min by second): ";
    while (!customPQ.empty()) {
        auto [first, second] = customPQ.top();
        cout << "{" << first << "," << second << "} ";
        customPQ.pop();
    }
    cout << endl;
    
    // ========================================
    // COMMON PRIORITY_QUEUE PATTERNS
    // ========================================
    
    cout << "\n=== COMMON PRIORITY_QUEUE PATTERNS ===" << endl;
    
    // 1. Kth Largest Element
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    priority_queue<int, vector<int>, greater<int>> kthPQ;
    
    for (int num : nums) {
        kthPQ.push(num);
        if (kthPQ.size() > k) {
            kthPQ.pop();
        }
    }
    cout << k << "th largest: " << kthPQ.top() << endl;
    
    // 2. Top K Frequent Elements
    unordered_map<int, int> freq;
    vector<int> arr = {1, 1, 1, 2, 2, 3};
    for (int x : arr) freq[x]++;
    
    auto freqCmp = [](pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(freqCmp)> freqPQ(freqCmp);
    
    for (auto& [num, count] : freq) {
        freqPQ.push({num, count});
        if (freqPQ.size() > 2) {
            freqPQ.pop();
        }
    }
    
    cout << "Top 2 frequent: ";
    while (!freqPQ.empty()) {
        cout << freqPQ.top().first << " ";
        freqPQ.pop();
    }
    cout << endl;
    
    // 3. Merge K Sorted Lists (concept)
    cout << "\nOther PQ uses:" << endl;
    cout << "- Dijkstra's algorithm" << endl;
    cout << "- Huffman coding" << endl;
    cout << "- Median finder" << endl;
    cout << "- Task scheduling" << endl;
    
    // ========================================
    // COMPARISON TABLE
    // ========================================
    
    cout << "\n=== COMPARISON TABLE ===" << endl;
    cout << "Container      | Insert | Remove | Access | Use Case" << endl;
    cout << "---------------|--------|--------|--------|----------" << endl;
    cout << "deque          | O(1)*  | O(1)*  | O(1)   | Both ends" << endl;
    cout << "stack          | O(1)   | O(1)   | O(1)** | LIFO" << endl;
    cout << "queue          | O(1)   | O(1)   | O(1)** | FIFO" << endl;
    cout << "priority_queue | O(logn)| O(logn)| O(1)** | Heap" << endl;
    cout << "*At ends only" << endl;
    cout << "**Top/front only" << endl;
    
    // ========================================
    // TIME COMPLEXITIES
    // ========================================
    
    cout << "\n=== TIME COMPLEXITIES ===" << endl;
    cout << "\nDeque:" << endl;
    cout << "push_front/back: O(1)" << endl;
    cout << "pop_front/back: O(1)" << endl;
    cout << "Access []: O(1)" << endl;
    cout << "insert/erase middle: O(n)" << endl;
    
    cout << "\nStack:" << endl;
    cout << "push: O(1)" << endl;
    cout << "pop: O(1)" << endl;
    cout << "top: O(1)" << endl;
    
    cout << "\nQueue:" << endl;
    cout << "push: O(1)" << endl;
    cout << "pop: O(1)" << endl;
    cout << "front/back: O(1)" << endl;
    
    cout << "\nPriority Queue:" << endl;
    cout << "push: O(log n)" << endl;
    cout << "pop: O(log n)" << endl;
    cout << "top: O(1)" << endl;
    
    return 0;
}
