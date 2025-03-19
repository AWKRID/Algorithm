// 미로
// 지훈이의 위치, 불의 위치 -> 불이 타기전에 탈출할 수 있나요?
// 얼마나 빨리?
// 불은 네방향으로 확산
// 지훈이는 미로의 가장자리에서 탈출 가능
// 지훈/불은 벽을 통과하지 x

// 불을 먼저 옮길거다. 불이 여러개 가능
// 각 지점에 불이 언제 붙는지를 두고
// 지훈이를 그다음에 옮길거다.
// 지훈이는 불이 붙기 전의 시간이라면 갈 수 있다. 
// queue를 pop했는데 해당 값이 가장자리라면, 바로 리턴한다. 

#include<bits/stdc++.h>
using namespace std;
string board[1005];
int n , m , fire[1005][1005], visited[1005][1005];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int main(){
  queue<pair<int,int>> q;
  cin >> n >> m;
  int sy, sx;
  for(int i = 0; i< n; i++){
    cin >> board[i];
    for(int j = 0; j< m ;j++){
      if(board[i][j] == 'F'){
        q.push({i,j});
        fire[i][j] = 1;
      }
      else if(board[i][j] == 'J'){
        sy = i; sx = j;
      }
    }
  }
  int y, x;
  // 불 이동
  while(q.size()){
    tie(y,x) = q.front(); q.pop();
    for(int i = 0; i< 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny >= n || ny < 0|| nx >= m || nx<0) continue;
      if(fire[ny][nx]) continue;
      if(board[ny][nx] == '#' || board[ny][nx] == 'F') continue;
      fire[ny][nx] = fire[y][x] + 1;
      q.push({ny,nx});
    }
  }
  // 지훈이 이동
  q.push({sy,sx});
  visited[sy][sx] = 1;
  while(q.size()){
    tie(y,x) = q.front(); q.pop();
    if(y == n-1 || y == 0 || x == m-1 || x==0) {
      cout << visited[y][x];
      return 0;
    }
    for(int i = 0; i< 4; i ++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny >= n || ny < 0 || nx >= m || nx <0) continue;
      if(visited[ny][nx]) continue;
      if(board[ny][nx] =='#') continue;
      if(fire[ny][nx] != 0 && fire[ny][nx] <= visited[y][x]+1) continue;
      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny,nx});
    }
  }
  cout << "IMPOSSIBLE";
  return 0;


}