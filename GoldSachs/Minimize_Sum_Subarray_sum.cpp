#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int len = 0;
        int i=0,j=0;
        int sum=nums[j];
        while(j<n && j>=i){
            if(sum>=target){
                len = j-i+1;
                ans =  min(len,ans);
                sum-= nums[i];
                i++;
            }
            else{
                j++;
                if(j==n) break;
                sum+= nums[j];
            }
        }
           if(ans==INT_MAX) ans = 0;
        return ans;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        int n;// No of elements
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        Solution obj;
        cout<<obj.minSubArrayLen(target,v)<<endl;        
    }
    return 0;
}