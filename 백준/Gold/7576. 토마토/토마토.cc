#include<bits/stdc++.h>
using namespace std;
int n,m, a[1005][1005];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
queue<pair<int,int>> q;
int ret;
void BFS(){
    int y, x;
    while(q.size()){
        tie(y,x) = q.front();
        q.pop();
        for(int i = 0; i< 4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= n || ny <0 || nx >=m || nx <0) continue;
            if(a[ny][nx] != 0) continue;
            a[ny][nx] = a[y][x] + 1;
            q.push({ny,nx});
        }
    }
}

int main(){
    cin >> m >> n;
    int flag = 1;
    for(int i = 0 ;i <n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
            if(a[i][j] == 1){
                q.push({i,j});
            }
            if(a[i][j] == 0){
                flag = 0;
            }
        }
    }
    if(flag == 1){
        cout << 0;
        return 0;
    }
    BFS();
   
    for(int i=0; i<n;i++){
        for(int j=0; j<m ;j++){
            if(a[i][j]==0){
                cout << -1; 
                return 0;
            }
            ret = max(ret, a[i][j]);
        }
    }
    
    cout << ret- 1;
   
}




