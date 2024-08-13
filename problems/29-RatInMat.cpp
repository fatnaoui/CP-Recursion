#include <iostream>
using namespace std;

int n,m;
char Mat[1000][1000];
bool first_reached = false;

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<Mat[i][j]<<' ';
        }
        cout<<endl;
    }
}

bool rat_path(int i,int j){
    if((i == n-1) && (j == m-1)){
        if(!first_reached){
            Mat[i][j] = '1';
            print();
            Mat[i][j] = '0';
            first_reached = true;
        }
        return true;
    }
    if( (i == n) || (j == m) || Mat[i][j] == 'X'){
        return false;
    }
    Mat[i][j] = '1';
    bool rp = rat_path(i,j+1);
    bool lp = rat_path(i+1,j);
    Mat[i][j] = 'O';
    if(rp || lp){
        return true;
    }
    return false;
}

int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>Mat[i][j];
        }
    }
    if(!rat_path(0,0)){ cout<<-1; }
}
