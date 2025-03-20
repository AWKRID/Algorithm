#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙 선언
  // 항상 더 적은 카드 셋들을 합치는게 이득이다. 
  // 힙에서 두개를 빼고, 합친 값을 추가한다. 
  cin >> n;
  int tmp;
  while(n--){
    cin >> tmp; 
    pq.push(tmp);
  }
  if(n == 1){
    cout << "0\n";
    return 0;
  }
  int ans = 0;
  while(pq.size() > 1){
    int first = pq.top(); pq.pop();
    int second = pq.top(); pq.pop();
    ans += (first + second);
    pq.push(first+second);
  }
  cout << ans;
  return 0; 
}