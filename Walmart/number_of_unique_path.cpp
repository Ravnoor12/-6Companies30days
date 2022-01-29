#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int NumberOfPath(int a, int b)
    {
        vector <vector<int>> dp(a+1 , vector<int> (b+1, 1));
        for(int i=1; i<=a; i++){
            for(int j=1; j<=b; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[a-1][b-1];
        
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        Solution ob;
        cout << ob.NumberOfPath(a,b) << endl;
    }
}