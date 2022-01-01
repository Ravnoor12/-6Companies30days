#include<bits/stdc++.h>
using namespace std;
 
class Group_Anagrams{
  public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        int n = string_list.size();
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<n;i++){
           string s = string_list[i]; 
            sort(s.begin(),s.end());
            mp[s].push_back(string_list[i]);
        }
        vector<vector<string>> ans;
        for(pair<string,vector<string>> a : mp){
            ans.push_back(a.second);
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
        vector<string> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        Group_Anagrams obj;
        vector<vector<string>> ans = obj.Anagrams(v);
        sort(ans.begin(),ans.end());
        for(int i =0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}