#include <bits/stdc++.h>
using namespace std;
const int max_n =54;
int t,m,n,k, a[max_n][max_n],visited[max_n][max_n],ret;
int dy[4]= {1,0,-1,0};
int dx[4] = {0,-1,0,1};

void dfs(int y,int x,int m,int n ){
	if(a[y][x]==0) return;
	visited[y][x]=1;
	for(int i=0;i<4;i++){
		int ny = y+dy[i];
		int nx= x+dx[i];
		if(ny<0||ny>=m||nx<0||nx>=n) continue;
		if(visited[ny][nx]==0){
			dfs(ny,nx,m,n);
		}
	}
}


int main(){
	int x,y;
	cin >> t;
	for(int i=0;i<t;i++){
		ret = 0;
		fill(&a[0][0], &a[max_n-1][max_n],0);
		fill(&visited[0][0], &visited[max_n-1][max_n],0);
		cin >> m >> n >> k;
		for(int j=0;j<k;j++){
			cin >> y >> x;
			a[y][x] = 1;
		}
		for(int h=0;h<m;h++){
			for(int l=0;l<n;l++){
				if(a[h][l]==0 || visited[h][l]==1) continue;
				ret++;
				dfs(h,l,m,n);
			}
		}
		cout << ret << "\n";
	}
	

	
}