// 한번에 한계단 혹은 두계단 가능
// 단, 연속한 세개의 계단은 밟을 수 없다. 
// d[i][j]
// d[i][2] = d[i-1][1] + arr[i];
// d[i][1] = d[i-2][2] + arr[i];

#include <bits/stdc++.h>
using namespace std;
int t, n;
int dp[305][3];
int point[305];
int main(){
  cin >> n;
  for(int i = 1; i<=n; i ++){
    cin >> point[i];
  }
  dp[1][1] = point[1];
  dp[2][1] = point[2];
  dp[1][2] = 0;
  dp[2][2] = point[1] + point[2];

  if(n == 1) {
    cout << point[1] << "\n"; 
    return 0 ;
  }
  if(n==2){
    cout << point[1]+point[2] << "\n";
    return 0 ;
  }
  for(int i = 3 ; i<=n;i++ ){
    dp[i][2] = dp[i-1][1] + point[i];
    dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + point[i];
  }

  cout << max(dp[n][1],dp[n][2]);
}