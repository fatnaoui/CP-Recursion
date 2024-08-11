#include <bits/stdc++.h>
using namespace std;

int n,m;
int input[1000][1000];
int visited[1000][1000];
int ans = 0;

int max_pond(int i,int j){
    if((i == n) || (j == m) || (j < 0) || (i < 0) || visited[i][j] || (input[i][j] == 0)){
        return 0;
    }
    int cur = 0;
    visited[i][j] = true;
    cur =  1+max_pond(i,j+1)+max_pond(i,j-1)+max_pond(i-1,j)+max_pond(i+1,j);
    return cur;
}

int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>input[i][j];
            visited[i][j] = false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(input[i][j] == 0){
                input[i][j] = 1;
                memset(visited, 0, sizeof(visited));// reset all values to false
                ans = max(ans,max_pond(i,j));
                input[i][j] = 0;
            }
        }
    }
    cout<<ans;
}
