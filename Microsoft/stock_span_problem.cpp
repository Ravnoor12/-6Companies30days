#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
        vector<int> ans;
        ans.push_back(1);
        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && price[i]>=price[st.top()]){
                st.pop();
            }
            int res;
            if(st.empty()) res = i+1;
            else {
                res = i - st.top();
            }
            ans.push_back(res);
            st.push(i);
        }
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}