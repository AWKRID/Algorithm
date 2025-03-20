#include <bits/stdc++.h>
using namespace std;
int t, k;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while(t--){
    cin >> k;
    char op; 
    int num;
    multiset<int> ms;
    for(int i = 0; i<k; i++){
      cin >> op >> num;
      if(op == 'I'){
        ms.insert(num);
      }
      else{
        if(ms.empty()) continue;
        if(num == -1){
          ms.erase(ms.begin());
        }
        else{
          ms.erase(prev(ms.end()));
        }
      }
    }
    if(ms.empty()) cout << "EMPTY\n";
    else{
      cout << *prev(ms.end()) << " " << *ms.begin() << '\n';
    }
  }
}