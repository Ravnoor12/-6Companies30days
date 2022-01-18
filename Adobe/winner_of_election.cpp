#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
  
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string,int>mp;
        for(int i = 0;i<n;i++){
            mp[arr[i]]++;
        }
        int maxnum = mp[arr[0]];
        string s = arr[0];
        for(int i=1;i<n;i++){
            int val = mp[arr[i]];
             string temp = arr[i];
            if(val > maxnum){
                maxnum = val;
                s = temp;
            }
            else if(val==maxnum && temp < s) s = temp;
        }
        vector<string> ans;
        ans.push_back(s);
        ans.push_back(to_string(maxnum));
        return ans;
    }
};

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        string arr[n];
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);       
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}