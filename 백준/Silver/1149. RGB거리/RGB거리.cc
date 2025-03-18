// 집 개수 N개
// 앞에서부터 할건데, 
// d[i][j] i 번째 집을 j번째 색으로 칠하는 최솟값

#include <bits/stdc++.h>
using namespace std;
int cost[1004][3], d[1004][3];
int n ;
int main(){
  cin >> n;

  for(int i = 1; i <=n ;i ++){
    cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
  }

  d[1][0]= cost[1][0]; d[1][1] = cost[1][1]; d[1][2] = cost[1][2];

  for(int i = 2; i<=n ;i++){
    d[i][0] = min(d[i-1][1], d[i-1][2]) + cost[i][0];
    d[i][1] = min(d[i-1][0], d[i-1][2]) + cost[i][1];
    d[i][2] = min(d[i-1][0], d[i-1][1]) + cost[i][2];
  }
  cout << min(min(d[n][0], d[n][1]), d[n][2]) << "\n";
}