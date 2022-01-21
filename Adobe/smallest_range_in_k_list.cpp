#include<bits/stdc++.h>
using namespace std;
#define N 1000

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        int maxnum =INT_MIN;
        
        for(int i=0;i<k;i++){
            pq.push({KSortedArray[i][0],{i,0}});
            maxnum=max(maxnum,KSortedArray[i][0]);
        }
        
        int ans=INT_MAX;
        int r1=KSortedArray[0][0],r2=KSortedArray[0][0];
        
        while(!pq.empty()){
            pair<int,pair<int,int>>p=pq.top();
            pq.pop();
        
            
            if((maxnum-p.first)<ans){
                ans=maxnum-p.first;
                r1=p.first;
                r2=maxnum;
            }
            
            if(p.second.second<(n-1)){
                pq.push({KSortedArray[p.second.first][p.second.second+1],{p.second.first,p.second.second+1}});
                maxnum=max(maxnum,KSortedArray[p.second.first][p.second.second+1]);
            }
            else
                break;
            
        }
        
        pair<int,int>res;
        res.first=r1;
        res.second=r2;
        return res;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}