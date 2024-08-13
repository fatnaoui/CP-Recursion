#include <bits/stdc++.h>
using namespace std;

int n;
int board[15][15] = {0};
bitset<15> Col = {0};
bitset<30> InvDiag = {0};
bitset<30> Diag = {0};
int ans = 0;

bool is_safe(int i,int j){
    if(Col[j] == 1) {return false;}
    if(InvDiag[i+j] == 1) {return false;}
    if(Diag[j-i+n-1] == 1) {return false;}
    return true;
}

void number_of_ways(int i){
    if(i == n){
        ans++;
        return ;
    }
    for(int j=0;j<n;j++){
        if(is_safe(i,j)){
            board[i][j] = 1;
            Col[j] = 1;
            InvDiag[i+j] = 1;
            Diag[j-i+n-1] = 1;
            number_of_ways(i+1);
            board[i][j] = 0;
            Col[j] = 0;
            InvDiag[i+j] = 0;
            Diag[j-i+n-1] = 0;
        }
    }
    return ;
}

int main() {
    cin>>n;
    number_of_ways(0);
    cout<<ans;
}



