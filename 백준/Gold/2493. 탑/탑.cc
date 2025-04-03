#include <bits/stdc++.h>
using namespace std;
int n;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  stack<pair<int,int>> st;
  for(int i = 1; i<=n; i++){
    int tmp;
    cin >> tmp;
    while(!st.empty()){
      if(st.top().second > tmp){
        cout << st.top().first << " ";
        break;
      }
      st.pop();
    }
    if(st.empty()){
      cout << "0 ";
    }
    st.push({i,tmp});
  }
  
}
