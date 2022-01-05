#include <bits/stdc++.h>
using namespace std;

// Find max 10 numbers in a list having 10M entries.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }

    for(int i=0;i<10;i++){
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}