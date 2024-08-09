#include <iostream>
using namespace std;

void find_digits(int i,int n,int &ans,int pre){
    if(i > n){
        ans++;
        return ;
    }
    if(pre == 0){
        find_digits(i+1,n,ans,1);
    }
    find_digits(i+1,n,ans,0);
    return ;
}

int main() {
    int t; cin>>t;
    int k = 1;
    while(t--){
        int n; cin>>n;
        int ans = 0;
        find_digits(0,n-1,ans,0);
        cout<<"#"<<k++<<" : "<<ans<<endl;
    }
}
