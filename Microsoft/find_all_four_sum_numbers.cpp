#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        int n = arr.size();
        vector<vector<int>> ans;
        if(arr.empty()) return ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k2 = k - arr[i] - arr[j];
                int left = j+1;
                int right = n-1;
                while(right>left){
                    int sum = arr[left]+arr[right];
                    if(sum>k2) right--;
                    else if(sum<k2) left++;
                    else {
                        vector<int> v(4,0);
                        v[0] = arr[i];
                        v[1] = arr[j];
                        v[2] = arr[left];
                        v[3] = arr[right];
                        ans.push_back(v);
                        while(right>left &&arr[left]==v[2]){
                            left++;
                        }
                        while(right>left && arr[right]==v[3]){
                            right--;
                        }
                    } 
                }
                while(j+1<n && arr[j]==arr[j+1]) j++;
            }
                while(i+1<n && arr[i]==arr[i+1]) i++;
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}