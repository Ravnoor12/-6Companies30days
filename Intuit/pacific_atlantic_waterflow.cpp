#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void dfs(int row,int col,int prev,vector<vector<int>>&h,vector<vector<bool>>&ocean)   {
       int n = h.size();
       int m = h[0].size();
       if(row<0 || row>=n || col<0 || col>=m || prev>h[row][col]) return;
       if(ocean[row][col]) return;
       ocean[row][col] =1;
       dfs(row+1,col,h[row][col],h,ocean);
       dfs(row-1,col,h[row][col],h,ocean);
       dfs(row,col+1,h[row][col],h,ocean);
       dfs(row,col-1,h[row][col],h,ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>>pacific(n, vector<bool>(m,false));
        vector<vector<bool>>atlantic(n, vector<bool>(m,false));
        for(int i=0;i<n;i++){
            dfs(i,0,heights[i][0],heights,pacific);
            dfs(i,m-1,heights[i][m-1],heights,atlantic);
        }
        for(int i=0;i<m;i++){
            dfs(0,i,heights[0][i],heights,pacific);
            dfs(n-1,i,heights[n-1][i],heights,atlantic);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});  
                }
            }
        }
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> nums(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>nums[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.pacificAtlantic(nums);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}