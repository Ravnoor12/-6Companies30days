#include<bits/stdc++.h> 
using namespace std; 

#define mod (long long int) (1e9 +7)
class Solution
{
  
  public:
    int kvowelwords(int N, int K) {
         vector<vector<long long>> dp(N+1,vector<long long> (K+1,0)) ;
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=K;++j)
            {
                if(i==0) {
                    dp[i][j] = 1 ;
                }
                else  {
                    dp[i][j] = (dp[i-1][K] * 21) % mod ;
                    
                    if(j>0) {
                        dp[i][j] = (dp[i][j] + dp[i-1][j-1] *5 % mod) % mod ;
                    }
                }
            }
        }
        return dp[N][K] ;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}