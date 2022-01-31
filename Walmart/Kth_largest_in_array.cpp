#include<bits/stdc++.h>
using namespace std;

class Solution {
   static bool comp(string a,string b){
        int n1 = a.size();
        int n2 = b.size();
        if(n1==n2){
            return a<b;
        }
        return n1<n2;
    }
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),comp);
        return nums[n-k];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        int n;
        cin>>n;
        vector<string> v(n);
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            v[i] = s;
        }
        Solution obj;
        cout<<obj.kthLargestNumber(v,k)<<endl;
    }
  return 0;   
}