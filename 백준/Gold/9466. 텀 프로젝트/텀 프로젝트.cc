#include <bits/stdc++.h>
using namespace std;
int t, n;
int love[100006];
int visited[100006];
void run(int x){
  int cur = x;
  while(true){
    visited[cur] = x;
    cur = love[cur];
    if(visited[cur] == x){
      while(visited[cur] != -1){
        visited[cur] = -1;
        cur = love[cur];
      }
      return;
    } 
    else if(visited[cur] != 0) {
      return; 
    }
  }
}


int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while(t--){
    fill(&visited[0], &visited[0] + 100006 , 0);
    fill(&love[0], &love[0] + 100006 , 0);
    cin >> n;
    for(int i = 1 ; i<= n; i++){
      cin >> love[i];
      if(love[i] == i) visited[i] = -1;
    }
    for(int i = 1; i<=n ;i++){
      if(visited[i]==0) run(i);
    }
    int ans = 0;
    for(int i = 1; i<=n;i++){
      if(visited[i] != -1) ans++;
    }
    cout << ans <<"\n";
  }
}