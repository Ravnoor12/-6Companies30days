#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isvalid(vector<int>piles,int h,int maxcap){
       int hr = 0;
        for(auto i:piles){
            hr += ceil((double)i/maxcap);
        }
        return hr<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start=1;
        int end=0;
        for(int i=0;i<n;i++){
            end = max(end,piles[i]);
        }
        int ans = end;
        while(end>=start){
           int mid = start + (end-start)/2;
            if(isvalid(piles,h,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int h;
        cin>>h;
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        Solution obj;
        cout<<obj.minEatingSpeed(nums,h);
    }
    return 0;
}