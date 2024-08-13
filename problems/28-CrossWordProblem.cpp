#include <bits/stdc++.h>
using namespace std;

int n;
string words[15];
int m;
char cross[10][10];
bool visited[10][10];
set<string> s;
char output[100];

bool exist(string sss){
    for(string si:words){
        if(sss == si){
            return true;
        }
    }
    return false;
}

void cross_words(int i,int j,int idx){
    output[idx] = '\0';
    if(exist(output)){ s.insert(output); }
    if((i == m) || (i < 0) || (j == m) || (j < 0) || visited[i][j]){
        return ; 
    }
    visited[i][j] = 1;
    // don't pick it
    cross_words(i,j-1,idx);
    cross_words(i-1,j-1,idx);
    cross_words(i-1,j,idx);
    cross_words(i-1,j+1,idx);
    cross_words(i,j+1,idx);
    cross_words(i+1,j+1,idx);
    cross_words(i+1,j,idx);
    cross_words(i+1,j-1,idx);

    // pick it
    output[idx] = cross[i][j];
    cross_words(i,j-1,idx+1);
    cross_words(i-1,j-1,idx+1);
    cross_words(i-1,j,idx+1);
    cross_words(i-1,j+1,idx+1);
    cross_words(i,j+1,idx+1);
    cross_words(i+1,j+1,idx+1);
    cross_words(i+1,j,idx+1);
    cross_words(i+1,j-1,idx+1);
    visited[i][j] = 0;  //backtracking
    return ;
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++){ cin>>words[i]; }
    cin>>m;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>cross[i][j];
            visited[i][j] = false;
        }
    }
    cross_words(0,0,0);
    for(auto ss:s){
        cout<<ss<<' ';
    }
}



