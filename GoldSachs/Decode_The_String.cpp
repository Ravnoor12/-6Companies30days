#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string decodedString(string s){
        int n = s.size();
        string ans = "";
        stack<char> st;
        for(int i =0;i<n;i++){
            if(s[i]==']'){
                 string a = "";
                 string freq = "";
                 int frq;
                 while(!st.empty() && st.top()!='['){
                     a = st.top() + a;
                     st.pop();
                 }
                 st.pop();
                while(!st.empty() && isdigit(st.top()) ){
                    freq += st.top();
                    st.pop();
                }
                reverse(freq.begin(),freq.end());
                frq = stoi(freq);
                while(frq--){
                    for(int i=0;i<a.size();i++){
                    st.push(a[i]);
                    }
                } 
            }
            else{
               st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.decodedString(s)<<endl;
    }
    return 0;
}