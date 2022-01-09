#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Quicksort method	
    /*void quicksort(char nuts[], char bolts[], int l, int r) {
	    if(l >= r) return;
	    int c = partition(nuts, bolts, l, r);
	    quicksort(nuts, bolts, l, c - 1);
	    quicksort(nuts, bolts, c + 1, r);
	}
	int partition(char nuts[], char bolts[], int l, int r) {
	    int s = l, idx;
	    for(int i = l; i <= r; i++) {
	        if(bolts[i] < nuts[l]) swap(bolts[s++], bolts[i]);
	        if(bolts[i] == nuts[l]) idx = i;
	    }
	    swap(bolts[s], bolts[idx]);
    	for(int i = l; i <= r; i++) {
            nuts[i] = bolts[i];
	    }
	    return s;
	}
    void matchPairs(char nuts[], char bolts[], int n) {
	     quicksort(nuts, bolts, 0, n - 1);
	}*/
	void matchPairs(char nuts[], char bolts[], int n) {
	     unordered_map<int,char> mp;
	     for(int i=0;i<n;i++){
	         if(nuts[i]=='!') mp[0]='!';
             else if(nuts[i]=='#') mp[1]='#';
             else if(nuts[i]=='$') mp[2]='$';
             else  if(nuts[i]=='%') mp[3]='%';
             else if(nuts[i]=='&') mp[4]='&';
             else if(nuts[i]=='*') mp[5]='*';
             else if(nuts[i]=='@') mp[6]='@';
             else if(nuts[i]=='^') mp[7]='^';
             else mp[8]='~';
	     }
	     int count=0;
         for(int i=0;i<9;i++){
            if(mp[i]){
            nuts[count]=mp[i];
            bolts[count]=mp[i];
            count++;
            }      
        }
	}
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char nuts[n],bolts[n];
        for(int i=0;i<n;i++){
            cin>>nuts[i];
        }
         for(int i=0;i<n;i++){
            cin>>bolts[i];
        }
        Solution obj;
        obj.matchPairs(nuts,bolts,n);
        for(int i=0;i<n;i++){
            cout<<nuts[i]<<" ";
        }
        cout<<endl;
         for(int i=0;i<n;i++){
            cout<<bolts[i]<<" ";
        }
        cout<<endl;
    }
}