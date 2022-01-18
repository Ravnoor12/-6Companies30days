#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int atoi(string str) {
        bool neg= false;
        int ans = 0;
        int n = str.size();
        for(int i=0;i<n;i++){
            if(i==0 && str[i]=='-') {
                neg = 1;
                continue;
            }
            if(str[i]>='0' && str[i]<='9'){
                ans = ans*10 + (str[i]-'0');
            }
            else{
                return -1;
            }
        }
        if(neg) ans = ans*-1;
        return ans;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}