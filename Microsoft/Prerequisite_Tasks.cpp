#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool iscycle(int i,vector<int>adj[],vector<bool>&vis,vector<bool>&recstack){
        vis[i] = 1;
        recstack[i] =1;
        for(auto j:adj[i]){
            if(!vis[j] && iscycle(j,adj,vis,recstack)){
                return true;
            }
            else{
                if(recstack[j]) return true;
            }
        }
        recstack[i] = false;
        return false;
    }
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
       vector<int> adj[N];
       for(auto i: prerequisites){
           int u = i.first;
           int v = i.second;
           adj[u].push_back(v);
       }
       vector<bool> vis(N,false);
       vector<bool>recstack(N,false);
       for(int i=0;i<N;i++){
           if(!vis[i]) {
               if(iscycle(i,adj,vis,recstack)) return false;
           }
       }
       return true;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}