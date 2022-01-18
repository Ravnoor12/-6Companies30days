#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string amendSentence (string s)
    {
        int n = s.size();
        string ans = "";
        ans += tolower(s[0]);
        for(int i=1;i<n;i++){
            if(s[i]>='A' && s[i]<='Z'){
                ans+= " ";
                ans+= tolower(s[i]);
            }
            else{
                ans+= s[i];
            }
        }
        return ans;
    }
};

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}