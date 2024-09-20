#include <bits/stdc++.h>
using namespace std;
int n, m, v;
const int max_n = 10004;
vector<int> adj[max_n];
int visited1[max_n], visited2[max_n];

void DFS(int here){
    cout << here << " ";
    visited1[here] = 1;
    for(auto there : adj[here]){
        if(visited1[there]) continue;
        DFS(there);
    }
}

void BFS(int here){
    queue<int> q;
    cout << here << " ";
    visited2[here] = 1;
    q.push(here);
    while(q.size()){
        here = q.front();
        q.pop();
        for(auto there : adj[here]){
            if(visited2[there]) continue;
            cout << there << " ";
            visited2[there] = visited2[here] + 1;
            q.push(there);
        }
    }
}

int main(){
    cin >> n >> m >> v;
    int v1, v2;
    for(int i = 0; i<m ;i++){
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    for(int i = 1; i<=n;i++){
        sort(adj[i].begin(), adj[i].end());
    }
    DFS(v);
    cout << "\n";
    BFS(v);

}