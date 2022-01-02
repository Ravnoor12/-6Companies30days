#include<iostream>
#include<vector>
using namespace std;
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ans = 0;
        int i=0;
        int j=0;
       long long int prod = 1;
        while(j<n){
            prod*=a[j];
            while(i<n && prod>=k){
                prod/=a[i];
                i++;
            }
            if(prod<k){
               ans += j-i+1;
            }
            j++;
        }
        return ans;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,i;
        long long k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution obj;
        cout<<obj.countSubArrayProductLessThanK(arr,n,k)<<endl;
    }
    return 0;
}