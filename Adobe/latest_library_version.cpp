#include <bits/stdc++.h>
using namespace std;

string latest(string a,string b){
    int n = a.size();
    int m = b.size();
    int len = min(n,m);
    if(n==0 && m==0) return "Both versions are same";
    else if(n==0) return b;
    else if(m==0) return a;
    else{
        int i=0,j=0;
        while(i<len && j<len){
            string a1 ="";
            string b1 = "";
            while(a[i]!='.' && i<len) {
                a1 += a[i];
                i++;
            }
            while(b[j]!='.' && j<len){
                b1 += b[j];
                j++;
            }
            if(a1>b1) return a;
            else if(b1>a1) return b;
            i++,j++;
        }
        if(i<n) return a;
    }
    return b;
}

int main() {
	string a,b;
	cin>>a>>b;
	cout<<latest(a,b)<<endl;
	return 0;
}