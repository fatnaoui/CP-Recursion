#include <iostream>
#include <bitset>
using namespace std;

int ans =0,D;

void queen(int rowmask,int ld,int lr){
    if(rowmask == D){
        ans++;
        return;
    }
    int safe = D & (~(rowmask | ld | lr));
    while(safe){
        int p = safe & (-safe);
        safe = safe - p;
        queen((rowmask | p),(ld | p) << 1,(lr | p) >> 1);
    }
  
}

int main() {
    int n; cin>>n;
    D = (1 << n) - 1;
    queen(0,0,0);
    cout<<ans;
}
