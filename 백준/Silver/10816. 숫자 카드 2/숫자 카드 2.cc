#include <bits/stdc++.h>
using namespace std;
int n, m, tmp;
vector<int> v;

int lowerIdx(int target, int len){
  int left = 0;
  int right = len;
  while(left < right){
    int mid = (left + right )/2;
    if(v[mid] >= target) right = mid;
    else left = mid + 1;
  }
  return left; 
}

int upperIdx(int target, int len){
  int left = 0;
  int right = len;
  while(left < right){
    int mid = (left + right )/2;
    if(v[mid] > target) right = mid;
    else left = mid + 1;
  }
  return left; 
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
  int len = v.size();
  while(m--){
    cin >> tmp;
    cout << upperIdx(tmp,len ) - lowerIdx(tmp,len) << "\n";
  }

}