#include <bits/stdc++.h>
using namespace std;
int n, k;
const int max_n = 100004;
int visited[100004];
queue<int> q; 

void fastIO(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

int bfs(int here){
    visited[here] = 1;
    q.push(here);
    while(q.size()){
        here = q.front();
        q.pop();
        for(int there : {here-1, here+1, here*2}){
            if(there < 0 || there >= max_n) continue;
            if(visited[there]) continue;
            visited[there] = visited[here] + 1;
            q.push(there);
        }
    }
    return 0;
}

int main(){
    fastIO();
    cin >> n >> k;
    bfs(n);
    cout << visited[k]-1 << "\n";
}

