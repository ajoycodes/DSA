#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a = 5, b = 10;
    
    cout << "Before swapping: a = " << a << ", b = " << b << endl;
    a = a^b;
    b = a^b;
    a = a^b;
    cout << "After swapping: a = " << a << ", b = " << b << endl;
    // Output: a = 10, b = 5
    // Explanation:
    // 1. a = a^b; (a becomes 15)       
    // 2. b = a^b; (b becomes 5)   
    // 3. a = a^b; (a becomes 10)
    // This method uses XOR to swap two numbers without using a temporary variable.


    return 0;
}