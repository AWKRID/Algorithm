
// connected-component의 개수
// 가장 큰 것의 크기
// 모든 점을 돌면서, visited 가 0인 경우에 bfs를 돌고
// bfs 함수가 종료되는 시점에 크기를 return하도록 짜자. 
// 그러고, max 하면 됨


#include <bits/stdc++.h>
using namespace std;
int a[505][505], visited[505][505];
int n,m;
int ret, cnt;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

int bfs (int y, int x){
  int cnt = 0;
  queue<pair<int,int>> q;
  q.push({y,x});
  visited[y][x]= 1;
  while(q.size()){
    tie(y,x) = q.front(); q.pop();
    cnt++;
    for(int i = 0; i< 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny >= n || ny <0 || nx >=m || nx <0) continue;
      if(visited[ny][nx]) continue;
      if(!a[ny][nx]) continue;
      visited[ny][nx] = 1;
      q.push({ny,nx});
    }
  }
  return cnt;
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j< m ; j++){
      cin >> a[i][j];
    }
  }
  
  for(int i = 0; i< n ; i++){
    for(int j = 0; j< m; j++){
      if(a[i][j] && !visited[i][j]){
       ret = max(ret, bfs(i,j));
       cnt++;
      }
    }
  }
  cout << cnt << "\n" << ret;

}