// N+ 1일 날 퇴사 
// N일동안 최대한 많은 상담

// d[i] i일 퇴사햇을 했을 때 얻을 수 있는 최대 수익
// d[i] = 0;
// d[n] = d[i] + pi 의 최대 값 (대신 일이 가능해야 한 경우에만)

#include <bits/stdc++.h>
using namespace std;
int n, d, c;
int dp[1500005];
int main(void){
  cin >> n;
  for(int i = 1; i<= n; i++){
    cin >> d >> c;
    dp[i] = max(dp[i], dp[i-1]);
    if(i+d <= n+1){
      dp[i+d] = max(dp[i+d], dp[i] + c);
    }
  }
  dp[n+1] = max(dp[n+1], dp[n]);
  cout << dp[n+1];

}