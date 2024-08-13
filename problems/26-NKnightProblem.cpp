#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
int board[10][10] = {0};

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == 1){
                cout<<'{'<<i<<','<<j<<'}'<<' ';
            }
        }
    }
    cout<<endl;
}

bool is_safe(int i,int j){
    if(i-2 >= 0){
        if((j-1 >= 0) && board[i-2][j-1] == 1){
            return false;
        }
        if((j+1 < n) && board[i-2][j+1] == 1){
            return false;
        }
    }
    if(i-1 >= 0){
        if((j-2 >= 0) && board[i-1][j-2] == 1){
            return false;
        }
        if((j+2 < n) && board[i-1][j+2] == 1){
            return false;
        }
    }
    return true;
}

void safe_positions(int i,int j,int remain){
    if(remain == 0){
        print();
        ans++;
        return ;
    }
    if(j == n){
        if(i+1 < n){safe_positions(i+1,0,remain);}
        return ;
    }
    if(is_safe(i,j)){
        board[i][j] = 1;
        safe_positions(i,j+1,remain-1);
        board[i][j] = 0;   //Backtracking
    }
    safe_positions(i,j+1,remain);
    return ;
}

int main() {
    cin>>n;
    safe_positions(0,0,n);
    cout<<ans;
}

// void safe_positions(int i,int j){
//     if(i == n){
//         print();
//         ans++;
//         return ;
//     }
//     if(j > n){
//         return ;
//     }
//     for(int j=0;j<n;j++){
//         if(is_safe(i,j)){
//             board[i][j] = 1;
//             safe_positions(i+1);
//             board[i][j] = 0;   //Backtracking
//         }
//     }
//     return ;
// }

