#include<iostream>
using namespace std;

// First approach, it was also accepted
/*class Solution {
  public:
    int findPosition(int N , int M , int K) {
        int pos=K;
        int i=1;
        while(i<M){
            if(pos==N) pos=1;
            else
            pos++;
            i++;
        }
        return pos;
    }
};*/

class Solution {
  public:
    int findPosition(int N , int M , int K) {
        if (M <= N - K + 1)
        return M + K - 1;
         M = M - (N - K + 1);
         if(M%N==0) return N;
         else{
             return M%N;
         }
    }
};    
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        Solution obj;
        cout<<obj.findPosition(n,m,k)<<endl;;
    }
    return 0;
}