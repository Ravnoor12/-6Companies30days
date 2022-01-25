#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     bool ans = 0;
     int direcx[4] = {-1,1,0,0};
     int direcy[4] = {0,0,-1,1};
        
    bool isvalid(int i,int j,int n,int m,vector<vector<bool>>&vis,int idx,string word,vector<vector<char>> &board){
       if( (i>=0) && (j>=0) && (i<n) && (j<m) && !vis[i][j] && (idx<word.size() )&& (board[i][j]==word[idx]) ){
            return 1;   
       } 
       return 0;
    }
    void dfs(vector<vector<char>>&board,vector<vector<bool>>&vis,int i,int j,int idx,int n,int m,string word){
        if(idx>=word.size()){
            ans =1;
            return;
        }
        for(int k=0;k<4;k++){
           if(isvalid(i+direcx[k],j+direcy[k],n,m,vis,idx,word,board)){
                vis[i+direcx[k]][j+direcy[k]]=1;
             dfs(board,vis,i+direcx[k],j+direcy[k],idx+1,n,m,word);
            }
        }
         vis[i][j]=false;
        return ;     
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
         int n = board.size();
         int m = board[0].size();
         vector<vector<bool>>vis(n,vector<bool>(m,0));
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(word[0]==board[i][j] ){
                    vis[i][j]=1;
                    if(word.size()>1)
                        dfs(board,vis,i,j,1,n,m,word);
                    else 
                       return true;
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
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}