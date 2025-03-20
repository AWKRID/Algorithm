

#include <bits/stdc++.h>
using namespace std;
vector<int> v, uni;
int x[1000006];
int n,tmp;
int main(void){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x[i]; 
    v.push_back(x[i]);
  }
  sort(v.begin(), v.end());
  uni.push_back(v[0]);
  for(int i = 1; i< n; i++){
    if(v[i]!= v[i-1]){
      uni.push_back(v[i]);
    }
  }
  for(int i = 0; i< n; i++){
    cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << " ";
  }
}