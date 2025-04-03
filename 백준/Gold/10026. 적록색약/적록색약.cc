#include <bits/stdc++.h>
using namespace std;
int n;
int visited[105][105];
char a[105][105];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
void bfs1(int y, int x, char t){
  queue<pair<int,int>> q;
  visited[y][x] = 1;
  q.push({y,x});
  while(q.size()){
    tie(y,x) = q.front(); q.pop();
    if(a[y][x] == 'G') a[y][x] = 'R';
    for(int i = 0; i< 4 ; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
      if(visited[ny][nx]) continue;
      if(a[ny][nx] != t) continue;
      visited[ny][nx] = visited[y][x];
      q.push({ny,nx});
    }
  }
}


int main(void){
  cin >> n;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    for(int j = 0 ; j < n; j++){
      a[i][j] = s[j];
    }
  }
  int ans1 = 0;
  int ans2 = 0;
  for(int i = 0; i< n; i++){
    for(int j = 0; j< n; j++){
      if(!visited[i][j]) {
        bfs1(i,j, a[i][j]);
        ans1++;
      }
    }
  }
  fill(&visited[0][0], &visited[0][0] + 105*105, 0);
  for(int i = 0; i< n; i++){
    for(int j = 0; j< n; j++){
      if(!visited[i][j]) {
        bfs1(i,j, a[i][j]);
        ans2++;
      }
    }
  }
  cout << ans1 << " "  << ans2;

}

