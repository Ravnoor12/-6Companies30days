#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(string str,string &maxstr,int k,int pos){
        if(k==0) return;
        int n = str.size();
        char maxch = str[pos];
        for(int i =pos+1;i<n;i++){
            if(maxch<str[i]) maxch = str[i];
        }
        if(maxch!=str[pos]) k--;
        for(int i=n-1;i>=pos;i--){
            if(str[i]==maxch){
                swap(str[pos],str[i]);
                if(str.compare(maxstr)>0) maxstr = str;
                solve(str,maxstr,k,pos+1);
                swap(str[i],str[pos]);
            }
        }
    }
    public:
    string findMaximumNum(string &str, int k)
    {
       string maxstr = str;
       solve(str,maxstr,k,0);
       return maxstr;
    }
};

int main()
{
    int t, k;
    string str;
    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}