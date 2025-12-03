#include <iostream>
#include <map>
#include <string>
using namespace std;

// ========================================
// MAP - ORDERED KEY-VALUE PAIRS
// ========================================
// Header: #include <map>
// Declaration: map<KeyType, ValueType> m;
// Implementation: Red-Black Tree (self-balancing BST)

int main() {
    cout << "=== STL MAP OPERATIONS ===" << endl;
    
    // ========================================
    // 1. INITIALIZATION
    // ========================================
    
    map<int, string> m1;                                    // Empty map
    map<int, string> m2 = {{1, "one"}, {2, "two"}};        // Initializer list
    map<int, string> m3(m2);                                // Copy constructor
    
    cout << "\n1. Initialization:" << endl;
    cout << "m2: ";
    for (auto& pair : m2) {
        cout << "{" << pair.first << ":" << pair.second << "} ";
    }
    cout << endl;
    
    // ========================================
    // 2. INSERTING ELEMENTS
    // ========================================
    
    map<int, string> m;
    
    // Using [] operator - O(log n)
    m[1] = "one";
    m[2] = "two";
    m[3] = "three";
    
    // Using insert - O(log n)
    m.insert({4, "four"});
    m.insert(make_pair(5, "five"));
    m.insert(pair<int, string>(6, "six"));
    
    // Using emplace - O(log n) - constructs in place
    m.emplace(7, "seven");
    
    // insert with hint (iterator) - O(1) if hint is correct
    auto hint = m.find(5);
    m.insert(hint, {8, "eight"});
    
    cout << "\n2. After inserting: ";
    for (auto& p : m) {
        cout << "{" << p.first << ":" << p.second << "} ";
    }
    cout << endl;
    
    // ========================================
    // 3. ACCESSING ELEMENTS
    // ========================================
    
    cout << "\n3. Accessing elements:" << endl;
    
    // Using [] operator - Creates if doesn't exist
    cout << "m[2] = " << m[2] << endl;
    cout << "m[10] = " << m[10] << " (created with default value)" << endl;
    
    // Using at() - Throws exception if doesn't exist
    try {
        cout << "m.at(3) = " << m.at(3) << endl;
        // cout << m.at(100);  // Would throw exception
    } catch (const out_of_range& e) {
        cout << "Key not found!" << endl;
    }
    
    // Using find() - Returns iterator
    auto it = m.find(5);
    if (it != m.end()) {
        cout << "Found: {" << it->first << ":" << it->second << "}" << endl;
    }
    
    // ========================================
    // 4. CHECKING EXISTENCE
    // ========================================
    
    cout << "\n4. Checking existence:" << endl;
    
    // count() - Returns 0 or 1 for map - O(log n)
    if (m.count(3)) {
        cout << "Key 3 exists" << endl;
    }
    
    // find() - O(log n)
    if (m.find(100) == m.end()) {
        cout << "Key 100 does not exist" << endl;
    }
    
    // contains() - C++20 - O(log n)
    // if (m.contains(3)) { ... }
    
    // ========================================
    // 5. REMOVING ELEMENTS
    // ========================================
    
    // erase by key - O(log n)
    m.erase(10);  // Remove the default value we created
    
    // erase by iterator - O(1) amortized
    auto eraseIt = m.find(8);
    if (eraseIt != m.end()) {
        m.erase(eraseIt);
    }
    
    // erase range - O(n)
    // m.erase(m.begin(), m.end());
    
    // clear() - Remove all - O(n)
    // m.clear();
    
    cout << "\n5. After erasing: ";
    for (auto& p : m) {
        cout << "{" << p.first << ":" << p.second << "} ";
    }
    cout << endl;
    
    // ========================================
    // 6. SIZE
    // ========================================
    
    cout << "\n6. Size:" << endl;
    cout << "Size: " << m.size() << endl;
    cout << "Is empty: " << (m.empty() ? "Yes" : "No") << endl;
    cout << "Max size: " << m.max_size() << endl;
    
    // ========================================
    // 7. ITERATORS
    // ========================================
    
    cout << "\n7. Iterators (sorted by key):" << endl;
    
    // Forward iteration
    cout << "Forward: ";
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << "{" << it->first << ":" << it->second << "} ";
    }
    cout << endl;
    
    // Reverse iteration
    cout << "Reverse: ";
    for (auto it = m.rbegin(); it != m.rend(); ++it) {
        cout << "{" << it->first << ":" << it->second << "} ";
    }
    cout << endl;
    
    // Range-based for loop
    cout << "Range-based: ";
    for (const auto& [key, value] : m) {  // C++17 structured binding
        cout << "{" << key << ":" << value << "} ";
    }
    cout << endl;
    
    // ========================================
    // 8. BOUNDS AND RANGE
    // ========================================
    
    map<int, string> nums = {{1, "a"}, {3, "b"}, {5, "c"}, {7, "d"}, {9, "e"}};
    
    cout << "\n8. Bounds:" << endl;
    
    // lower_bound - First element >= key - O(log n)
    auto lb = nums.lower_bound(4);
    if (lb != nums.end()) {
        cout << "Lower bound of 4: {" << lb->first << ":" << lb->second << "}" << endl;
    }
    
    // upper_bound - First element > key - O(log n)
    auto ub = nums.upper_bound(5);
    if (ub != nums.end()) {
        cout << "Upper bound of 5: {" << ub->first << ":" << ub->second << "}" << endl;
    }
    
    // equal_range - Returns pair of iterators [lower_bound, upper_bound)
    auto range = nums.equal_range(5);
    cout << "Equal range of 5: ";
    for (auto it = range.first; it != range.second; ++it) {
        cout << "{" << it->first << ":" << it->second << "} ";
    }
    cout << endl;
    
    // ========================================
    // 9. CUSTOM COMPARATOR
    // ========================================
    
    cout << "\n9. Custom comparator (descending):" << endl;
    
    // Descending order
    map<int, string, greater<int>> descMap = {{1, "one"}, {2, "two"}, {3, "three"}};
    
    cout << "Descending map: ";
    for (auto& p : descMap) {
        cout << "{" << p.first << ":" << p.second << "} ";
    }
    cout << endl;
    
    // Custom comparator function
    struct CustomCompare {
        bool operator()(const int& a, const int& b) const {
            return a > b;  // Descending
        }
    };
    
    map<int, string, CustomCompare> customMap;
    customMap[1] = "one";
    customMap[2] = "two";
    
    // ========================================
    // 10. COMMON PATTERNS
    // ========================================
    
    cout << "\n10. Common patterns:" << endl;
    
    // Frequency counter
    string text = "hello world";
    map<char, int> freq;
    for (char c : text) {
        freq[c]++;  // Auto-creates with 0, then increments
    }
    
    cout << "Character frequency: ";
    for (auto& [ch, count] : freq) {
        cout << ch << ":" << count << " ";
    }
    cout << endl;
    
    // Check and insert
    map<int, int> cache;
    int key = 5;
    if (cache.find(key) == cache.end()) {
        cache[key] = 100;  // Insert only if not exists
    }
    
    // Update or insert
    cache[key] = 200;  // Updates if exists, inserts if not
    
    // ========================================
    // 11. MULTIMAP (ALLOWS DUPLICATES)
    // ========================================
    
    cout << "\n11. Multimap (allows duplicate keys):" << endl;
    
    multimap<int, string> mm;
    mm.insert({1, "one"});
    mm.insert({1, "uno"});
    mm.insert({2, "two"});
    mm.insert({2, "dos"});
    
    cout << "Multimap: ";
    for (auto& p : mm) {
        cout << "{" << p.first << ":" << p.second << "} ";
    }
    cout << endl;
    
    // Find all values for a key
    auto mmRange = mm.equal_range(1);
    cout << "All values for key 1: ";
    for (auto it = mmRange.first; it != mmRange.second; ++it) {
        cout << it->second << " ";
    }
    cout << endl;
    
    // ========================================
    // 12. WHEN TO USE MAP
    // ========================================
    
    cout << "\n12. When to use map:" << endl;
    cout << "✓ Need sorted key-value pairs" << endl;
    cout << "✓ Need range queries (lower_bound, upper_bound)" << endl;
    cout << "✓ Need ordered iteration" << endl;
    cout << "✗ Don't need order (use unordered_map - faster)" << endl;
    cout << "✗ Need duplicate keys (use multimap)" << endl;
    
    // ========================================
    // 13. MAP VS UNORDERED_MAP
    // ========================================
    
    cout << "\n13. Map vs Unordered_map:" << endl;
    cout << "Feature        | map         | unordered_map" << endl;
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
    cout << "Access ([], at): O(log n)" << endl;
    cout << "Insert: O(log n)" << endl;
    cout << "Erase: O(log n)" << endl;
    cout << "Find: O(log n)" << endl;
    cout << "Count: O(log n)" << endl;
    cout << "Lower/Upper bound: O(log n)" << endl;
    
    return 0;
}
