#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
         int n = nums.size();
         unordered_map<int,int> mp;
         if(n%2!=0) return false;
          for(int i=0;i<n;i++){
            mp[nums[i] % k]++;
        }
        for(int i=0;i<n;i++){
            int r1 = nums[i]%k;
            if(r1==0){
                if(mp[r1]%2!=0) return false;
            }
            else{
              int r2 = k - r1;
              if(r1==r2 && mp[r2]%2!=0) return false;
              if(mp.find(r2)==mp.end()) return false;
              if(mp[r1]!=mp[r2]) return false;
            }
        }
        return true;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        Solution obj;
        bool ans = obj.canPair(v,k);
        if(ans) cout<<"True"<<endl;
        else {
            cout<<"False"<<endl;
        }
    }
    return 0;
}