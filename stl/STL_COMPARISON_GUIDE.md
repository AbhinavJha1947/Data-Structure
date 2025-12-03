# C++ STL CONTAINERS - COMPLETE COMPARISON GUIDE
## Interview Preparation Reference

---

## 📋 TABLE OF CONTENTS
1. [Overview](#overview)
2. [Sequence Containers](#sequence-containers)
3. [Associative Containers](#associative-containers)
4. [Unordered Containers](#unordered-containers)
5. [Container Adapters](#container-adapters)
6. [Utility](#utility)
7. [Complete Comparison Table](#complete-comparison-table)
8. [Decision Tree](#decision-tree)
9. [Interview Questions](#interview-questions)
10. [Time Complexity Cheat Sheet](#time-complexity-cheat-sheet)

---

## 🎯 OVERVIEW

### What is STL?
**Standard Template Library (STL)** is a collection of generic classes and functions in C++:
- **Containers**: Data structures (vector, map, set, etc.)
- **Algorithms**: Functions (sort, search, etc.)
- **Iterators**: Objects to traverse containers
- **Function Objects**: Objects that act like functions

### Why Use STL?
✅ **Tested and optimized** - Industry standard  
✅ **Generic** - Works with any data type  
✅ **Reusable** - Don't reinvent the wheel  
✅ **Efficient** - Optimized implementations  
✅ **Interview standard** - Expected knowledge  

---

## 1️⃣ SEQUENCE CONTAINERS

### VECTOR
```cpp
#include <vector>
vector<int> v = {1, 2, 3};
```

**Implementation**: Dynamic array  
**Access**: O(1) random access  
**Insert/Delete**: O(1) at end, O(n) elsewhere  

**Advantages**:
✅ Fast random access  
✅ Cache-friendly (contiguous memory)  
✅ Fast iteration  
✅ Low memory overhead  

**Disadvantages**:
❌ Slow insert/delete in middle  
❌ Reallocation cost  

**When to Use**:
- Default choice for most cases
- Need random access
- Frequent access, rare insertions

---

### LIST (Doubly Linked List)
```cpp
#include <list>
list<int> l = {1, 2, 3};
```

**Implementation**: Doubly linked list  
**Access**: O(n) sequential only  
**Insert/Delete**: O(1) with iterator  

**Advantages**:
✅ Fast insert/delete anywhere  
✅ No reallocation  
✅ Splice operation  

**Disadvantages**:
❌ No random access  
❌ High memory overhead (pointers)  
❌ Cache-unfriendly  

**When to Use**:
- Frequent insertions/deletions in middle
- Need splice operation
- Don't need random access

---

### DEQUE (Double-Ended Queue)
```cpp
#include <deque>
deque<int> dq = {1, 2, 3};
```

**Implementation**: Array of arrays  
**Access**: O(1) random access  
**Insert/Delete**: O(1) at both ends, O(n) in middle  

**Advantages**:
✅ Fast push/pop at both ends  
✅ Random access  
✅ No reallocation  

**Disadvantages**:
❌ Slower than vector for iteration  
❌ More memory overhead than vector  

**When to Use**:
- Need push/pop at both ends
- Sliding window problems
- BFS queue

---

### ARRAY (Fixed Size)
```cpp
#include <array>
array<int, 5> arr = {1, 2, 3, 4, 5};
```

**Implementation**: Fixed-size array  
**Access**: O(1)  
**Size**: Compile-time constant  

**When to Use**:
- Size known at compile time
- Need stack allocation
- No dynamic resizing needed

---

## 2️⃣ ASSOCIATIVE CONTAINERS (Ordered)

### MAP (Key-Value, Ordered)
```cpp
#include <map>
map<int, string> m = {{1, "one"}, {2, "two"}};
```

**Implementation**: Red-Black Tree  
**All Operations**: O(log n)  
**Ordering**: Sorted by key  

**Advantages**:
✅ Sorted iteration  
✅ Range queries (lower_bound, upper_bound)  
✅ Guaranteed O(log n)  

**Disadvantages**:
❌ Slower than unordered_map  
❌ Memory overhead (tree pointers)  

**When to Use**:
- Need sorted order
- Need range queries
- Need lower/upper bound

**Variants**:
- `multimap`: Allows duplicate keys

---

### SET (Unique Elements, Ordered)
```cpp
#include <set>
set<int> s = {1, 2, 3};
```

**Implementation**: Red-Black Tree  
**All Operations**: O(log n)  
**Ordering**: Sorted  

**Advantages**:
✅ Automatic sorting  
✅ Unique elements  
✅ Range queries  
✅ Set operations (union, intersection)  

**When to Use**:
- Need unique sorted elements
- Need set operations
- Need range queries

**Variants**:
- `multiset`: Allows duplicates

---

## 3️⃣ UNORDERED CONTAINERS (Hash-Based)

### UNORDERED_MAP (Key-Value, Unordered)
```cpp
#include <unordered_map>
unordered_map<int, string> um = {{1, "one"}};
```

**Implementation**: Hash table  
**Average**: O(1)  
**Worst**: O(n)  
**Ordering**: None  

**Advantages**:
✅ Fastest lookup/insert (average)  
✅ Best for large datasets  

**Disadvantages**:
❌ No ordering  
❌ No range queries  
❌ Worst case O(n)  
❌ Higher memory overhead  

**When to Use**:
- Don't need order
- Need O(1) operations
- Frequency counting
- Caching

**Variants**:
- `unordered_multimap`: Allows duplicate keys

---

### UNORDERED_SET (Unique Elements, Unordered)
```cpp
#include <unordered_set>
unordered_set<int> us = {1, 2, 3};
```

**Implementation**: Hash table  
**Average**: O(1)  
**Worst**: O(n)  

**When to Use**:
- Need unique elements
- Don't need order
- Fast lookup critical

**Variants**:
- `unordered_multiset`: Allows duplicates

---

## 4️⃣ CONTAINER ADAPTERS

### STACK (LIFO)
```cpp
#include <stack>
stack<int> st;
st.push(10);
int top = st.top();
st.pop();
```

**Implementation**: Uses deque by default  
**Operations**: O(1)  

**When to Use**:
- DFS traversal
- Expression evaluation
- Undo/Redo
- Backtracking

---

### QUEUE (FIFO)
```cpp
#include <queue>
queue<int> q;
q.push(10);
int front = q.front();
q.pop();
```

**Implementation**: Uses deque by default  
**Operations**: O(1)  

**When to Use**:
- BFS traversal
- Task scheduling
- Level order traversal

---

### PRIORITY_QUEUE (Heap)
```cpp
#include <queue>
priority_queue<int> pq;  // Max heap
priority_queue<int, vector<int>, greater<int>> minPQ;  // Min heap
```

**Implementation**: Heap (vector-based)  
**Insert/Delete**: O(log n)  
**Top**: O(1)  

**When to Use**:
- Kth largest/smallest
- Dijkstra's algorithm
- Merge K sorted lists
- Top K elements

---

## 5️⃣ UTILITY

### PAIR
```cpp
#include <utility>
pair<int, string> p = {1, "one"};
auto [first, second] = p;  // C++17
```

**When to Use**:
- Return 2 values
- Coordinates
- Key-value pairs

---

### TUPLE
```cpp
#include <tuple>
tuple<int, string, double> t = {1, "one", 1.1};
auto [a, b, c] = t;  // C++17
```

**When to Use**:
- Return 3+ values
- Heterogeneous data
- Temporary grouping

---

## 📊 COMPLETE COMPARISON TABLE

| Container | Access | Insert | Delete | Search | Ordered | Duplicates | Memory |
|-----------|--------|--------|--------|--------|---------|------------|--------|
| **vector** | O(1) | O(n) | O(n) | O(n) | ❌ | ✅ | Low |
| **list** | O(n) | O(1)* | O(1)* | O(n) | ❌ | ✅ | High |
| **deque** | O(1) | O(1)** | O(1)** | O(n) | ❌ | ✅ | Medium |
| **array** | O(1) | N/A | N/A | O(n) | ❌ | ✅ | Lowest |
| **map** | O(log n) | O(log n) | O(log n) | O(log n) | ✅ | ❌ | Medium |
| **set** | O(log n) | O(log n) | O(log n) | O(log n) | ✅ | ❌ | Medium |
| **unordered_map** | O(1) avg | O(1) avg | O(1) avg | O(1) avg | ❌ | ❌ | High |
| **unordered_set** | O(1) avg | O(1) avg | O(1) avg | O(1) avg | ❌ | ❌ | High |
| **multimap** | O(log n) | O(log n) | O(log n) | O(log n) | ✅ | ✅ | Medium |
| **multiset** | O(log n) | O(log n) | O(log n) | O(log n) | ✅ | ✅ | Medium |
| **stack** | O(1)*** | O(1) | O(1) | N/A | ❌ | ✅ | Low |
| **queue** | O(1)*** | O(1) | O(1) | N/A | ❌ | ✅ | Low |
| **priority_queue** | O(1)*** | O(log n) | O(log n) | N/A | Partial | ✅ | Low |

*With iterator  
**At ends only  
***Top/front only  

---

## 🌳 DECISION TREE

```
Need key-value pairs?
├─ Yes → Need order?
│  ├─ Yes → map
│  └─ No → unordered_map
│
└─ No → Need unique elements?
   ├─ Yes → Need order?
   │  ├─ Yes → set
   │  └─ No → unordered_set
   │
   └─ No → Need LIFO?
      ├─ Yes → stack
      │
      └─ No → Need FIFO?
         ├─ Yes → queue
         │
         └─ No → Need priority?
            ├─ Yes → priority_queue
            │
            └─ No → Need random access?
               ├─ Yes → Need push/pop both ends?
               │  ├─ Yes → deque
               │  └─ No → vector
               │
               └─ No → Frequent middle insert/delete?
                  ├─ Yes → list
                  └─ No → vector
```

---

## 💡 INTERVIEW QUESTIONS & ANSWERS

### Q1: Vector vs List?
**Answer**:
| Feature | Vector | List |
|---------|--------|------|
| Access | O(1) | O(n) |
| Insert/Delete | O(n) | O(1) with iterator |
| Memory | Contiguous | Non-contiguous |
| Cache | Friendly | Unfriendly |
| **Use** | Default choice | Frequent middle ops |

### Q2: Map vs Unordered_map?
**Answer**:
| Feature | map | unordered_map |
|---------|-----|---------------|
| Order | Sorted | None |
| Search | O(log n) | O(1) avg |
| Range query | Yes | No |
| **Use** | Need order | Need speed |

### Q3: When to use deque?
**Answer**:
- Need push/pop at **both ends**
- Sliding window problems
- BFS (better than queue for some cases)

### Q4: Set vs Unordered_set?
**Answer**:
- **set**: Need sorted, range queries, O(log n)
- **unordered_set**: Need O(1), don't need order

### Q5: How does priority_queue work?
**Answer**:
- Implemented as **heap** (max heap by default)
- Insert/Delete: O(log n)
- Top: O(1)
- Use for Kth largest, Dijkstra, etc.

### Q6: Difference between emplace and insert?
**Answer**:
- **insert**: Constructs object, then copies/moves
- **emplace**: Constructs in-place (faster, no copy)

### Q7: What is iterator invalidation?
**Answer**:
- **vector**: Invalidated on reallocation or erase
- **list**: Only erased iterator invalidated
- **map/set**: Only erased iterator invalidated

### Q8: Custom comparator for set?
**Answer**:
```cpp
struct Compare {
    bool operator()(int a, int b) const {
        return a > b;  // Descending
    }
};
set<int, Compare> s;
```

### Q9: How to iterate and erase?
**Answer**:
```cpp
for (auto it = v.begin(); it != v.end(); ) {
    if (condition) {
        it = v.erase(it);  // Returns next iterator
    } else {
        ++it;
    }
}
```

### Q10: Pair vs Tuple?
**Answer**:
- **pair**: Exactly 2 elements, `.first/.second`
- **tuple**: 0+ elements, `get<N>()`
- Use pair for 2, tuple for 3+

---

## ⏱️ TIME COMPLEXITY CHEAT SHEET

### Sequence Containers
```
vector:  Access O(1), Insert O(n), Delete O(n)
list:    Access O(n), Insert O(1)*, Delete O(1)*
deque:   Access O(1), Insert O(1)**, Delete O(1)**
```

### Associative Containers
```
map/set:           All O(log n)
unordered_map/set: All O(1) average, O(n) worst
```

### Adapters
```
stack/queue:       All O(1)
priority_queue:    Insert/Delete O(log n), Top O(1)
```

---

## 🎯 COMMON INTERVIEW PATTERNS

### 1. Frequency Counter
```cpp
unordered_map<char, int> freq;
for (char c : str) freq[c]++;
```

### 2. Two Sum
```cpp
unordered_map<int, int> seen;
for (int i = 0; i < nums.size(); i++) {
    if (seen.count(target - nums[i]))
        return {seen[target - nums[i]], i};
    seen[nums[i]] = i;
}
```

### 3. Sliding Window Maximum
```cpp
deque<int> dq;  // Store indices
// Maintain decreasing order
```

### 4. Top K Elements
```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
// Keep size k
```

### 5. LRU Cache
```cpp
list<int> cache;
unordered_map<int, list<int>::iterator> map;
```

---

## ✅ SUMMARY

### Default Choices
- **General purpose**: `vector`
- **Key-value (fast)**: `unordered_map`
- **Key-value (sorted)**: `map`
- **Unique elements (fast)**: `unordered_set`
- **Unique elements (sorted)**: `set`
- **LIFO**: `stack`
- **FIFO**: `queue`
- **Priority**: `priority_queue`

### Remember
1. **vector** is default
2. **unordered_** for speed
3. **ordered** for sorting
4. **multi** for duplicates
5. **deque** for both ends
6. **list** for middle ops

---

*Master STL for interview success! 🚀*
