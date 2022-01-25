#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
      vector<int> topologicalSort(vector<int>&indegree,int k,vector<int> adj[]){
        queue<int>q;
        for(int i=0;i<k;i++){
            if(indegree[i]==0)q.push(i);
        }
            //string ans ="";
         vector<int>ans;
            while(!q.empty()){
                int node = q.front();
                q.pop();
               // ans += (node + 'a');
                ans.push_back(node);
                for(auto x:adj[node]){
                    indegree[x]--;
                    if(indegree[x]==0) q.push(x);
                }
            }
        if(ans.size()==k) return ans;
        ans.clear();
        return ans;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++) 
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
        }
       
        return topologicalSort(indegree,numCourses,adj);
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int numcourses;
        cin>>numcourses;
        int n;
        cin>>n;
        vector<vector<int>>nums(n,vector<int>(2));
         for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                cin>>nums[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.findOrder(numcourses,nums);
        for(auto i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}