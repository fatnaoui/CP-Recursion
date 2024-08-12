#include <bits/stdc++.h>
using namespace std;

int get_distance(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}

void min_time(int i,int n,int x1,int y1,int x2,int y2,int &ans,int cur,int pip[][5],bool *visited){
    if(i > n){
        cur += get_distance(x1,y1,x2,y2);
        ans = min(ans,cur);
        return ;
    }
    for(int j=0;j<n;j++){
        if(!visited[j]){
            visited[j] = true;
            int dist1 = get_distance(x1,y1,pip[j][0],pip[j][1])+pip[j][4];
            int dist2 = get_distance(x1,y1,pip[j][2],pip[j][3])+pip[j][4];
            min_time(i+1,n,pip[j][2],pip[j][3],x2,y2,ans,cur+dist1,pip,visited);
            min_time(i+1,n,pip[j][0],pip[j][1],x2,y2,ans,cur+dist2,pip,visited);
            visited[j] = false;   // backtracking
        }
    }
    // Consider the case when no pipe is used
    min_time(i + 1, n, x1, y1, x2, y2, ans, cur, pip, visited);
    return ;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        int input[4];
        for(int i=0;i<4;i++){
            cin>>input[i];
        }
        int pip[5][5];
        bool visited[5];
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin>>pip[i][j];
            }
            visited[i] = false;
        }
        int ans = get_distance(input[0],input[1],input[2],input[3]);
        min_time(0,n,input[0],input[1],input[2],input[3],ans,0,pip,visited);
        cout<<ans<<endl;
    }
    
}
