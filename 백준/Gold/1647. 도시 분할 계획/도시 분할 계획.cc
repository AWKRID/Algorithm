// MSP

// 마을을 두 마을로 나누는데, 
// 각 두 마을은 각각 최소 비용으로 연결되어야 한다. 

// 그냥 MSP 한다음에 제일 비용이 비싼 다리 하나 끊으면 끝

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int,int>> adj[100006]; // cost, target
int chk[100006];
vector<int> totalEdge; 
int main(void){
  cin >> n >> m;
  for(int i = 0; i< m ;i++){
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }
  chk[1] = 1;
  priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

  for(pair<int,int> edge : adj[1]){
    pq.push({edge.first, 1, edge.second});
  }
  while(totalEdge.size() < n-1){
    int cost, st, en;
    tie(cost, st, en) = pq.top(); pq.pop();
    if(chk[en]) continue;
    chk[en] = 1;
    totalEdge.push_back(cost);
    for(pair<int,int> edge : adj[en]){
      if(!chk[edge.second]) pq.push({edge.first, en, edge.second});
    }
  }
  sort(totalEdge.begin(), totalEdge.end());
  int ans = 0;
  for(int i = 0; i < totalEdge.size()- 1; i++){
    ans += totalEdge[i];
  }
  cout << ans; 
}