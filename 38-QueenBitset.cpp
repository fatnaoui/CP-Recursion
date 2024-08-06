#include <iostream>
#include <bitset>
using namespace std;

bitset<20> Horiz,InvDiag,Diag = {0};

bool is_safe(int i,int j,int n){
    if(Horiz[j] || InvDiag[i+j] || Diag[j-i+n]) return false;
    Horiz[j] = 1;
    InvDiag[i+j] = 1;
    Diag[j-i+n] = 1;
    return true;
}

void queen(int Mat[][10],int i,int n){
    if(i > n){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n;k++){
                cout<<Mat[j][k]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
        return ;
    }

    for(int j=0;j<=n;j++){
        if(is_safe(i,j,n)){
            Mat[i][j] = 1;
            queen(Mat,i+1,n);
            Mat[i][j] = 0;
            Horiz[j] = 0;
            InvDiag[i+j] = 0;
            Diag[j-i+n] = 0;
        }
    }
    return;
}

int main() {
    int n; cin>>n;
    int Mat[10][10] = {0};
    queen(Mat,0,n-1);
}
