#include<bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(vector<int>adj[],vector<bool>&vis,int d){
        if(!vis[d]){
            vis[d] = 1;
            for(auto i:adj[d]){
                if(!vis[i]){
                    dfs(adj,vis,i);
                }
            }
        }
    }
	public:
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        adj[c].erase(find(adj[c].begin(),adj[c].end(),d));
        adj[d].erase(find(adj[d].begin(),adj[d].end(),c));
        vector<bool>vis(V,false);
        dfs(adj,vis,d);
        return !vis[c];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        int c,d;
        cin>>c>>d;   
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }
    return 0;
}