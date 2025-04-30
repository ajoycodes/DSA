#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int c = a & b;
            a = a ^ b;
            b = (unsigned int)c << 1;
        }
        return a;
    }
};

int main() {
    Solution sol;
    int a = 5, b = 3;
    cout << "Sum of " << a << " and " << b << " is: " << sol.getSum(a, b) << endl;

    return 0;
}
