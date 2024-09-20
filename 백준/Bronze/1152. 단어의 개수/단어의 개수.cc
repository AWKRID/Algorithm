#include<bits/stdc++.h>
using namespace std;

int cnt;
string s;




void fastIO(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int main(){
	fastIO();
	getline(cin, s);
	if(s.size() == 1 && s[0]==' ') {
		cout << "0\n";
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i] == ' '){
			if(i==0||i==s.size()-1) continue;
			cnt++;
		}
	}
	cout << cnt+1 << "\n";
}