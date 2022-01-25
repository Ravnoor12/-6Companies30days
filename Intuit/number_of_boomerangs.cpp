#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getdist(int i1,int i2,int j1,int j2){
        int x = pow((j1-i1),2);
        int y = pow((j2-i2),2);
        return (x+y);
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mp;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int dist = getdist(points[i][0],points[i][1],points[j][0],points[j][1]);
                if(mp.find(dist)!=mp.end()){
                    ans += mp[dist];
                }
                mp[dist]++;
            }
        }
        return ans*2;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> nums(n,vector<int>(2));
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                cin>>nums[i][j];
            }
        }
        Solution obj;
        cout<<obj.numberOfBoomerangs(nums)<<endl;
    }
    return 0;
}