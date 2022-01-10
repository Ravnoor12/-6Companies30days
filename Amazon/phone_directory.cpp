#include<bits/stdc++.h>
using namespace std;

class Solution{
    bool ispref(string s,string s1){
        int n = s.size();
        int n1 = s1.size();
        if(n1<n) return false;
        for(int i=0;i<n;i++){
            if(s[i]!=s1[i]) return false;
        }
        return true;
    }
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        int n1 = s.size();
        string s1 ="";
        vector<vector<string>> ans;
        for(int i=0;i<n1;i++){
            s1 += s[i];
            set<string> st;
            for(int j=0;j<n;j++){
                if(ispref(s1,contact[j])) st.insert(contact[j]);
            }
            vector<string>temp;
            for(auto i:st){
                temp.push_back(i);
            }
            if(temp.size()==0) {
                temp.push_back("0");
                ans.push_back(temp);
                continue;
            }
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
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
        string contact[n],s;
        for(int i=0;i<n;i++){
            cin>>contact[i];
        }
        cin>>s;
        Solution obj;
        vector<vector<string>> ans = obj.displayContacts(n,contact,s);
        for(int i=0;i<s.size();i++){
            for(auto j:ans[i]){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}