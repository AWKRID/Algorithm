// 초기에 N+1 개의 집합
// union 연산과 find 연산필요

// n,m 입력 -> m은 연산의 개수
// 연산 0 a b -> a가 포함된 집합과 b가 포함된 집합을 합쳐라
// 1 a b는 두 원소가 같은 집합에 있으면 YES, 아니면 NO

#include <bits/stdc++.h>
using namespace std;
int n, m, k, t;
int p[1000006];

int find(int v){
  if(p[v] < 0) return v;
  return p[v] = find(p[v]);
}

bool uni(int u, int v){
  // 각각의 부모를 찾아
  u = find(u);
  v = find(v);
  // 만약 부모가 같으면 굳이? 
  if(u == v) return false;

  // 부모가 다르면 
  // rank가 더 큰 것 아래로 랭크가 작은거 붙이기
  if(p[v] < p[u]){
    swap(u,v); // 이제 v가 무조건 랭크가 더 크다
  } 
  if(p[u] == p[v]){
    p[u]--; // 랭크 하나 늘리기 
  }
  p[v] = u;
  return true;
}
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  for(int tes = 1 ; tes <= t ; tes++){
    cin >> n;
    cin >> k;
    fill(&p[0], &p[0] + n, -1);
    int a,b;
    while(k--){
      cin >> a >> b;
      uni(a,b);
    }
    cin >> m;
    cout << "Scenario "<< tes << ":\n";

    int u, v;
    while(m--){
      cin >> u >> v;
      if(find(u) == find(v)) {
        cout << "1\n";
      }else{
        cout << "0\n";
      }
    }
    cout << "\n";
  }
}