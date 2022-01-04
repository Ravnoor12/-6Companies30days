#include<iostream>
using namespace std;

class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        long long int ans = N*(N+1)*(2*N +1)/6;
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        Solution obj;
        cout<<obj.squaresInChessBoard(n)<<endl;
    }
    return 0;
}