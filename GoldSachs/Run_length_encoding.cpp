#include<iostream>
using namespace std;
string encode(string s)
{     
  int count  =1;
  string ans = "";
  int n =s.size();
  int i=0;
  while(i<n-1){
      char cur = s[i];
      while(s[i]==s[i+1] && i<n-1){
          count++;
          i++;
      }
      ans = ans + cur + to_string(count);
      count = 1;
      i++;
  }
  if(s[n-2]!=s[n-1]) ans = ans + s[n-1] + '1'; 
  return ans;
}     

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<encode(s)<<endl;
    }
    return 0;
}