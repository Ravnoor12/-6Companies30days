#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int currNode ,  vector<bool> &visited ,vector<vector<int>>& isConnected ){
        visited[currNode]=1;
        vector<int>currNeighbours = isConnected[currNode];
        for( int i=0; i < currNeighbours.size() ; i++ ){
            if(currNeighbours[i] == 1 && visited[i] == 0 )
                dfs(i , visited , isConnected);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n = isConnected.size();
        int ans =0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
               ans++; 
                dfs(i,vis,isConnected);
            }
        }
        return ans;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> nums(n,vector<int>(n));
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>nums[i][j];
            }
        }
        Solution obj;
        cout<<obj.findCircleNum(nums)<<endl;
    }
    return 0;
}