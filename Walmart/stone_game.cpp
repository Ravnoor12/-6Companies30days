#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp (n,vector<int>(n));
	    for(int g=0;g<n;g++){
	        for(int i=0,j=g;j<n;i++,j++){
	            if(g==0) dp[i][j] = piles[i];
	            else if(g==1){
	                dp[i][j] = max(piles[i],piles[j]);
	            }
	            else{
	                int val1 = piles[i] + min(dp[i+2][j],dp[i+1][j-1]);
	                int val2 = piles[j] + min(dp[i][j-2],dp[i+1][j-1]);
	                dp[i][j] = max(val1,val2);
	            }
	        }
	    }
	    return dp[0][n-1];
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        Solution obj;
        cout<<obj.stoneGame(nums)<<endl;
    }
}