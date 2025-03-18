#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100005], psum[100005];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  psum[0] = 0;
  for(int i = 1; i<= n; i++){
    cin >> a[i];
    psum[i] = psum[i-1] + a[i];
  }
  while(m--){
    int a,b;
    cin >> a >> b;
    cout << psum[b] - psum[a-1] << "\n";
  }
  return 0 ;
}