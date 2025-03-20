#include <bits/stdc++.h>
using namespace std;
int n;
int self[305];
vector<pair<int,int>> edge[305];
bool chk[305];
int main(void){

  // 간선을 어떻게 표현을 할거냐
  // 양방향 간선이기 때문에
  // vector<pair<int,int>> adj로 두고, adj[i] 에다가 {cost, vertex}} 두기
  // 

  // 서치를 진행하는데, 일단 개인의 우물을 파지 않고 발생하는 최솟값을 구하고
  // n+1 정점을 추가해서 각 간선의 비용을 개별 우물 파는데 드는 비용으로 모든 정점이랑 연결

  // 두 개의 MST 값의 크기를 비교해서 최소값을 출력 

  cin >> n;
  for(int i = 1; i<= n ; i++){
    cin >> self[i];
  } 
  int cost;
  for(int i = 1; i<= n;i++){
    for(int j = 1; j<=n; j++){
      cin >> cost;
      edge[i].push_back({cost, j});
    }
  }
  // 먼저 셀프로 파지 않고 최소 스패닝 트리 구하기
  // 특정 점에서 시작해서, pq에다가 연결가능한 간선 다 넣어서 진행
  // pq.top() 해서, 해당 edge의 타켓 정점이 이미 mst에 포함되어 있으면 continue
  // 그게 아니면 해당 정점과 이어진 간선을 다 넣고 진행
  // 간선의 개수가 n-1이 될 때까지 
  for(int i = 1 ; i<= n; i++){
    edge[i].push_back({self[i], n+1});
    edge[n+1].push_back({self[i], i});
  }
  
  priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
  for(auto e : edge[1]){
    pq.push(make_tuple(e.first, 1, e.second));
  }
  chk[1] = true;
  int total = 0;
  int cnt = 0;
  while(cnt < n){
    int start, end;
    tie(cost, start, end) = pq.top(); pq.pop();
    if(chk[end]) continue;
    chk[end] = true;
    total += cost;
    cnt++;
    for(auto e: edge[end]){
      if(!chk[e.second]) pq.push(make_tuple(e.first, end, e.second));
    }
  }
  cout << total;
  return 0;

}