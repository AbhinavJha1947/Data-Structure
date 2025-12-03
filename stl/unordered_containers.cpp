#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

// ========================================
// UNORDERED_MAP - HASH TABLE (KEY-VALUE)
// ========================================
// Header: #include <unordered_map>
// Implementation: Hash Table
// Average O(1) operations

int main() {
    cout << "=== STL UNORDERED CONTAINERS ===" << endl;
    
    // ========================================
    // UNORDERED_MAP
    // ========================================
    
    cout << "\n=== UNORDERED_MAP ===" << endl;
    
    unordered_map<int, string> um;
    
    // Insert - O(1) average
    um[1] = "one";
    um[2] = "two";
    um.insert({3, "three"});
    um.emplace(4, "four");
    
    cout << "Unordered map (no specific order): ";
    for (auto& [key, val] : um) {
        cout << "{" << key << ":" << val << "} ";
    }
    cout << endl;
    
    // Access - O(1) average
    cout << "um[2] = " << um[2] << endl;
    
    // Find - O(1) average
    if (um.find(3) != um.end()) {
        cout << "Found key 3" << endl;
    }
    
    // Count - O(1) average
    cout << "Count of 1: " << um.count(1) << endl;
    
    // Erase - O(1) average
    um.erase(4);
    
    // Size
    cout << "Size: " << um.size() << endl;
    
    // Bucket information
    cout << "Bucket count: " << um.bucket_count() << endl;
    cout << "Load factor: " << um.load_factor() << endl;
    cout << "Max load factor: " << um.max_load_factor() << endl;
    
    // Reserve space
    um.reserve(100);  // Reserve for 100 elements
    
    // ========================================
    // UNORDERED_SET
    // ========================================
    
    cout << "\n=== UNORDERED_SET ===" << endl;
    
    unordered_set<int> us;
    
    // Insert - O(1) average
    us.insert(10);
    us.insert(20);
    us.insert(30);
    us.insert(10);  // Duplicate ignored
    us.emplace(40);
    
    cout << "Unordered set (no specific order): ";
    for (int x : us) {
        cout << x << " ";
    }
    cout << endl;
    
    // Find - O(1) average
    if (us.find(20) != us.end()) {
        cout << "Found 20" << endl;
    }
    
    // Count - O(1) average
    cout << "Count of 30: " << us.count(30) << endl;
    
    // Erase - O(1) average
    us.erase(40);
    
    // Size
    cout << "Size: " << us.size() << endl;
    
    // ========================================
    // UNORDERED_MULTIMAP
    // ========================================
    
    cout << "\n=== UNORDERED_MULTIMAP (allows duplicate keys) ===" << endl;
    
    unordered_multimap<int, string> umm;
    umm.insert({1, "one"});
    umm.insert({1, "uno"});
    umm.insert({2, "two"});
    umm.insert({2, "dos"});
    
    cout << "Unordered multimap: ";
    for (auto& [key, val] : umm) {
        cout << "{" << key << ":" << val << "} ";
    }
    cout << endl;
    
    // Count occurrences
    cout << "Count of key 1: " << umm.count(1) << endl;
    
    // Find all values for a key
    auto range = umm.equal_range(1);
    cout << "All values for key 1: ";
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->second << " ";
    }
    cout << endl;
    
    // ========================================
    // UNORDERED_MULTISET
    // ========================================
    
    cout << "\n=== UNORDERED_MULTISET (allows duplicates) ===" << endl;
    
    unordered_multiset<int> ums = {5, 2, 8, 2, 9, 5, 1};
    
    cout << "Unordered multiset: ";
    for (int x : ums) {
        cout << x << " ";
    }
    cout << endl;
    
    // Count occurrences
    cout << "Count of 5: " << ums.count(5) << endl;
    
    // Erase all occurrences
    ums.erase(5);
    cout << "After erasing all 5s: ";
    for (int x : ums) {
        cout << x << " ";
    }
    cout << endl;
    
    // ========================================
    // CUSTOM HASH FUNCTION
    // ========================================
    
    cout << "\n=== CUSTOM HASH FUNCTION ===" << endl;
    
    // For custom types, need custom hash
    struct Point {
        int x, y;
        bool operator==(const Point& other) const {
            return x == other.x && y == other.y;
        }
    };
    
    struct PointHash {
        size_t operator()(const Point& p) const {
            return hash<int>()(p.x) ^ (hash<int>()(p.y) << 1);
        }
    };
    
    unordered_set<Point, PointHash> points;
    points.insert({1, 2});
    points.insert({3, 4});
    
    cout << "Custom hash set size: " << points.size() << endl;
    
    // ========================================
    // COMMON PATTERNS
    // ========================================
    
    cout << "\n=== COMMON PATTERNS ===" << endl;
    
    // 1. Frequency counter
    string text = "hello world";
    unordered_map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }
    cout << "Character frequency: ";
    for (auto& [ch, count] : freq) {
        cout << ch << ":" << count << " ";
    }
    cout << endl;
    
    // 2. Two Sum problem
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    unordered_map<int, int> seen;
    
    cout << "Two Sum (target=" << target << "): ";
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (seen.find(complement) != seen.end()) {
            cout << "indices " << seen[complement] << " and " << i << endl;
            break;
        }
        seen[nums[i]] = i;
    }
    
    // 3. Remove duplicates
    vector<int> arr = {1, 2, 2, 3, 4, 4, 5};
    unordered_set<int> unique(arr.begin(), arr.end());
    arr.assign(unique.begin(), unique.end());
    cout << "After removing duplicates: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    // 4. Check if arrays have common element
    vector<int> a1 = {1, 2, 3};
    vector<int> a2 = {4, 5, 3};
    unordered_set<int> set1(a1.begin(), a1.end());
    bool hasCommon = false;
    for (int x : a2) {
        if (set1.count(x)) {
            hasCommon = true;
            break;
        }
    }
    cout << "Arrays have common element: " << (hasCommon ? "Yes" : "No") << endl;
    
    // ========================================
    // PERFORMANCE TUNING
    // ========================================
    
    cout << "\n=== PERFORMANCE TUNING ===" << endl;
    
    unordered_map<int, int> perfMap;
    
    // Reserve buckets if size known
    perfMap.reserve(1000);
    
    // Set max load factor (default 1.0)
    perfMap.max_load_factor(0.75);
    
    // Rehash to specific bucket count
    perfMap.rehash(100);
    
    cout << "Bucket count: " << perfMap.bucket_count() << endl;
    cout << "Max load factor: " << perfMap.max_load_factor() << endl;
    
    // ========================================
    // WHEN TO USE UNORDERED CONTAINERS
    // ========================================
    
    cout << "\n=== WHEN TO USE ===" << endl;
    cout << "✓ Need O(1) average operations" << endl;
    cout << "✓ Don't need sorted order" << endl;
    cout << "✓ Don't need range queries" << endl;
    cout << "✗ Need sorted iteration (use map/set)" << endl;
    cout << "✗ Need lower_bound/upper_bound (use map/set)" << endl;
    cout << "✗ Worst case O(n) unacceptable (use map/set)" << endl;
    
    // ========================================
    // ORDERED VS UNORDERED
    // ========================================
    
    cout << "\n=== ORDERED VS UNORDERED ===" << endl;
    cout << "Feature        | map/set     | unordered_map/set" << endl;
    cout << "---------------|-------------|-------------------" << endl;
    cout << "Ordering       | Sorted      | No order" << endl;
    cout << "Implementation | Red-Black   | Hash table" << endl;
    cout << "Search         | O(log n)    | O(1) avg, O(n) worst" << endl;
    cout << "Insert         | O(log n)    | O(1) avg, O(n) worst" << endl;
    cout << "Delete         | O(log n)    | O(1) avg, O(n) worst" << endl;
    cout << "Range query    | Yes         | No" << endl;
    cout << "Memory         | Lower       | Higher (buckets)" << endl;
    cout << "Cache          | Better      | Worse" << endl;
    
    // ========================================
    // TIME COMPLEXITIES
    // ========================================
    
    cout << "\n=== TIME COMPLEXITIES ===" << endl;
    cout << "Insert: O(1) average, O(n) worst" << endl;
    cout << "Erase: O(1) average, O(n) worst" << endl;
    cout << "Find: O(1) average, O(n) worst" << endl;
    cout << "Count: O(1) average, O(n) worst" << endl;
    cout << "Note: Worst case when many hash collisions" << endl;
    
    return 0;
}
