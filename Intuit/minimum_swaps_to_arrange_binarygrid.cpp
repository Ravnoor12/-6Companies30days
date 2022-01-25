#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isOk(vector<int> row, int zeroStart) {
        if(row.empty() || zeroStart >= row.size())
            return true;
        
        for(int i = zeroStart; i < row.size(); i++) {
            if(row[i] != 0)
                return false;
        }
        
        return true;
    }
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int>maxright;
        int ans = 0;
        int n = grid.size();
        for(int i=0;i<n-1;i++){
            int nxtok = -1;
                if(isOk(grid[i],i+1)) continue;
                else{
                    for(int j = i + 1; j < grid.size() && nxtok == -1; j++) {
                        if(isOk(grid[j], i + 1)) {
                            nxtok = j;
                        }
                    }
                    if(nxtok==-1) return -1;
                    for(int j = nxtok; j > i; j--) {
                        swap<vector<int>>(grid[j], grid[j - 1]);
                        ans++;
                    }
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
          vector<vector<int>>nums(n,vector<int>(n));
            for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>nums[i][j];
            }
        }
        Solution obj;
        cout<<obj.minSwaps(nums)<<endl;
    }
    return 0;
}