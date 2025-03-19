// n개의 정수로 된 수열
// 크키가 양수인 부분 수열 중 합이 S가 되는 수열의 총 개수

#include<bits/stdc++.h>
using namespace std;
int n, s, cnt;
int a[21];
int isUsed[21];
void func(int idx, int sum){
  if(idx==n) return;
  func(idx+1, sum);
  if(sum + a[idx] == s) cnt++;
  func(idx+1, sum + a[idx]);
}

int main(){
  cin >> n >> s;
  for(int i = 0; i< n; i++){
    cin >> a[i];
  }
  func(0,0);
  cout << cnt;
}