#include <bits/stdc++.h>
using namespace std;
int n, m;
int INF = 100000000;
int adj[105][105];
int main(void){
  cin >> n;
  cin >> m;
  int cost, a, b;
  fill(&adj[0][0], &adj[0][0] + 105*105, INF);

  for(int i = 0 ; i< m ; i++){
    cin >> a >> b >> cost;
    adj[a][b] = min(adj[a][b], cost);
  }
  for(int i = 1; i<=n;i++){
    adj[i][i] = 0;
  }

  for(int v = 1; v<= n ; v++){
    for(int i = 1; i<=n; i++){
      for(int j = 1; j<= n; j++){
        adj[i][j] =min(adj[i][j], adj[i][v] + adj[v][j]);
      }
    }
  }
  for(int i = 1; i<=n ;i++){
    for(int j = 1; j<=n ;j++){
      if(adj[i][j] == INF ) {
        cout << "0 ";
      }else{
        cout << adj[i][j] << " ";
      }
    }
    cout << "\n";
  }
}