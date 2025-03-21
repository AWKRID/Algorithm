#include <bits/stdc++.h>
using namespace std;

// 최단 경로 알고리즘 -> BFS
// 대신에 벽을 하나 부서도 된다.
// visited 배열에 최단경로가 들어갈 텐데.
// visited 배열을 다르게 관리 -> visited[y][x][break] break가 1이면
// 벽을 한 번 부수고 y,x 올 때의 최소값이 담기게 끔. 

// 그러면 bfs 이동 조건은?
// queue에서 꺼내고
// overflow 조건 확인하고
// 방문가능 지점인지 확인하고
// 만약 방문 가능지점이면 그냥 지나가고 

// 그냥 지나가는 거 -> visited[ny][nx][1] = visited[y][x][1]
//              -> visited[ny][nx][0] = visited[y][x][0]
// 방문 불가능 지점이면 벽을 한 번 깨고 지나가기 -> 이때, vistied[ny][nx][1] = visited[y][x][0]
int n, m;
int visited[1006][1006][2];
int a[1006][1006];
string b[1006];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};


int main(){
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++){
    cin >> b[i];
    for(int j = 0; j< m ; j++){
      a[i][j] = int(b[i][j] - '0');
    }
  }
 
  // -1로 최단거리 배열 초기화
  fill(&visited[0][0][0], &visited[0][0][0]+ 1006*1006*2, -1);

  queue<tuple<int,int,int>> q;
  q.push({0,0,0}); 
  visited[0][0][0] = 0; 
  int y,x, flag;
  while(q.size()){
    tie(y,x, flag) = q.front(); q.pop();
    for(int i = 0 ; i< 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
      // 이미 벽을 깨부수고 온거라면
      if(flag){
        // 앞이 벽이면 더 이상 못가고
        if(a[ny][nx]) continue; 
        // 벽이 아니고, 방문을 안한 경우에만 갱신
        if(visited[ny][nx][flag] != -1) continue;
        visited[ny][nx][flag] = visited[y][x][flag] + 1;
        q.push({ny,nx,flag});
      }
      // 벽을 한 번 깰 기회가 있다면
      else{
        if(a[ny][nx]){
          // 앞이 벽이고 그 앞이 한 번도 방문을 안했다면 
          if(visited[ny][nx][1] != -1) continue;
          visited[ny][nx][1] = visited[y][x][0] + 1;
          q.push({ny,nx,1});
          continue;
        }
        else{
          if(visited[ny][nx][0] != -1) continue;
          visited[ny][nx][0] = visited[y][x][0] + 1;
          q.push({ny,nx,0});
        }
      }
    }
  }
  if(visited[n-1][m-1][0] == -1 && visited[n-1][m-1][1] == -1){
    cout << "-1\n"; 
  }
  else if(visited[n-1][m-1][0] == -1 && visited[n-1][m-1][1] != -1){
    cout << visited[n-1][m-1][1] + 1 << "\n";
  }
  else if(visited[n-1][m-1][0] != -1 && visited[n-1][m-1][1] == -1) {
    cout << visited[n-1][m-1][0] + 1 << "\n";
  }
  else{
    cout << min(visited[n-1][m-1][0], visited[n-1][m-1][1]) + 1 << "\n";
  }

}