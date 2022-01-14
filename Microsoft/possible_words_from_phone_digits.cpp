#include <bits/stdc++.h>
using namespace std;

class Solution
{
    string code[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};       
    public:
    void getcomb(int a[],int idx,string output,vector<string>&ans,string code[],int n){
        if(idx==n){
            ans.push_back(output);
            return;
        }
        int digit = a[idx];
        string temp = code[digit];
        for(int i=0;i<temp.size();i++){
            output.push_back(temp[i]);
            getcomb(a,idx+1,output,ans,code,n);
            output.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string>ans;
      if(N==0) return ans;
      int i =0;
      string output = "";
      getcomb(a,i,output,ans,code,N);
      return ans;
    }
};

int main() {
	int T;
	cin >> T; 
	while(T--){ 
	   int N;
	   cin >> N; 
	   int a[N]; 
	   for(int i =0;i<N;i++){
	       cin >> a[i]; 
	   }
	   Solution obj;	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}