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

double fastExponentiation(double base, int exponent) {
    if (exponent == 0) return 1;
    if (exponent < 0) {
        base = 1 / base;
        exponent = -exponent;
    }
    double result = 1;
    while (exponent > 0) {
        if((exponent&1)!=0){
            result *= base;
        }
        base *= base;
        exponent >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout<<fastExponentiation(2.0, 10)<<endl; // Output: 1024
    cout<<fastExponentiation(2.0, -2)<<endl; // Output: 0.25

    

    return 0;
}