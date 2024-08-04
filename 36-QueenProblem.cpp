#include <iostream>
#include <set>
#include <string>
using namespace std;

bool is_safe(int Mat[][100],int i,int j,int n){
    // horizontal line
    for(int k=0;k<i;k++){
        if(Mat[k][j] == 1){
            return false;
        }
    }

    // inverse diagonal line
    for(int k=1;(i-k)>=0 && (j-k)>=0;k++){
        if(Mat[i-k][j-k] == 1){
            return false;
        }
    }

    // diagonal line
    for(int k=1;(i-k)>=0 && (j+k)<=n;k++){
        if(Mat[i-k][j+k] == 1){
            return false;
        }
    }

    return true;  // you can place the Queen
}

bool quene(int Mat[][100],int i,int n){
    // Base case
    if(i > n){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                cout<<Mat[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    for(int j=0;j<=n;j++){
        if(is_safe(Mat,i,j,n)){
            Mat[i][j] = 1;
            bool nextqueen = quene(Mat,i+1,n);
            if(nextqueen){
                return true;
            }
            Mat[i][j] = 0; // Backtracking
        }
    }
    return false;
}

int main() {
    int Mat[100][100] = {0};
    int n; cin>>n;
    bool ans = quene(Mat,0,n-1);
    if(ans == false){
        cout<<"we cannot place the Queens";
    }
}
