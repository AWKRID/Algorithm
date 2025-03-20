

#include <bits/stdc++.h>
using namespace std;
int n , s, tmp, mn = 999999;
int a[100006], psum[100006];
int main(void){
  cin >> n >> s;
  for(int i = 0 ; i< n; i++){
    cin >> a[i];
    psum[i+1] = psum[i] + a[i];
  }
  int j = 0;
  for(int i = 1; i<= n; i++){
    while(j <= n && psum[j]-psum[i-1] < s){
      j++;
    }
    if(j > n) break;
    mn = min(mn, j-i +1);
  }
  if(psum[n] < s) {
    cout << "0";
    return 0;
  }
  cout << mn << "\n";
  return 0 ;
  // 부분 합 중에서 합이 s가 되는 것 중에 길이가 가장 짧은 것 
  // 자연수다 -> 즉 s를 어떻게든 늘려가면서 찾기만 하면 그 뒤는 볼필요가 없다. 
 


}