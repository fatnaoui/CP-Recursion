#include <iostream>
using namespace std;

void number_of_binary_string(int i,int n,int p,int &ans){
    if(i == n){
        ans++;
        return;
    }
    if(p == 1){
        number_of_binary_string(i+1,n,0,ans);
    }
    if(p == 0){
        number_of_binary_string(i+1,n,0,ans);
        number_of_binary_string(i+1,n,1,ans);
    }
    return ;
}

int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int ans = 0;
        number_of_binary_string(0,n,0,ans);
        cout<<ans<<endl;
    }
}
