#include<bits/stdc++.h>
using namespace std;
const int max_n = 55;
int n,m, visited[101][101];
string a[101];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void BFS(int y, int x){
    visited[y][x] = 1;
    queue<pair<int,int>> q;
    q.push({y,x});
    while(q.size()){
        tie(y,x) = q.front();
        q.pop();
        for(int i = 0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= n || ny <0 || nx >= m || nx <0) continue;
            if(visited[ny][nx]) continue;
            if(a[ny][nx] != '1') continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }
    BFS(0,0);
    cout << visited[n-1][m-1];

}