#include<bits/stdc++.h>
using namespace std;

int getbinary(int x){
    int ans = 0;
    int l = 1;
    while(x!=0){
       ans += (x%2)*l;
       x/=2;
       l*=10;
    }
    return ans;
}
vector<string> generate(int N)
{
    vector<string> s;
	for(int i=1;i<=N;i++){
	    int val = getbinary(i);
	    s.push_back(to_string(val));
	}
	return s;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}