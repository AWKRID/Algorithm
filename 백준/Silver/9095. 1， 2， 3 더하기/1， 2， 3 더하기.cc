// 1, 2, 3 
// 1 : 1
// 2: 2
// 3: 4 


#include <bits/stdc++.h>
using namespace std;
int t, n;
int arr[11];
int main(){
  arr[1] = 1; arr[2] = 2; arr[3] = 4;
  cin >> t;
  while(t--){
    cin >> n;
    if(n <= 3) {
      cout << arr[n] << "\n";
      continue;
    }
    for(int i = 4; i<=n; i++){
      arr[i] = arr[i-1] + arr[i-2]  + arr[i-3] ;
    }
    cout << arr[n] << "\n";
  }
}