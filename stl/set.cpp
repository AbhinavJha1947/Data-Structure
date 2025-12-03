#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

// ========================================
// SET - ORDERED UNIQUE ELEMENTS
// ========================================
// Header: #include <set>
// Declaration: set<Type> s;
// Implementation: Red-Black Tree (self-balancing BST)

int main() {
    cout << "=== STL SET OPERATIONS ===" << endl;
    
    // ========================================
    // 1. INITIALIZATION
    // ========================================
    
    set<int> s1;                           // Empty set
    set<int> s2 = {5, 2, 8, 1, 9};        // Initializer list (auto-sorted)
    set<int> s3(s2);                       // Copy constructor
    set<int> s4(s2.begin(), s2.end());    // Range constructor
    
    cout << "\n1. Initialization (auto-sorted):" << endl;
    cout << "s2: ";
    for (int x : s2) cout << x << " ";
    cout << endl;
    
    // ========================================
    // 2. INSERTING ELEMENTS
    // ========================================
    
    set<int> s;
    
    // insert - O(log n) - Returns pair<iterator, bool>
    auto result1 = s.insert(10);
    cout << "\n2. Insert 10: " << (result1.second ? "Success" : "Failed") << endl;
    
    auto result2 = s.insert(10);  // Duplicate
    cout << "Insert 10 again: " << (result2.second ? "Success" : "Failed (duplicate)") << endl;
    
    s.insert(20);
    s.insert(5);
    s.insert(15);
    s.insert(25);
    
    // insert with hint - O(1) if hint is correct
    auto hint = s.find(15);
    s.insert(hint, 17);
    
    // insert range
    int arr[] = {30, 35, 40};
    s.insert(arr, arr + 3);
    
    // emplace - O(log n) - Construct in place
    s.emplace(12);
    
    cout << "After inserting: ";
    for (int x : s) cout << x << " ";
    cout << endl;
    
    // ========================================
    // 3. SEARCHING ELEMENTS
    // ========================================
    
    cout << "\n3. Searching:" << endl;
    
    // find - O(log n) - Returns iterator
    auto it = s.find(15);
    if (it != s.end()) {
        cout << "Found 15" << endl;
    }
    
    // count - O(log n) - Returns 0 or 1
    if (s.count(20)) {
        cout << "20 exists" << endl;
    }
    
    // contains - C++20 - O(log n)
    // if (s.contains(25)) { ... }
    
    // ========================================
    // 4. REMOVING ELEMENTS
    // ========================================
    
    // erase by value - O(log n)
    s.erase(30);
    
    // erase by iterator - O(1) amortized
    auto eraseIt = s.find(35);
    if (eraseIt != s.end()) {
        s.erase(eraseIt);
    }
    
    // erase range - O(n)
    // s.erase(s.begin(), s.end());
    
    // clear - O(n)
    // s.clear();
    
    cout << "\n4. After erasing: ";
    for (int x : s) cout << x << " ";
    cout << endl;
    
    // ========================================
    // 5. SIZE
    // ========================================
    
    cout << "\n5. Size:" << endl;
    cout << "Size: " << s.size() << endl;
    cout << "Is empty: " << (s.empty() ? "Yes" : "No") << endl;
    cout << "Max size: " << s.max_size() << endl;
    
    // ========================================
    // 6. ITERATORS
    // ========================================
    
    cout << "\n6. Iterators (always sorted):" << endl;
    
    // Forward iteration
    cout << "Forward: ";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Reverse iteration
    cout << "Reverse: ";
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // ========================================
    // 7. BOUNDS AND RANGE
    // ========================================
    
    set<int> nums = {1, 3, 5, 7, 9, 11, 13, 15};
    
    cout << "\n7. Bounds:" << endl;
    
    // lower_bound - First element >= value - O(log n)
    auto lb = nums.lower_bound(6);
    if (lb != nums.end()) {
        cout << "Lower bound of 6: " << *lb << endl;
    }
    
    // upper_bound - First element > value - O(log n)
    auto ub = nums.upper_bound(7);
    if (ub != nums.end()) {
        cout << "Upper bound of 7: " << *ub << endl;
    }
    
    // equal_range - Returns pair [lower_bound, upper_bound)
    auto range = nums.equal_range(7);
    cout << "Equal range of 7: ";
    for (auto it = range.first; it != range.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Print range [5, 11]
    cout << "Elements in range [5, 11]: ";
    auto start = nums.lower_bound(5);
    auto end = nums.upper_bound(11);
    for (auto it = start; it != end; ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // ========================================
    // 8. SET OPERATIONS
    // ========================================
    
    set<int> a = {1, 2, 3, 4, 5};
    set<int> b = {4, 5, 6, 7, 8};
    
    cout << "\n8. Set operations:" << endl;
    cout << "Set A: ";
    for (int x : a) cout << x << " ";
    cout << endl;
    
    cout << "Set B: ";
    for (int x : b) cout << x << " ";
    cout << endl;
    
    // Union - O(n)
    set<int> unionSet;
    set_union(a.begin(), a.end(), b.begin(), b.end(), 
              inserter(unionSet, unionSet.begin()));
    cout << "Union: ";
    for (int x : unionSet) cout << x << " ";
    cout << endl;
    
    // Intersection - O(n)
    set<int> intersectionSet;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(),
                     inserter(intersectionSet, intersectionSet.begin()));
    cout << "Intersection: ";
    for (int x : intersectionSet) cout << x << " ";
    cout << endl;
    
    // Difference (A - B) - O(n)
    set<int> differenceSet;
    set_difference(a.begin(), a.end(), b.begin(), b.end(),
                   inserter(differenceSet, differenceSet.begin()));
    cout << "Difference (A-B): ";
    for (int x : differenceSet) cout << x << " ";
    cout << endl;
    
    // Symmetric Difference - O(n)
    set<int> symDiffSet;
    set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(),
                             inserter(symDiffSet, symDiffSet.begin()));
    cout << "Symmetric Difference: ";
    for (int x : symDiffSet) cout << x << " ";
    cout << endl;
    
    // ========================================
    // 9. CUSTOM COMPARATOR
    // ========================================
    
    cout << "\n9. Custom comparator (descending):" << endl;
    
    // Descending order
    set<int, greater<int>> descSet = {5, 2, 8, 1, 9};
    
    cout << "Descending set: ";
    for (int x : descSet) cout << x << " ";
    cout << endl;
    
    // Custom comparator for strings by length
    struct CompareLength {
        bool operator()(const string& a, const string& b) const {
            return a.length() < b.length();
        }
    };
    
    set<string, CompareLength> strSet = {"apple", "hi", "banana", "cat"};
    cout << "Strings by length: ";
    for (const string& s : strSet) cout << s << " ";
    cout << endl;
    
    // ========================================
    // 10. MULTISET (ALLOWS DUPLICATES)
    // ========================================
    
    cout << "\n10. Multiset (allows duplicates):" << endl;
    
    multiset<int> ms = {5, 2, 8, 2, 9, 5, 1};
    
    cout << "Multiset: ";
    for (int x : ms) cout << x << " ";
    cout << endl;
    
    // count - Returns number of occurrences
    cout << "Count of 5: " << ms.count(5) << endl;
    
    // erase all occurrences
    ms.erase(5);  // Removes all 5s
    cout << "After erasing all 5s: ";
    for (int x : ms) cout << x << " ";
    cout << endl;
    
    // erase single occurrence
    ms.insert(2);
    ms.insert(2);
    auto msIt = ms.find(2);
    ms.erase(msIt);  // Removes only one 2
    cout << "After erasing one 2: ";
    for (int x : ms) cout << x << " ";
    cout << endl;
    
    // ========================================
    // 11. COMMON PATTERNS
    // ========================================
    
    cout << "\n11. Common patterns:" << endl;
    
    // Remove duplicates from vector
    vector<int> vec = {5, 2, 8, 2, 9, 5, 1};
    set<int> uniqueSet(vec.begin(), vec.end());
    vec.assign(uniqueSet.begin(), uniqueSet.end());
    cout << "Vector after removing duplicates: ";
    for (int x : vec) cout << x << " ";
    cout << endl;
    
    // Find kth smallest (0-indexed)
    set<int> data = {10, 5, 15, 3, 20};
    int k = 2;
    auto kthIt = data.begin();
    advance(kthIt, k);
    cout << k << "th smallest: " << *kthIt << endl;
    
    // Check if subset
    set<int> subset = {2, 3};
    set<int> superset = {1, 2, 3, 4, 5};
    bool isSubset = includes(superset.begin(), superset.end(),
                             subset.begin(), subset.end());
    cout << "Is subset: " << (isSubset ? "Yes" : "No") << endl;
    
    // ========================================
    // 12. WHEN TO USE SET
    // ========================================
    
    cout << "\n12. When to use set:" << endl;
    cout << "✓ Need unique elements" << endl;
    cout << "✓ Need sorted order" << endl;
    cout << "✓ Need range queries" << endl;
    cout << "✓ Need set operations (union, intersection)" << endl;
    cout << "✗ Don't need order (use unordered_set)" << endl;
    cout << "✗ Need duplicates (use multiset)" << endl;
    cout << "✗ Need key-value pairs (use map)" << endl;
    
    // ========================================
    // 13. SET VS UNORDERED_SET
    // ========================================
    
    cout << "\n13. Set vs Unordered_set:" << endl;
    cout << "Feature        | set         | unordered_set" << endl;
    cout << "---------------|-------------|---------------" << endl;
    cout << "Ordering       | Sorted      | No order" << endl;
    cout << "Implementation | Red-Black   | Hash table" << endl;
    cout << "Search         | O(log n)    | O(1) avg" << endl;
    cout << "Insert         | O(log n)    | O(1) avg" << endl;
    cout << "Delete         | O(log n)    | O(1) avg" << endl;
    cout << "Range query    | Yes         | No" << endl;
    cout << "Memory         | Lower       | Higher" << endl;
    
    // ========================================
    // 14. TIME COMPLEXITIES
    // ========================================
    
    cout << "\n14. Time Complexities:" << endl;
    cout << "Insert: O(log n)" << endl;
    cout << "Erase: O(log n)" << endl;
    cout << "Find: O(log n)" << endl;
    cout << "Count: O(log n)" << endl;
    cout << "Lower/Upper bound: O(log n)" << endl;
    cout << "Set operations: O(n)" << endl;
    
    return 0;
}
