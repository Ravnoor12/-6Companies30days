#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minInsAndDel(int A[], int B[], int N, int M) {
        unordered_set<int> st;
        for(int i = 0; i < M; i++) 
            st.insert(B[i]);
        vector<int> lis;
        for(int i = 0; i < N; i++) {
            if(st.find(A[i])!=st.end()){
                auto it = lower_bound(lis.begin(),lis.end(),A[i]);
                if(it==lis.end()){
                    lis.push_back(A[i]);
                }
                else{
                    *it = A[i];
                }
            }
        }
        return (N - lis.size()) + (M-lis.size());
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];
        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}