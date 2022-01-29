#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    if (dividend == INT_MIN && divisor == 1) return INT_MIN;
    if (divisor == INT_MIN) return dividend == INT_MIN;
    int a = abs(dividend), b = abs(divisor), res = 0, n = 0;
    if (dividend == INT_MIN){
        res = 1;
        a = abs(dividend + b);
    }
    while (a >= b){
        while ((b<<n) <= INT_MAX/2 && a >= (b<<n)) ++n;
        if (a < (b<<n)) --n;
        a -= b<<n;
        res += 1<<n;
        n = 0;
    }
    return (dividend >= 0) == (divisor >= 0)?res:-res;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        Solution obj;
        cout<<obj.divide(a,b)<<endl;
    }
    return 0;
}