#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0;i<N;i++){
            sum += arr[i];
        }
        if(sum%2!=0) return 0;
        vector<vector<int>> dp((sum/2)+1,vector<int>(N+1,0));
        for (int i = 0; i <= N; i++){
            dp[0][i] = 1;
        }
        for(int i=1;i<=sum/2;i++){
            for(int j=1;j<=N;j++){
                dp[i][j] = dp[i][j-1];
                if(dp[i][j]!=1 && i>=arr[j-1]){
                    dp[i][j] = dp[i-arr[j-1]][j-1];
                }
            }
        }
        return dp[sum/2][N];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}