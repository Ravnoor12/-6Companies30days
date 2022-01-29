#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calmoves(char a,string col){
        int n = col.size();
        int count = 0;
        for(int i=1;i<n-1;i++){
            if(col[i]==a && col[i-1]==a && col[i+1]==a){
                count++;
            }
        }
        return count;
    }
    bool winnerOfGame(string colors) {
        int a = calmoves('A',colors);
        int b = calmoves('B',colors);
        return a>b;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.winnerOfGame(s)<<endl;
    }
    return 0;
}