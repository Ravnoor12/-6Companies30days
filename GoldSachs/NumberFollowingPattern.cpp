#include<iostream>
#include<stack>
using namespace std;

class Solution{   
public:
    string printMinNumberForPattern(string s){
        int n = s.size();
        int count = 1;
        string ans = "";
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]=='D'){
                st.push(count);
                count++;
            }
            else{
                st.push(count);
                count++;
                while(!st.empty()){
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(count);
             while(!st.empty()){
                    ans += to_string(st.top());
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
        cout<<obj.printMinNumberForPattern(s)<<endl;
    }
    return 0;
}