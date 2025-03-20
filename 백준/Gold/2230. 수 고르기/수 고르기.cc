

#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n, m, tmp;
int mn = 2100000000;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n ; i++) {
    cin >> tmp; 
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  for(int i = 0 ; i< v.size(); i++){
    int idx = lower_bound(v.begin(), v.end(), v[i] + m) - v.begin();
    if(idx >= v.size()) continue;
    mn = min(mn, v[idx]- v[i]);
  }
  cout << mn << "\n";
}