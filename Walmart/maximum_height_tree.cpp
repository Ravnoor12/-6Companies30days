#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int height(int N){
        int h = 0;
        int i=1;
        int a = N;
        while(a>0){
            if(a-i>=0){
                h++;
                a-=i;
                i++;
            }
            else{
                return h;
            }
        }
        return h;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.height(N)<<endl;
    }
    return 0;
}