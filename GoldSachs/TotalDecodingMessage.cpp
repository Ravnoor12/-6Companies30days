#include<iostream>
using namespace std;

class Solution{
	public:
		int CountWays(string str){
		    int n = str.size();
		    int mod = 1e9 + 7;
		    int dp[n+1];
		    dp[0] = 1;
		    dp[1] = 1;
            if(str[0]=='0')
                return 0;
		    for(int i=2;i<=n;i++){
		        dp[i]=0;
		       if(str[i-1]>'0') dp[i] = dp[i-1];
		       if( str[i-2]=='1' || (str[i-2]=='2') && str[i-1]<'7'){
		           dp[i] += (dp[i-2]);
		       }
		       dp[i] = dp[i]%mod;
	 	     }
	 	     return dp[n];
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.CountWays(s)<<endl;
    }
    return 0;
}