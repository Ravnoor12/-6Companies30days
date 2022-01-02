#include<iostream>
#define ull unsigned long long
using namespace std;
class Solution{
public:	
	ull getNthUglyNo(int n) {
	    ull dp[n];
	    int f2 = 0;
	    int f3 =0;
	    int f5 =0;
	    dp[0]=1;
	    for(int i=1;i<n;i++){
	        ull num2 = 2*dp[f2];
	        ull num3 = 3*dp[f3];
	        ull num5 = 5*dp[f5];
            ull minnum = min(num2,min(num3,num5));
            dp[i]=minnum;
            if(minnum==num2) f2++;
            if(minnum==num3) f3++;
            if(minnum==num5) f5++;
	    }
	    return dp[n-1];
	    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Solution obj;
        ull ans = obj.getNthUglyNo(n);
        cout<<ans<<endl;
    }
    return 0;
}
