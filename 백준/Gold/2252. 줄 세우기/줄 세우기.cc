


#include <bits/stdc++.h>
using namespace std;
vector<int> adj[32005];
int deg[32005];
int n,m;
int main(void){
  cin >> n >> m;
  for(int i = 0; i< m ; i++){
    int first, second;
    cin >> first >> second;
    deg[second]++;
    adj[first].push_back(second);
  }
  queue<int> q;
  // 위상 정렬
  for(int i = 1; i<= n; i++){
    if(deg[i]==0) q.push(i);
  }
  vector<int> ret;

  while(q.size()){
    int cur = q.front(); q.pop();
    ret.push_back(cur);
    // 위상 정렬에 넣고
    // 연결된 모든 정점에 대해서 deg값을 제거 
    for(int v : adj[cur]){
      if(--deg[v] == 0) q.push(v);
    }
  }
  for(int v: ret){
    cout << v << " ";
  }
  return 0;
}