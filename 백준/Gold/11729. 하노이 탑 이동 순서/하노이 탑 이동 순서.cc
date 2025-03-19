#include <bits/stdc++.h>
using namespace std;

void hanoi(int start, int end, int n){
  if(n==1) {
    cout << start << ' ' << end << '\n';
    return;
  }
  int mid = 6- start- end;
  hanoi(start, mid, n-1);
  cout << start << ' ' << end << '\n';
  hanoi(mid, end, n-1);
}

int main(){
  int k;
  cin >> k;
  cout << (1<<k) - 1 << '\n';
  hanoi(1, 3, k);
}