#include <bits/stdc++.h> 
using namespace std; 

class Solution
{   
    public: 
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
         vector<int> v;
    int i1=0,i2 = r-1,j1 = 0,j2 = c-1;
    while(i1<=i2 && j1<=j2){
         for(int i=j1;i<=j2;i++){
             v.push_back(matrix[i1][i]);
         } 
         i1++;
         if(i1>i2 || j1>j2) break;
         for(int i=i1;i<=i2;i++){
             v.push_back(matrix[i][j2]);
         }
         j2--;
         if(i1>i2 || j1>j2) break;
         for(int i=j2;i>=j1;i--){
             v.push_back(matrix[i2][i]);
         }
         i2--;
         if(i1>i2 || j1>j2) break;
         for(int i=i2;i>=i1;i--){
             v.push_back(matrix[i][j1]);
         }         
         j1++;
      }
       return v;
    }
};
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 
        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}