#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool valid(vector<vector<bool>>&vis,vector<vector<int>>&grid,int r,int c,int n,int m){
        if((r>=0) && (r<n) && (c>=0) && (c<m) && (grid[r][c] && !vis[r][c])) return 1;
        return 0;
    }
    void dfs(vector<vector<bool>>&vis,int &count,vector<vector<int>>&grid,int i,int j,int n,int m){
        vis[i][j]=1;
        static int rows[] = {-1,-1,-1,0,0,1,1,1};
        static int cols[] = {-1,0,1,1,-1,-1,0,1};
        for(int k=0;k<8;k++){
           int r = i+rows[k],c=j+cols[k];
            if(valid(vis,grid,r,c,n,m)){
                count++;
                dfs(vis,count,grid,r,c,n,m);
            }
        }
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MIN;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j]){
                    int count = 1;
                    dfs(vis,count,grid,i,j,n,m);
                    ans = max(count,ans);
                }
            }
        }
        return ans;
    }
};
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}