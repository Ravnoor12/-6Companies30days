#include<bits/stdc++.h>
using namespace std;

void rotate(int n,vector<vector<int>>&a)
{
      for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
           int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    for(int i=0;i<n;i++){
        int start = 0;
        int end = n-1;
        while(start<end){
          int temp = a[start][i];
          a[start][i] = a[end][i];
          a[end][i] = temp;;
            start++;
            end--;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> v(n,vector<int>(n));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cin>>v[i][j];
        }
        rotate(n,v);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<v[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}