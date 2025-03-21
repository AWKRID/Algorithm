// 원숭이
// k 번만 말처럼 움직일 수 있음
// 벽 부수기 문제랑 같다! 
// {y,x,k} 를 넣고
// k가 최대 숫자보다 작은 경우에는 queue에 나이트 무빙을 넣는다

#include<bits/stdc++.h>
using namespace std;
int a[205][205];
int visited[205][205][31];
int n, m, k;
int INF = 98765432;
int dy[12] = {0,1,0,-1, 1, 1, -1,-1,2,2,-2,-2};
int dx[12] = {1,0,-1,0, 2, -2,2, -2,1,-1,1,-1};
void bfs(int y, int x){
  visited[y][x][0] = 1;
  queue<tuple<int,int,int>> q;
  q.push({y,x,0});
  int cnt; 
  while(q.size()){
    tie(y,x,cnt) = q.front(); q.pop();
    int dir = 4;
    if(cnt < k) dir = 12;

    for(int i = 0; i< dir; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || ny >= n || nx < 0|| nx >= m) continue;
      if(a[ny][nx]) continue; 
      // 말의 움직임이라면
      if(i >= 4){
        if(visited[ny][nx][cnt+1]) continue;
        visited[ny][nx][cnt+1]= visited[y][x][cnt] + 1;
        q.push({ny,nx,cnt+1});
        continue;
      }else{
        if(visited[ny][nx][cnt]) continue;
        visited[ny][nx][cnt] = visited[y][x][cnt] + 1;
        q.push({ny,nx,cnt});
      }
    }
  }
}

int main(void){
  cin >> k;
  cin >> m >> n;
  for(int i = 0 ; i< n ;i ++){
    for(int j = 0; j< m;j++){
      cin >> a[i][j];
    }
  }
  bfs(0,0); 
  int mn = INF; 
  for(int i = 0; i<= k ; i++){
    if(visited[n-1][m-1][i] != 0) mn = min(mn, visited[n-1][m-1][i]);
  }
  if(mn == INF){
    cout << "-1\n";
  }
  else{
    cout << mn-1 << "\n";
  }
  return 0;
}