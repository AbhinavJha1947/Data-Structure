#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ========================================
// VECTOR - DYNAMIC ARRAY
// ========================================
// Header: #include <vector>
// Declaration: vector<int> v;

int main() {
    cout << "=== STL VECTOR OPERATIONS ===" << endl;
    
    // ========================================
    // 1. INITIALIZATION
    // ========================================
    
    vector<int> v1;                          // Empty vector
    vector<int> v2(5);                       // 5 elements, default value 0
    vector<int> v3(5, 10);                   // 5 elements, all initialized to 10
    vector<int> v4 = {1, 2, 3, 4, 5};       // Initializer list
    vector<int> v5(v4);                      // Copy constructor
    
    cout << "\n1. Initialization:" << endl;
    cout << "v3 (5 elements with value 10): ";
    for (int x : v3) cout << x << " ";
    cout << endl;
    
    // ========================================
    // 2. ADDING ELEMENTS
    // ========================================
    
    vector<int> v;
    
    // push_back - Add at end - O(1) amortized
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    
    // emplace_back - Construct in place - O(1) amortized (faster than push_back)
    v.emplace_back(40);
    
    // insert - Insert at position - O(n)
    v.insert(v.begin() + 1, 15);              // Insert 15 at index 1
    v.insert(v.begin(), 5);                   // Insert 5 at beginning
    v.insert(v.end(), 50);                    // Insert 50 at end
    
    cout << "\n2. After adding elements: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    
    // ========================================
    // 3. ACCESSING ELEMENTS
    // ========================================
    
    cout << "\n3. Accessing elements:" << endl;
    
    // Using [] operator - No bounds checking
    cout << "v[0] = " << v[0] << endl;
    
    // Using at() - With bounds checking (throws exception)
    cout << "v.at(2) = " << v.at(2) << endl;
    
    // front() - First element
    cout << "v.front() = " << v.front() << endl;
    
    // back() - Last element
    cout << "v.back() = " << v.back() << endl;
    
    // data() - Pointer to underlying array
    int* ptr = v.data();
    cout << "First element via data(): " << *ptr << endl;
    
    // ========================================
    // 4. REMOVING ELEMENTS
    // ========================================
    
    // pop_back - Remove last element - O(1)
    v.pop_back();
    
    // erase - Remove at position - O(n)
    v.erase(v.begin() + 1);                   // Remove element at index 1
    
    // erase range
    // v.erase(v.begin(), v.begin() + 2);     // Remove first 2 elements
    
    // clear - Remove all elements - O(n)
    // v.clear();
    
    cout << "\n4. After removing elements: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    
    // ========================================
    // 5. SIZE AND CAPACITY
    // ========================================
    
    cout << "\n5. Size and Capacity:" << endl;
    
    // size() - Number of elements
    cout << "Size: " << v.size() << endl;
    
    // capacity() - Allocated storage
    cout << "Capacity: " << v.capacity() << endl;
    
    // empty() - Check if empty
    cout << "Is empty: " << (v.empty() ? "Yes" : "No") << endl;
    
    // max_size() - Maximum possible size
    cout << "Max size: " << v.max_size() << endl;
    
    // reserve() - Reserve capacity
    v.reserve(100);
    cout << "After reserve(100), capacity: " << v.capacity() << endl;
    
    // shrink_to_fit() - Reduce capacity to size
    v.shrink_to_fit();
    cout << "After shrink_to_fit(), capacity: " << v.capacity() << endl;
    
    // resize() - Change size
    v.resize(10, 100);  // Resize to 10, new elements = 100
    cout << "After resize(10, 100): ";
    for (int x : v) cout << x << " ";
    cout << endl;
    
    // ========================================
    // 6. ITERATORS
    // ========================================
    
    cout << "\n6. Iterators:" << endl;
    
    // begin() and end()
    cout << "Using iterators: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // rbegin() and rend() - Reverse iterators
    cout << "Reverse iteration: ";
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // ========================================
    // 7. MODIFIERS
    // ========================================
    
    vector<int> v6 = {1, 2, 3};
    vector<int> v7 = {4, 5, 6};
    
    // assign - Replace contents
    v6.assign(5, 10);  // 5 elements with value 10
    
    // swap - Swap contents
    v6.swap(v7);
    
    cout << "\n7. After swap, v6: ";
    for (int x : v6) cout << x << " ";
    cout << endl;
    
    // ========================================
    // 8. ALGORITHMS WITH VECTOR
    // ========================================
    
    vector<int> nums = {5, 2, 8, 1, 9, 3, 7};
    
    cout << "\n8. Algorithms:" << endl;
    cout << "Original: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    
    // sort - O(n log n)
    sort(nums.begin(), nums.end());
    cout << "After sort: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    
    // reverse
    reverse(nums.begin(), nums.end());
    cout << "After reverse: ";
    for (int x : nums) cout << x << " ";
    cout << endl;
    
    // binary_search - O(log n) - requires sorted array
    sort(nums.begin(), nums.end());
    bool found = binary_search(nums.begin(), nums.end(), 5);
    cout << "Binary search for 5: " << (found ? "Found" : "Not found") << endl;
    
    // lower_bound - First element >= value
    auto lb = lower_bound(nums.begin(), nums.end(), 5);
    cout << "Lower bound of 5: index " << (lb - nums.begin()) << endl;
    
    // upper_bound - First element > value
    auto ub = upper_bound(nums.begin(), nums.end(), 5);
    cout << "Upper bound of 5: index " << (ub - nums.begin()) << endl;
    
    // find - O(n)
    auto it = find(nums.begin(), nums.end(), 7);
    if (it != nums.end()) {
        cout << "Found 7 at index: " << (it - nums.begin()) << endl;
    }
    
    // count
    int cnt = count(nums.begin(), nums.end(), 5);
    cout << "Count of 5: " << cnt << endl;
    
    // min_element and max_element
    auto minIt = min_element(nums.begin(), nums.end());
    auto maxIt = max_element(nums.begin(), nums.end());
    cout << "Min: " << *minIt << ", Max: " << *maxIt << endl;
    
    // accumulate (need #include <numeric>)
    // int sum = accumulate(nums.begin(), nums.end(), 0);
    
    // ========================================
    // 9. 2D VECTOR
    // ========================================
    
    cout << "\n9. 2D Vector:" << endl;
    
    // Declaration
    vector<vector<int>> matrix(3, vector<int>(4, 0));  // 3x4 matrix
    
    // Initialize
    matrix[0][0] = 1;
    matrix[1][2] = 5;
    
    // Print
    cout << "Matrix:" << endl;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // Jagged array (different column sizes)
    vector<vector<int>> jagged;
    jagged.push_back({1, 2});
    jagged.push_back({3, 4, 5});
    jagged.push_back({6});
    
    // ========================================
    // 10. COMMON PATTERNS
    // ========================================
    
    cout << "\n10. Common Patterns:" << endl;
    
    // Remove duplicates (sorted)
    vector<int> dup = {1, 1, 2, 2, 3, 4, 4, 5};
    auto last = unique(dup.begin(), dup.end());
    dup.erase(last, dup.end());
    cout << "After removing duplicates: ";
    for (int x : dup) cout << x << " ";
    cout << endl;
    
    // Rotate
    vector<int> rot = {1, 2, 3, 4, 5};
    rotate(rot.begin(), rot.begin() + 2, rot.end());  // Rotate left by 2
    cout << "After rotate: ";
    for (int x : rot) cout << x << " ";
    cout << endl;
    
    // Partition
    vector<int> part = {1, 2, 3, 4, 5, 6};
    partition(part.begin(), part.end(), [](int x) { return x % 2 == 0; });
    cout << "After partition (even first): ";
    for (int x : part) cout << x << " ";
    cout << endl;
    
    // ========================================
    // 11. PERFORMANCE TIPS
    // ========================================
    
    cout << "\n11. Performance Tips:" << endl;
    cout << "- Use reserve() if you know size beforehand" << endl;
    cout << "- Use emplace_back() instead of push_back() for objects" << endl;
    cout << "- Avoid frequent insert/erase in middle (O(n))" << endl;
    cout << "- Use shrink_to_fit() to free unused memory" << endl;
    cout << "- Pass by reference to avoid copying" << endl;
    
    // ========================================
    // 12. TIME COMPLEXITIES
    // ========================================
    
    cout << "\n12. Time Complexities:" << endl;
    cout << "Access ([]): O(1)" << endl;
    cout << "push_back: O(1) amortized" << endl;
    cout << "pop_back: O(1)" << endl;
    cout << "insert: O(n)" << endl;
    cout << "erase: O(n)" << endl;
    cout << "find: O(n)" << endl;
    cout << "sort: O(n log n)" << endl;
    
    return 0;
}
