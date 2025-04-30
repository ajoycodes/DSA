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

bool checkODD(int n){
    return ((n|1)==n);
}

bool checkEven(int n){
    return ((n|1)!=n);
}


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

int getIthBit(int n, int i){
    return (n>>2) & 1;
}

void setIthBit(int n, int i){
    n = n | (1<<i);
    cout<<"After Set bit: "<<n<<endl;
}

int clearIthBit(int n, int i){
    return n & ~(1<<i);
}

void updateIthBit(int n, int i, int v){
    n =  n | (1<<i);
    n = clearIthBit(n, v);
    cout<<"After Update bit: "<<n<<endl;
}

int clearRangeOfBits(int n, int i, int j){
    int a= (~0) << (j+1);
    int b = (1<<i) -1;

    int mask = a | b;
    return n & mask;
}

bool checkPowTwo(int n){
    return (n& (n-1))==0;
}

int countSetBits(int n){
    int cnt =0;
    while(n!=0){
        if((n&1) ==1) cnt++;
        n = n>>1;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout<<fastExponentiation(2.0, 10)<<endl; // Output: 1024
    cout<<fastExponentiation(2.0, -2)<<endl; // Output: 0.25
    cout<<checkODD(5)<<endl; // Output: 1 (true)
    cout<<checkEven(9)<<endl; // Output: 1 (true)
    cout<<getIthBit(5, 2)<<endl; // Output: 1 (true)
    setIthBit(5, 1); // Output: After Set bit: 7
    cout<<clearIthBit(5, 2)<<endl; // Output: 1 (true)
    updateIthBit(5, 1, 2); // Output: After Update bit: 1
    cout<<clearRangeOfBits(15, 1, 2)<<endl; // Output: 9 (1001 in binary)
    cout<<checkPowTwo(8)<<endl; // Output: 1 (true)
    cout<<countSetBits(7)<<endl; // Output: 3 (111 in binary)
    

    return 0;
}