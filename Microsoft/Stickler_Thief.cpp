#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
    public:
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n);
        dp[0] = arr[0];
        dp[1] = max(dp[0],arr[1]);
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1], arr[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}