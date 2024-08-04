#include <iostream>
using namespace std;

bool RatInMat(char matrice[10][10],int solution[10][10],int i,int j,int n,int m){
    if(i == n && j == m){
        solution[i][j] = 1;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout<<solution[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
            return true;
    }
    if(i>n || j>m){
        return false;
    }
    if(matrice[i][j] == 'X'){
        return false;
    }
    solution[i][j] = 1;

    // Recursion case
    bool forwardpass = RatInMat(matrice,solution,i,j+1,n,m);
    bool downpass = RatInMat(matrice,solution,i+1,j,n,m);

    // Backtracking
    solution[i][j] = 0;
    if(forwardpass || downpass){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    char matrice[10][10] = {"0000",
                    "00X0",
                    "000X",
                    "0X00"};
    int solution[10][10] = {0};
    bool ans = RatInMat(matrice,solution,0,0,3,3);
    if(ans == false){
        cout<<"Path doesn't exist";
    }
}
