#include <bits/stdc++.h>
using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m) {

    if (m == 0) return true;
    if (n == 0) return false;

    if (v1[n - 1] == v2[m - 1]) return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}

class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        vector<int> small(N);
        vector<int>grt(N);
        small[0] = -1;
        grt[N-1] = -1;
        int imin=0;
        for(int i=1;i<N;i++){
            if(arr[imin]<arr[i] && imin<i){
                small[i] = imin;
            }
            else if(imin>=i || arr[i]<=arr[imin]){
                small[i]=-1;
                imin= i;
            }
        }
        int imax = N-1;
        for(int i=N-2;i>=0;i--){
            if(arr[imax]>arr[i] && imax>i){
                grt[i] = imax;
            }
            else if(imax<=i || arr[imax]<=arr[i]){
                small[i]=-1;
                imax = i;
            }
        }
        vector<int>ans(3);
        for(int i=0;i<N;i++){
            if(grt[i]!=-1 && small[i]!=-1){
                ans[0] = arr[small[i]],ans[1] = arr[i],ans[2] = arr[grt[i]];
                return ans;
            }
        }
        return {};
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        auto res = obj.find3Numbers(a, n);
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and
                   isSubSequence(a, res, n, res.size())) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}