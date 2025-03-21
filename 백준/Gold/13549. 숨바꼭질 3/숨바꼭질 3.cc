// 숨바꼭질 3
// 수빈이 N, 동생 K 

#include <bits/stdc++.h>
using namespace std;
int visited[100006];

int n, k;
int main(){
  cin >> n >> k;
  visited[n] = 1;
  queue<int> q;
  q.push(n);
  int cur;
  while(q.size()){
    cur = q.front(); q.pop();
    for(int next : {cur-1, cur + 1, 2 * cur}){
      if(next <0 || next > 100000) continue;
      if(visited[next] != 0 && visited[next] <= visited[cur]) continue;
      visited[next] = visited[cur];
      q.push(next);
      if(next != 2 * cur){
        visited[next]++;
      }
    }
  }
  cout << visited[k]- 1;
}