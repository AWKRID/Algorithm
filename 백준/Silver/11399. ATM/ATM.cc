// ATM 1대
// N명의 사람 줄서있음
// i 번째 사람이 걸리는 시간 Pi분
// 각 사람이 돈을 인출하는데 걸리는 시간의 합의 최소를 구해라

// 해결
// 명제: 돈을 뽑는데 오래 걸리는 사람을 무조건 뒤로

#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n, tmp;
int sum;
void fastIO(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main(){
  cin >> n;
  for(int i =0 ;i <n ;i++){
    cin >> tmp;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  for(int i = 0; i< n ;i++){
    sum += v[i] * (n-i);
  }
  
  cout << sum;
  return 0;
}