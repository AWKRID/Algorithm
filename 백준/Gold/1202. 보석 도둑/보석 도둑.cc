// 보석도둑
// N개의 보석
// 각각은 무게 M, 가격 V
// 가방을 K개, 각 가방은 C의 무게를 가질 수 있고, 가방에는 하나밖에 못넣음

// 보석의 최대가격? 
// 가방을 크기 순으로 정렬
// 어차피 하나밖에 못넣으니까
// 작은 가방부터 넣을 수 있는 최대 밸류를 넣자. 
// 만약 가장 작은 가방에 넣을 수 있는 것 중에 최대가 아닌 것이 최대 밸류라면
// 더 최대를 넣으면 된다. -> 증명 끝

// 가방을 무게 순으로 정렬
// 보석을 무게 순으로 정렬.
// 찾을 때, upperbound를 찾고, 그 안의 것들 중에서 value가 가장 높은거..? 

#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> jewels; 
multiset<int> bags;
int n, k;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  int w, c;
  for(int i = 0; i < n; i++){
    cin >> w >> c;
    jewels.push_back({c,w});
  }
  sort(jewels.begin(), jewels.end(), greater<pair<int,int>>());

  for(int i = 0; i< k; i++){
    int bag;
    cin >> bag;
    bags.insert(bag);
  }
  long long ans = 0;
  for(pair<int,int> jewel: jewels){
    tie(c,w) = jewel;
    auto it = bags.lower_bound(w);
    if(it == bags.end()) continue;
    ans += c;
    bags.erase(it);
  }
  cout << ans << "\n";

}