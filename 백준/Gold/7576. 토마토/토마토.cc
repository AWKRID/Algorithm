// n*m 격자에 토마토
// 하루가 지나면 인접한 영역에 있는 토마토가 익는다
// 며칠이 지나면 다 익는가?
// 최단 거리를 두고, 그 값의 최대를 칭하면 된다.  
// 근데 bfs를 돌꺼니까 어차피 마지막의 값을 가져오자.

#include<bits/stdc++.h>
using namespace std;
int n,m, visited[1005][1005], a[1005][1005];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int tmp;
  int dy[4] = {0,1,0,-1};
  int dx[4] = {1,0,-1,0};
  queue<pair<int,int>> q;
  cin >> m >> n;
  int already = 1;
  for(int i = 0  ; i< n; i++){
    for(int j = 0; j< m; j++){
      cin >> a[i][j];
      if(a[i][j] == 1){
        q.push({i,j});
        visited[i][j] = 1;
      }
      if(a[i][j]==0) already = 0;
    }
  }
  // 모두 다 익어있는 상황? 
  if(already){
    cout << "0\n";
    return 0;
  }

  int y, x;
  while(q.size()){
    tie(y,x) = q.front(); q.pop();
    for(int i = 0; i< 4; i++){
      int ny = y+ dy[i];
      int nx = x + dx[i];
      if(ny >= n || ny <0 || nx >=m || nx <0) continue;
      if(visited[ny][nx]) continue;
      if(a[ny][nx] == -1) continue;
      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny,nx});
    }
  }
  int ret = -1;
  for(int i = 0; i< n;i++){
    for(int j = 0; j< m; j++){
      if(a[i][j] != -1 && visited[i][j] == 0) {
        cout << "-1\n";
        return 0;
      }
      ret = max(ret, visited[i][j]);
    }
    
  }
  cout << ret-1;

}