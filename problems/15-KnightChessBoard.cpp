#include <iostream>
using namespace std;

int board[10][10];

int numer_of_safe_reahced_places(int i,int j,int n){
    if((i<0) || (i>n) || (j<0) || (j>n) || board[i][j] == 0){
        return 0;
    }
    board[i][j] = 0;
    int r = 0;
    r = 1+max(numer_of_safe_reahced_places(i-2,j-1,n),
                 max(numer_of_safe_reahced_places(i-1,j-2,n),
                 max(numer_of_safe_reahced_places(i-1,j+2,n),
                 max(numer_of_safe_reahced_places(i-2,j+1,n),
                 max(numer_of_safe_reahced_places(i+1,j-2,n),
                 max(numer_of_safe_reahced_places(i+1,j+2,n),
                 max(numer_of_safe_reahced_places(i+2,j-1,n),
                    numer_of_safe_reahced_places(i+2,j+1,n))))))
                )   );
    board[i][j] = 1;
    return r;
}


int main() {
    int n; cin>>n;
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
            if(board[i][j] == 1){
                sum++;
            }
        }
    }
    cout<<sum - numer_of_safe_reahced_places(0,0,n-1);
}
