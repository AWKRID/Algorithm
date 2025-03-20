#include <bits/stdc++.h>
using namespace std;
int n, m, tmp;
vector<int> v;

int bs(int target){
  int left = 0; 
  int right = v.size()-1;
  while(left <= right){
    int mid = (left + right) / 2;
    if(v[mid] == target) return 1;
    else if(v[mid] > target){
      right = mid -1;
    }
    else{
      left = mid + 1;
    }
  }
  return 0;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n;
  for(int i = 0; i< n; i++){
    cin >> tmp;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  cin >> m;
  while(m--){
    cin >> tmp;
    cout << bs(tmp) << "\n";
  }

}