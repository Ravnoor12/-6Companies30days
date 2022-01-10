#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node *root = new Node(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));

            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution {
    int maxDistance(Node* target,unordered_map<Node*,Node*>mp){
        queue<Node*> q;
        q.push(target);
        unordered_map<Node*,int>vis;
        int ans = 0;
        vis[target]=1;
        while(!q.empty()){
           int n = q.size();
           bool fl = 0;
           for(int i=0;i<n;i++){
               Node* temp = q.front();
               q.pop();
               if(temp->left && !vis[temp->left]) {
                    fl = 1; 
                    vis[temp->left] = 1; 
                    q.push(temp->left); 
                }
                if(temp->right && !vis[temp->right]) {
                    fl = 1; 
                    vis[temp->right] = 1; 
                    q.push(temp->right); 
                }
                 if(mp[temp] && !vis[mp[temp]]) {
                    fl = 1; 
                    vis[mp[temp]] = 1; 
                    q.push(mp[temp]); 
                } 
            } 
            if(fl) ans++;
        }
        return ans;
    }
    Node* bfsTomapParents(Node* root,unordered_map<Node*,Node*>&mp,int target){
          Node* ans;
          queue<Node*> q;
          q.push(root);
          while(!q.empty()){
              Node* temp = q.front();
              if(temp->data==target) ans = temp;
              q.pop();
              if(temp->left){ 
                  mp[temp->left] = temp;
                  q.push(temp->left);
                }
              if(temp->right){ 
                  mp[temp->right] = temp;
                  q.push(temp->right);
              }
          }
          return ans;
    }
  public:
    int minTime(Node* root, int target) 
    {
        unordered_map<Node* ,Node*>mp;
        Node* targ = bfsTomapParents(root,mp,target);
        int ans = maxDistance(targ,mp);
        return ans;
    }
};
int main() 
{
    int tc;
    cin>>tc;
    fflush(stdin);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        int target;
        cin>>target;
        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }
    return 0;
}