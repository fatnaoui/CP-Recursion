#include <iostream>
using namespace std;

bool is_safe(int soduko[][9],int i,int j,int k,int n){
    for(int row=0;row<i;row++){
        if(soduko[row][j] == k){
            return false;
        }
    }

    for(int col=0;col<j;col++){
        if(soduko[i][col] == k){
            return false;
        }
    }

    return true;
}

bool generate_soduko(int soduko[][9],int i,int j,int n){
    if(i > n){
        for(int h=0;h<=n;h++){
            for(int k=0;k<=n;k++){
                cout<<soduko[h][k]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    if(j > n){
        return generate_soduko(soduko,i+1,0,n);
    }
    if(soduko[i][j] != 0){
        return generate_soduko(soduko,i,j+1,n);
    }
    for(int k=1;k<=n+1;k++){
        if(is_safe(soduko,i,j,k,n)){
            soduko[i][j] = k;
            bool next = generate_soduko(soduko,i,j+1,n);
            if(next){
                return true;
            }
        }
    }
    soduko[i][j] = 0;
    return false;
}

int main() {
    int n; cin>>n;
    int soduko[9][9] = {0};
    generate_soduko(soduko,0,0,n-1);
}
