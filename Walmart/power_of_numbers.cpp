#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

class Solution{
    int power(long long x, unsigned int y, int p)
{
    int res = 1;
 
    x = x % p; 
    if (x == 0) return 0;
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}
    public:
    long long power(int x,int y)
    {
        return power(x,y,mod);
    }
    
};
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long N;
        cin>>N;
        
        long long R = 0; 
        R = rev(N);
        Solution ob;
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}