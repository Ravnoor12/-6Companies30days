#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]) q.push({i,j});
            }
        }
        if(q.size()==0 || q.size()==n*n) return -1;
        int x[] = {-1,1,0,0};
        int y[] = {0,0,-1,1};
        int ans= 0;     //level    
        while(!q.empty()){
            int t = q.size();
            while(t--){
                auto [i,j] = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int x1 = i+x[k];
                    int y1 = j + y[k];
                    if(x1>=0 && y1<n && x1<n && y1>=0 && grid[x1][y1]==0){
                        grid[x1][y1] = 1;
                        q.push({x1,y1});
                    }
                }
            }
            ans++;
        }
            return ans-1;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
         vector<vector<int>>nums(n,vector<int>(n));
            for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>nums[i][j];
            }
        }
        Solution obj;
        cout<<obj.maxDistance(nums)<<endl;
    }
    return 0;
}