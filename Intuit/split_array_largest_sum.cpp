#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool valid(vector<int>nums, int m,int maxcap){
        int j = 1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i];
            if(sum>maxcap){
                sum = nums[i];
                j++;
            }
        } 
        return j<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        int maxnum = 0;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i];
            maxnum = max(maxnum,nums[i]);
        }
        int ans = INT_MAX;
        int low = maxnum;
        int high = sum;
        while(high>=low){
            int mid = low + (high-low)/2;
            if(valid(nums,m,mid)){
                ans = min(ans,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int m;
        cin>>m;
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        Solution obj;
        cout<<obj.splitArray(nums,m)<<endl;
    }
    return 0;
}