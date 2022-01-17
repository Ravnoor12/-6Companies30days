#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;

class Solution
{
    void generate(int n,int i,int j,string s,vector<string> &ans){
        if(i==n && j==n) {
            ans.push_back(s);
            return;
        }
        if(i<n) generate(n,i+1,j,s+'(',ans);
        if(j<i) generate(n,i,j+1,s + ')',ans);
    }
    public:
    vector<string> AllParenthesis(int n) 
    {
        vector<string> ans;
        generate(n,0,0,"",ans);
        return ans;
    }
};

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 