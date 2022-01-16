#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> subarraySum(int arr[], int n, long long s)
    {
       vector<int> ans;
       int i=0;
       int j=0;
       long long sum = arr[j];
       while(j<n){
           if(sum==s){
               ans.push_back(i+1);
               ans.push_back(j+1);
               return ans;
           }
           else if(sum<s){
               j++;
               sum += arr[j];
           }
           else if(sum>s){
               sum -= arr[i];
               i++;
           }
       }
       ans.push_back(-1);
       return ans;
    }
};

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
 }