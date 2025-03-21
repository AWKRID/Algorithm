// 다리를 놓을 건데 가장 짧은 다리를 놓아야 한다
// connected component 사이의 최단 거리를 구해야 한다. 
// 각 connected component에 번호를 붙이자. 

// 개별 cc의 최 외각의 모든 점들이 동시에 출발해서
// 0인 구간만을 밟으며 bfs를 진행한다.
// 이 때, 자기 cc 보다 번호가 큰 땅을 밟게 되는 순간 bfs를 종료하고, 그 최단 거리를 입력한다.

// 전체 k개의 CC가 있다면, k-1번째 CC까지 진행하고 최소 값을 return

#include<bits/stdc++.h>
using namespace std;
int n;
int a[105][105];
int visited[105][105];
int visited2[105][105];
int cc[105][105];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
queue<pair<int,int>> outSide;


void makeCC(int y, int x, int num){
  queue<pair<int,int>> q;
  q.push({y,x});
  cc[y][x] = num;
  while(q.size()){
    tie(y,x) = q.front(); q.pop();
    for(int i = 0; i< 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || ny >= n || nx < 0 || nx>=n) continue;
      if(!a[ny][nx]) continue;
      if(cc[ny][nx]) continue; 
      q.push({ny,nx});
      cc[ny][nx] = num;
    }
  }
}


void findOutSide(int k){
  int y; int x;
  for(int i = 0; i< n;i++){
    for(int j = 0; j< n; j++){
      if(cc[i][j] == k){
        y= i; x = j;
        break;
      }
    }
  }
  visited2[y][x] = 1;
  queue<pair<int,int>> q; 
  q.push({y,x});
  while(q.size()){
    tie(y,x) = q.front(); q.pop();
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || ny >=n || nx <0 || nx >=n)continue;
      if(!cc[ny][nx]){
        if(visited[y][x]) continue;
        visited[y][x] = 1;
        outSide.push({y,x});
        continue;
      }
      if(visited2[ny][nx]) continue;
      visited2[ny][nx] = 1;
      q.push({ny,nx});
    }
  }
}


// k 번쨰 섬에서 k보다 큰 섬으로 가는 최단 거리를 구하는 식
// 먼저 queue에 최외각 원소들을 다 넣는다. -> outside
int findMinLength(int k){
  int y, x;
  queue<pair<int,int>> &q = outSide;
  while(q.size()){
    tie(y,x) = q.front(); q.pop();
    for(int i = 0 ; i< 4; i++){
      int ny = y + dy[i];
      int nx = x + dx[i];
      if(ny < 0 || ny >=n || nx < 0 || nx >=n) continue;
      if(visited[ny][nx]) continue;
      if(cc[ny][nx]==0){
        q.push({ny,nx}); visited[ny][nx] = visited[y][x]+ 1;
        continue;
      }
      if(cc[ny][nx] <= k) continue;
      if(cc[ny][nx] > k) return visited[y][x];
    }
  }
  return 9999999;
}



int main(){
  cin >> n;
  for(int i = 0; i< n; i++){
    for(int j = 0; j< n; j++){
      cin >> a[i][j];
    }
  }
  int num = 0;
  for(int i = 0; i<n ;i++){
    for(int j = 0; j< n; j++){
      if(a[i][j] && !cc[i][j]){
        makeCC(i,j,++num);
      }
    }
  }
  int mn = 9999999;
  for(int i = 1; i < num ;i++){
    fill(&visited[0][0], &visited[0][0]+105*105, 0);
    fill(&visited2[0][0], &visited2[0][0]+105*105, 0);
    while(outSide.size()){
      outSide.pop();
    }
    findOutSide(i);
    mn = min(mn, findMinLength(i));
  }
  cout << mn -1 ;
}