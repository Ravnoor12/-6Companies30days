#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string s){
    if(s.length()==0 || s[0]=='N'){
        return NULL;
    }
    vector<string>ip;
    istringstream iss(s);
    for(string s; iss >>s;){
        ip.push_back(s);
    }
    Node* root = new Node(stoi(ip[0]));
    queue<Node *>q;
    q.push(root);
    int i=1;
    while(!q.empty() && i<ip.size()){
        Node *currNode = q.front();
        q.pop();
        string curval = ip[i];
        if(curval!="N"){
            currNode->left = new Node(stoi(curval));
            q.push(currNode->left);
        }
        i++;
        if(i>=ip.size()) break;
        curval = ip[i];
        if(curval!="N"){
            currNode->right = new Node(stoi(curval));
            q.push(currNode->right);
        }
        i++;
    }
    return root;
}
class Solution
{
    public:
    
    vector<int> serialize(Node *root) 
    {
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
           Node* curNode = q.front();
           q.pop();
           if(curNode==NULL) ans.push_back(-1);
           else ans.push_back(curNode->data);
           if(curNode != NULL){
               q.push(curNode->left);
               q.push(curNode->right);            
           }
        }
        return ans;
    }
    
    Node * deSerialize(vector<int> &A)
    {
       Node* root = new Node(A[0]);    
       queue<Node*>q;
       q.push(root);
       int i=1;
       while(!q.empty() && i<A.size()){
           Node* temp = q.front();
           q.pop();
           if(A[i]==-1) temp->left = NULL;
           else{
               Node* temp_left = new Node(A[i]);
               temp->left = temp_left;
               q.push(temp_left);
           }
           i++;
           if(A[i]==-1) temp->right = NULL;
           else{
               Node* temp_right = new Node(A[i]);
               temp->right = temp_right;
               q.push(temp_right);
           }
           i++;
       }
       return root;
    }

};

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node* node)  
{  
    if (node == NULL) return;  
  
    _deleteTree(node->left);  
    _deleteTree(node->right);  
    delete node;  
}  
  
void deleteTree(Node** node_ref)  
{  
    _deleteTree(*node_ref);  
    *node_ref = NULL;  
}  

int main(){
    int t;
    cin>>t;
    fflush(stdin);
    while (t--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        deleteTree(&root);
        Node *getRoot = deserial.deSerialize(A);
        inorder(getRoot);
        cout <<endl;
    }
    return 0;
}  