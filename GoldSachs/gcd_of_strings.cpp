#include<iostream>
using namespace std;
class Solution {
public:
    bool check(string pre,string str1,string str2){
        int n1 = str1.size();
        int n2 = str2.size();
        int n = pre.size();
        int len1 = n1/n;
        int len2 = n2/n;
        string s1 =  "";
        string s2 = "";
        for(int i=1;i<=len1;i++) s1 += pre;
        for(int i=1;i<=len2;i++) s2 += pre;
        return (s1==str1 && s2==str2);
    }
    string gcdOfStrings(string str1, string str2) {
        int i=0;
        int n1 = str1.size();
        int n2 = str2.size();
        string s = "";
        string ans;
        while(i<n1 && i<n2 && str1[i]==str2[i]){
            s += str1[i];
            if(check(s,str1,str2)) ans=s;
            i++;
        }
        return ans;
    }
};
int main(){
    string s1,s2;
    cin>>s1>>s2;
    Solution obj;
    string ans = obj.gcdOfStrings(s1,s2);
    cout<<ans<<endl;
    return 0;
}