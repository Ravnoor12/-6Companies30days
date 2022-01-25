#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isvalid(vector<int>weights,int maxcap,int days){
        int d = 1;
        int sum = 0; 
        for(int i=0;i<weights.size();i++){
            sum+= weights[i];
            if(d>days) return false;
            if(sum>maxcap) i--;
            if(sum>=maxcap){
                sum = 0;
                d++;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MAX,high;
        int sum = 0;
        for(int i=0;i<weights.size();i++){
            sum+= weights[i];
            low = min(low,weights[i]);
        }
        high = sum;
        int mid;
        int ans = 0;
        while(high>=low){
            mid = low + (high-low)/2;
            if(isvalid(weights,mid,days)) {
                ans = mid;
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
        int days;
        cin>>days;
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        Solution obj;
        cout<<obj.shipWithinDays(nums,days);
    }
  return 0;   
}