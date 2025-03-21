// 연속해서 k개의 접시를 먹는 경우에 할인
// 각 고객은 쿠폰 -> 무료 제공
// 다양한 종류의 초밥을 먹는 것이 목표
// 

#include<bits/stdc++.h>
using namespace std;
int n, d, k, c;
int a[30005];
int cnt[3005];
int main(void){
  cin >> n >> d >> k >> c;
  for(int i =0; i< n; i++){
    cin >> a[i];
  }
  int mx = 0; 
  // 0번 초밥 부터 k-1 번 초밥 까지를 현재 s에 넣을거다
  // 대신 cnt를 관리해주자. 
  set<int> s;
  for(int i = 0; i < k; i++){
    s.insert(a[i]);
    cnt[a[i]]++;
  }

  // 그 중에서 만약 할인 초밥이 들어간 경우에는 전체 사이즈만큼만
  // 그게 아니면 size +1 
  if(cnt[c]) mx = int(s.size());
  else mx = int(s.size()) + 1;

  // 그다음 모든 회전 상황을 고려하기 위해서
  // 1번 초밥 부터 n-1번 초밥 부터 k개의 초밥을 먹는 경우를 생각
  // 빠지는 초밥은 a[i-1], 들어가는 초밥은 [i+k]
  for(int i = 1; i< n; i++){
    int minus = a[i-1];
    int plus = a[(i+k-1) % n];
    cnt[minus]--;
    cnt[plus]++;
    
    if(cnt[minus] == 0) s.erase(minus); 
    s.insert(plus);
    if(cnt[c]) mx = max(mx, int(s.size()));
    else mx = max(mx, int(s.size()) + 1);
  }
  cout << mx;

}