#include <iostream>
using namespace std;

int number_of_pairs(int n){
    if(n == 2) return n;
    if(n == 0 || n == 1){
        return 1;
    }
    return number_of_pairs(n-1) + (n-1)*number_of_pairs(n-2);
}

int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<number_of_pairs(n)<<endl;
    }
}
