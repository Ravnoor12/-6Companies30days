#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    string nxtnumber(string a) {
        int i,j;
        int n = a.size();
        for(i=n-1;i>0;i--){
            if(a[i]>a[i-1]) break;
        }
        if(i==0) return "-1";
        for(int j=n-1;j>=i;j--){
             if(a[i-1] < a[j]){
                 char temp = a[j];
                 a[j] = a[i-1];
                 a[i-1] = temp;
                 break;
             }
        }
        reverse(a.begin()+i,a.end());
        return a;
    }
    string nextPalin(string N) { 
        int n = N.size();
        if(n<=3) return "-1";
        string ans = "";
        string half = N.substr(0,n/2);
        string num = nxtnumber(half);
        if(num!="-1"){
            ans+= nxtnumber(half);
            if(n%2!=0) ans += N[n/2];
            reverse(num.begin(),num.end());
            ans += num;
            return ans;
        }
        return "-1";
    }
};

int main() {
   int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}