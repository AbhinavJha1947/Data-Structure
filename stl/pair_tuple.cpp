#include <iostream>
#include <utility>  // pair
#include <tuple>    // tuple
#include <vector>
#include <algorithm>
using namespace std;

// ========================================
// PAIR AND TUPLE
// ========================================

int main() {
    cout << "=== STL PAIR AND TUPLE ===" << endl;
    
    // ========================================
    // PAIR
    // ========================================
    
    cout << "\n=== PAIR ===" << endl;
    
    // Declaration and initialization
    pair<int, string> p1;
    pair<int, string> p2(1, "one");
    pair<int, string> p3 = {2, "two"};
    pair<int, string> p4 = make_pair(3, "three");
    
    // Access elements
    cout << "p2.first = " << p2.first << endl;
    cout << "p2.second = " << p2.second << endl;
    
    // Modify elements
    p2.first = 10;
    p2.second = "ten";
    
    // Comparison (lexicographic)
    pair<int, int> a = {1, 2};
    pair<int, int> b = {1, 3};
    cout << "a < b: " << (a < b ? "true" : "false") << endl;
    
    // Swap
    pair<int, int> x = {1, 2};
    pair<int, int> y = {3, 4};
    x.swap(y);
    cout << "After swap, x = {" << x.first << ", " << x.second << "}" << endl;
    
    // ========================================
    // PAIR WITH CONTAINERS
    // ========================================
    
    cout << "\n=== PAIR WITH CONTAINERS ===" << endl;
    
    // Vector of pairs
    vector<pair<int, string>> vec = {{1, "one"}, {2, "two"}, {3, "three"}};
    
    cout << "Vector of pairs: ";
    for (auto& p : vec) {
        cout << "{" << p.first << ":" << p.second << "} ";
    }
    cout << endl;
    
    // Sort by first element (default)
    sort(vec.begin(), vec.end());
    
    // Sort by second element
    sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    });
    
    // ========================================
    // COMMON PAIR PATTERNS
    // ========================================
    
    cout << "\n=== COMMON PAIR PATTERNS ===" << endl;
    
    // 1. Return multiple values
    auto divMod = [](int a, int b) -> pair<int, int> {
        return {a / b, a % b};
    };
    
    auto [quotient, remainder] = divMod(17, 5);  // C++17 structured binding
    cout << "17 / 5 = " << quotient << " remainder " << remainder << endl;
    
    // 2. Store coordinates
    vector<pair<int, int>> points = {{1, 2}, {3, 4}, {5, 6}};
    
    // 3. Store key-value temporarily
    vector<pair<string, int>> scores = {{"Alice", 95}, {"Bob", 87}, {"Charlie", 92}};
    
    // Sort by score (descending)
    sort(scores.begin(), scores.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });
    
    cout << "Sorted scores: ";
    for (auto& [name, score] : scores) {
        cout << name << ":" << score << " ";
    }
    cout << endl;
    
    // 4. Graph edges
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 4}};
    
    // ========================================
    // TUPLE
    // ========================================
    
    cout << "\n=== TUPLE ===" << endl;
    
    // Declaration and initialization
    tuple<int, string, double> t1;
    tuple<int, string, double> t2(1, "one", 1.1);
    tuple<int, string, double> t3 = {2, "two", 2.2};
    tuple<int, string, double> t4 = make_tuple(3, "three", 3.3);
    
    // Access elements using get<>
    cout << "t2: " << get<0>(t2) << ", " << get<1>(t2) << ", " << get<2>(t2) << endl;
    
    // Modify elements
    get<0>(t2) = 10;
    get<1>(t2) = "ten";
    get<2>(t2) = 10.10;
    
    // C++17 structured binding
    auto [num, str, dbl] = t2;
    cout << "Structured binding: " << num << ", " << str << ", " << dbl << endl;
    
    // tuple_size
    cout << "Tuple size: " << tuple_size<decltype(t2)>::value << endl;
    
    // ========================================
    // TUPLE OPERATIONS
    // ========================================
    
    cout << "\n=== TUPLE OPERATIONS ===" << endl;
    
    // tie - Create tuple of references
    int a_val;
    string b_val;
    double c_val;
    
    tie(a_val, b_val, c_val) = t2;
    cout << "Using tie: " << a_val << ", " << b_val << ", " << c_val << endl;
    
    // ignore - Ignore specific elements
    tie(a_val, ignore, c_val) = t2;
    
    // Comparison (lexicographic)
    tuple<int, int> ta = {1, 2};
    tuple<int, int> tb = {1, 3};
    cout << "ta < tb: " << (ta < tb ? "true" : "false") << endl;
    
    // Swap
    tuple<int, string> tx = {1, "one"};
    tuple<int, string> ty = {2, "two"};
    tx.swap(ty);
    cout << "After swap, tx = {" << get<0>(tx) << ", " << get<1>(tx) << "}" << endl;
    
    // tuple_cat - Concatenate tuples
    tuple<int, string> t_a = {1, "one"};
    tuple<double, char> t_b = {1.1, 'A'};
    auto t_cat = tuple_cat(t_a, t_b);
    cout << "Concatenated: " << get<0>(t_cat) << ", " << get<1>(t_cat) << ", " 
         << get<2>(t_cat) << ", " << get<3>(t_cat) << endl;
    
    // ========================================
    // TUPLE WITH CONTAINERS
    // ========================================
    
    cout << "\n=== TUPLE WITH CONTAINERS ===" << endl;
    
    // Vector of tuples
    vector<tuple<int, string, double>> students = {
        {1, "Alice", 95.5},
        {2, "Bob", 87.3},
        {3, "Charlie", 92.1}
    };
    
    cout << "Students: " << endl;
    for (auto& [id, name, score] : students) {
        cout << id << ": " << name << " - " << score << endl;
    }
    
    // Sort by score (descending)
    sort(students.begin(), students.end(), [](auto& a, auto& b) {
        return get<2>(a) > get<2>(b);
    });
    
    // ========================================
    // COMMON TUPLE PATTERNS
    // ========================================
    
    cout << "\n=== COMMON TUPLE PATTERNS ===" << endl;
    
    // 1. Return multiple values
    auto getStats = [](vector<int>& nums) -> tuple<int, int, double> {
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        double avg = 0;
        for (int x : nums) avg += x;
        avg /= nums.size();
        return {minVal, maxVal, avg};
    };
    
    vector<int> data = {1, 2, 3, 4, 5};
    auto [minV, maxV, avgV] = getStats(data);
    cout << "Stats: min=" << minV << ", max=" << maxV << ", avg=" << avgV << endl;
    
    // 2. Store heterogeneous data
    vector<tuple<string, int, double, bool>> records = {
        {"Alice", 25, 50000.0, true},
        {"Bob", 30, 60000.0, false}
    };
    
    // 3. Multiple sorting criteria
    vector<tuple<int, int, int>> items = {{1, 5, 10}, {1, 3, 20}, {2, 5, 15}};
    sort(items.begin(), items.end());  // Sorts by all elements lexicographically
    
    // ========================================
    // PAIR VS TUPLE
    // ========================================
    
    cout << "\n=== PAIR VS TUPLE ===" << endl;
    cout << "Feature        | pair        | tuple" << endl;
    cout << "---------------|-------------|-------------" << endl;
    cout << "Elements       | 2           | 0 or more" << endl;
    cout << "Access         | .first/.second | get<N>()" << endl;
    cout << "Structured bind| Yes (C++17) | Yes (C++17)" << endl;
    cout << "Use case       | 2 elements  | 3+ elements" << endl;
    
    // ========================================
    // WHEN TO USE
    // ========================================
    
    cout << "\n=== WHEN TO USE ===" << endl;
    
    cout << "\nUse PAIR when:" << endl;
    cout << "✓ Need exactly 2 elements" << endl;
    cout << "✓ Coordinates (x, y)" << endl;
    cout << "✓ Key-value pairs" << endl;
    cout << "✓ Return 2 values from function" << endl;
    
    cout << "\nUse TUPLE when:" << endl;
    cout << "✓ Need 3+ elements" << endl;
    cout << "✓ Return multiple values" << endl;
    cout << "✓ Store heterogeneous data" << endl;
    cout << "✓ Temporary grouping" << endl;
    
    cout << "\nAvoid when:" << endl;
    cout << "✗ Need named fields (use struct)" << endl;
    cout << "✗ Complex data (use class)" << endl;
    cout << "✗ Need methods (use class)" << endl;
    
    // ========================================
    // PRACTICAL EXAMPLES
    // ========================================
    
    cout << "\n=== PRACTICAL EXAMPLES ===" << endl;
    
    // Example 1: Interval merging
    vector<pair<int, int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    sort(intervals.begin(), intervals.end());
    
    vector<pair<int, int>> merged;
    for (auto& interval : intervals) {
        if (merged.empty() || merged.back().second < interval.first) {
            merged.push_back(interval);
        } else {
            merged.back().second = max(merged.back().second, interval.second);
        }
    }
    
    cout << "Merged intervals: ";
    for (auto& [start, end] : merged) {
        cout << "[" << start << "," << end << "] ";
    }
    cout << endl;
    
    // Example 2: Custom sorting with multiple criteria
    vector<tuple<string, int, double>> employees = {
        {"Alice", 30, 50000},
        {"Bob", 25, 60000},
        {"Charlie", 30, 55000}
    };
    
    // Sort by age, then by salary (descending)
    sort(employees.begin(), employees.end(), [](auto& a, auto& b) {
        if (get<1>(a) != get<1>(b)) {
            return get<1>(a) < get<1>(b);  // Age ascending
        }
        return get<2>(a) > get<2>(b);  // Salary descending
    });
    
    cout << "Sorted employees: " << endl;
    for (auto& [name, age, salary] : employees) {
        cout << name << " (age " << age << ", salary " << salary << ")" << endl;
    }
    
    return 0;
}
