#include <bits/stdc++.h>
using namespace std;
int a[105][105][105];
int visited[105][105][105];
int n, m, h;
int dy[6] = {1,0,0,-1,0,0};
int dx[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};
queue<tuple<int,int,int>> q;

int bfs(){
  int y, x, z;
  int mx = 0;
  while(q.size()){
    tie(y,x,z) = q.front(); q.pop();
    mx = visited[y][x][z];
    for(int dir = 0; dir < 6; dir++){
      int ny = y + dy[dir];
      int nx = x + dx[dir];
      int nz = z + dz[dir];
      if(ny < 0 || ny >= n || nx < 0 || nx >= m || nz < 0 || nz >= h) continue;
      if(a[ny][nx][nz] == -1) continue;
      if(visited[ny][nx][nz]) continue;
      visited[ny][nx][nz] = visited[y][x][z] + 1;
      q.push({ny,nx,nz});
    }
  }
  return mx;
}


int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> m >> n >> h;
  bool flag = true;
  for(int k = 0; k < h ;k++){
    for(int i = 0 ; i< n; i++){
      for(int j = 0; j< m; j++){
        cin >> a[i][j][k];
        if(a[i][j][k] == 0){
          flag = false;
        }
        if(a[i][j][k] == 1){
          q.push({i,j,k});
          visited[i][j][k] = 1; 
        }
      }
    }
  }
  if(flag){
    cout << "0\n";
    return 0;
  }
  int days = bfs();
  for(int i = 0 ; i< n; i ++){
    for(int j = 0; j< m ;j++){
      for(int k = 0; k< h; k++){
        if(a[i][j][k] == 0 && visited[i][j][k] == 0){
          cout << "-1\n";
          return 0;
        }
      }
    }
  }
  cout << days-1 <<"\n";

  
}