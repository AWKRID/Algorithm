#include <bits/stdc++.h>

using namespace std;
vector<int> adj[20005];
int visited[20005];
int bfs(int here){
    int ret = -1;
    queue<int> q;
    visited[here] = 1;
    q.push(here);
    while(q.size()){
        here = q.front(); q.pop();
        ret = max(ret, visited[here]);
        for(int there : adj[here]){
            if(visited[there]) continue;
            q.push(there);
            visited[there] = visited[here] + 1;
        }
    }
    return ret;
}
int solution(int n, vector<vector<int>> edge) {
    for(vector<int> e: edge){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    int mx = bfs(1);
    int cnt = 0;
    for(int i = 1; i<= n ; i++){
        if(visited[i] == mx) cnt++;
    }
    return cnt;
    
}