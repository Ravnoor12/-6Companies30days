#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string matrixChainOrder(int p[], int n){
        vector<vector<pair<int,string>>> dp(n-1,vector<pair<int,string>>(n-1));
        for(int i=0;i<n-1;i++){
            string temp ="";
            char a = 'A' +i;
            temp += a;
            dp[i][i] = {0,temp};
        }
        for(int g = 1;g<=n;g++){
            for(int i=0,j=g;j<n-1;i++,j++){
                dp[i][j].first = INT_MAX;
                 for(int k=i;k<j;k++){
                      int lc = dp[i][k].first;
                      int rc = dp[k+1][j].first;
                      int mc = p[i]*p[k+1]*p[j+1];
                      int tc = lc + rc + mc;
                      if(dp[i][j].first > tc){
                          dp[i][j].second = "(" + dp[i][k].second + dp[k+1][j].second + ")";
                          dp[i][j].first = tc;
                      }
                 }
            }
            
        }
        return dp[0][n-2].second;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}