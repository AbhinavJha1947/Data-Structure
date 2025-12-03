#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

// ========================================
// LIST - DOUBLY LINKED LIST
// ========================================
// Header: #include <list>
// Declaration: list<int> l;

int main() {
    cout << "=== STL LIST OPERATIONS ===" << endl;
    
    // ========================================
    // 1. INITIALIZATION
    // ========================================
    
    list<int> l1;                           // Empty list
    list<int> l2(5);                        // 5 elements, default value 0
    list<int> l3(5, 10);                    // 5 elements, all initialized to 10
    list<int> l4 = {1, 2, 3, 4, 5};        // Initializer list
    list<int> l5(l4);                       // Copy constructor
    
    cout << "\n1. Initialization:" << endl;
    cout << "l3 (5 elements with value 10): ";
    for (int x : l3) cout << x << " ";
    cout << endl;
    
    // ========================================
    // 2. ADDING ELEMENTS
    // ========================================
    
    list<int> l;
    
    // push_back - Add at end - O(1)
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    
    // push_front - Add at beginning - O(1)
    l.push_front(5);
    l.push_front(1);
    
    // emplace_back - Construct at end - O(1)
    l.emplace_back(40);
    
    // emplace_front - Construct at beginning - O(1)
    l.emplace_front(0);
    
    // insert - Insert at position - O(1) if iterator given
    auto it = l.begin();
    advance(it, 3);  // Move iterator 3 positions
    l.insert(it, 15);
    
    cout << "\n2. After adding elements: ";
    for (int x : l) cout << x << " ";
    cout << endl;
    
    // ========================================
    // 3. ACCESSING ELEMENTS
    // ========================================
    
    cout << "\n3. Accessing elements:" << endl;
    
    // front() - First element - O(1)
    cout << "l.front() = " << l.front() << endl;
    
    // back() - Last element - O(1)
    cout << "l.back() = " << l.back() << endl;
    
    // Note: No [] or at() operator (no random access)
    // Must use iterators to access middle elements
    
    // ========================================
    // 4. REMOVING ELEMENTS
    // ========================================
    
    // pop_back - Remove last element - O(1)
    l.pop_back();
    
    // pop_front - Remove first element - O(1)
    l.pop_front();
    
    // erase - Remove at position - O(1)
    auto eraseIt = l.begin();
    advance(eraseIt, 2);
    l.erase(eraseIt);
    
    // erase range - O(n)
    // l.erase(l.begin(), l.end());
    
    // remove - Remove all occurrences of value - O(n)
    l.push_back(10);
    l.push_back(10);
    l.remove(10);  // Removes all 10s
    
    // remove_if - Remove based on condition - O(n)
    l.remove_if([](int x) { return x % 2 == 0; });  // Remove even numbers
    
    cout << "\n4. After removing elements: ";
    for (int x : l) cout << x << " ";
    cout << endl;
    
    // ========================================
    // 5. SIZE
    // ========================================
    
    cout << "\n5. Size:" << endl;
    
    // size() - Number of elements - O(1)
    cout << "Size: " << l.size() << endl;
    
    // empty() - Check if empty - O(1)
    cout << "Is empty: " << (l.empty() ? "Yes" : "No") << endl;
    
    // max_size() - Maximum possible size
    cout << "Max size: " << l.max_size() << endl;
    
    // resize() - Change size
    l.resize(10, 100);  // Resize to 10, new elements = 100
    
    // clear() - Remove all elements - O(n)
    // l.clear();
    
    // ========================================
    // 6. ITERATORS
    // ========================================
    
    cout << "\n6. Iterators:" << endl;
    
    // begin() and end()
    cout << "Forward iteration: ";
    for (auto it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // rbegin() and rend() - Reverse iterators
    cout << "Reverse iteration: ";
    for (auto it = l.rbegin(); it != l.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // ========================================
    // 7. MODIFIERS
    // ========================================
    
    list<int> l6 = {1, 2, 3};
    list<int> l7 = {4, 5, 6};
    
    // assign - Replace contents
    l6.assign(5, 10);  // 5 elements with value 10
    
    // swap - Swap contents - O(1)
    l6.swap(l7);
    
    cout << "\n7. After swap, l6: ";
    for (int x : l6) cout << x << " ";
    cout << endl;
    
    // ========================================
    // 8. LIST-SPECIFIC OPERATIONS
    // ========================================
    
    list<int> nums = {5, 2, 8, 1, 9, 3, 7, 2, 5};
    
    cout << "\n8. List-specific operations:" << endl;
    cout << "Original: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    
    // sort - O(n log n) - Uses merge sort
    nums.sort();
    cout << "After sort: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    
    // sort with custom comparator
    nums.sort(greater<int>());  // Descending order
    cout << "After sort (descending): ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    
    // reverse - O(n)
    nums.reverse();
    cout << "After reverse: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    
    // unique - Remove consecutive duplicates - O(n)
    // Must be sorted first
    nums.sort();
    nums.unique();
    cout << "After unique: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    
    // ========================================
    // 9. SPLICE - TRANSFER ELEMENTS
    // ========================================
    
    list<int> l8 = {1, 2, 3};
    list<int> l9 = {4, 5, 6};
    
    cout << "\n9. Splice operations:" << endl;
    
    // splice - Transfer all elements from l9 to l8
    auto pos = l8.begin();
    advance(pos, 1);  // Position after first element
    l8.splice(pos, l9);  // O(1) or O(n) depending on implementation
    
    cout << "After splice, l8: ";
    for (int x : l8) cout << x << " ";
    cout << endl;
    
    cout << "After splice, l9: ";
    for (int x : l9) cout << x << " ";
    cout << " (empty)" << endl;
    
    // ========================================
    // 10. MERGE - MERGE SORTED LISTS
    // ========================================
    
    list<int> l10 = {1, 3, 5};
    list<int> l11 = {2, 4, 6};
    
    cout << "\n10. Merge:" << endl;
    
    // merge - Merge two sorted lists - O(n)
    l10.merge(l11);
    
    cout << "After merge, l10: ";
    for (int x : l10) cout << x << " ";
    cout << endl;
    
    // ========================================
    // 11. ALGORITHMS WITH LIST
    // ========================================
    
    list<int> data = {5, 2, 8, 1, 9};
    
    cout << "\n11. Algorithms:" << endl;
    
    // find - O(n)
    auto findIt = find(data.begin(), data.end(), 8);
    if (findIt != data.end()) {
        cout << "Found 8" << endl;
    }
    
    // count - O(n)
    int cnt = count(data.begin(), data.end(), 5);
    cout << "Count of 5: " << cnt << endl;
    
    // min_element and max_element - O(n)
    auto minIt = min_element(data.begin(), data.end());
    auto maxIt = max_element(data.begin(), data.end());
    cout << "Min: " << *minIt << ", Max: " << *maxIt << endl;
    
    // for_each
    cout << "For each (doubled): ";
    for_each(data.begin(), data.end(), [](int& x) { x *= 2; });
    for (int x : data) cout << x << " ";
    cout << endl;
    
    // ========================================
    // 12. WHEN TO USE LIST
    // ========================================
    
    cout << "\n12. When to use list:" << endl;
    cout << "✓ Frequent insertions/deletions in middle" << endl;
    cout << "✓ Need O(1) insert/delete at known position" << endl;
    cout << "✓ Need splice operation" << endl;
    cout << "✗ Need random access (use vector)" << endl;
    cout << "✗ Memory overhead (pointers)" << endl;
    cout << "✗ Cache unfriendly (non-contiguous)" << endl;
    
    // ========================================
    // 13. LIST VS VECTOR
    // ========================================
    
    cout << "\n13. List vs Vector:" << endl;
    cout << "Operation      | List    | Vector" << endl;
    cout << "---------------|---------|--------" << endl;
    cout << "Random Access  | O(n)    | O(1)" << endl;
    cout << "Insert Front   | O(1)    | O(n)" << endl;
    cout << "Insert Back    | O(1)    | O(1)" << endl;
    cout << "Insert Middle  | O(1)*   | O(n)" << endl;
    cout << "Delete Front   | O(1)    | O(n)" << endl;
    cout << "Delete Back    | O(1)    | O(1)" << endl;
    cout << "Delete Middle  | O(1)*   | O(n)" << endl;
    cout << "Memory         | Higher  | Lower" << endl;
    cout << "Cache          | Poor    | Good" << endl;
    cout << "*If iterator is known" << endl;
    
    // ========================================
    // 14. TIME COMPLEXITIES
    // ========================================
    
    cout << "\n14. Time Complexities:" << endl;
    cout << "Access: O(n)" << endl;
    cout << "push_front/push_back: O(1)" << endl;
    cout << "pop_front/pop_back: O(1)" << endl;
    cout << "insert (with iterator): O(1)" << endl;
    cout << "erase (with iterator): O(1)" << endl;
    cout << "remove: O(n)" << endl;
    cout << "sort: O(n log n)" << endl;
    cout << "reverse: O(n)" << endl;
    cout << "unique: O(n)" << endl;
    cout << "merge: O(n)" << endl;
    
    return 0;
}
