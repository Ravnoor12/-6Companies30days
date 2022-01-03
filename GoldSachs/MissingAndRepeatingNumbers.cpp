#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        unordered_map<int,int> mp;
        int *ans = new int[2];
        for(int i=0;i<n;i++){
            if(mp[arr[i]]) ans[0]=arr[i];
            mp[arr[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(mp[i]==0){
                ans[1] = i;
                break;
            }
        }
        return ans;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution obj;
        auto ans = obj.findTwoElement(arr,n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}