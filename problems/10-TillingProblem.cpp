#include <iostream>
using namespace std;

int number_of_possibilities(int n,int m){
    if(n < m){
        return 1;
    }
    if(n == m){
        return 2; 
    }
    int ans = 0;
    ans += number_of_possibilities(n-1,m) + number_of_possibilities(n-m,m);
    return ans;
}

int main() {
    int T; cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        cout<<number_of_possibilities(n,m)<<endl;
    }
}
