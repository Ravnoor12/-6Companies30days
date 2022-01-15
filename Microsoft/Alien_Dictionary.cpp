#include <bits/stdc++.h>
using namespace std;

class Solution{
    string topologicalSort(vector<int>&indegree,int k,vector<int> adj[]){
        queue<int>q;
        for(int i=0;i<k;i++){
            if(indegree[i]==0)q.push(i);
        }
            string ans ="";
            while(!q.empty()){
                int node = q.front();
                q.pop();
                ans += (node + 'a');
                for(auto x:adj[node]){
                    indegree[x]--;
                    if(indegree[x]==0) q.push(x);
                }
            }
        if(ans.size()==k) return ans;
        return "";
    }
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        
        for(int i=0;i<N-1;i++){
            int len = min(dict[i].size(),dict[i+1].size());
            for(int j=0;j<len;j++){
                if(dict[i][j]!=dict[i+1][j]){
                    adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;
                }
            }
        }
        vector<int> indegree(K,0);
        for(int i=0;i<K;i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
        return topologicalSort(indegree,K,adj);
    }
};

string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
    }
    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();
    return p1 < p2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];       
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];
        string temp[N];
        copy(dict, dict + N, temp);
        sort(temp, temp + N, f);
        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;
        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}