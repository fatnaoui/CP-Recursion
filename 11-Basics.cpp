#include <iostream>
using namespace std;

// N factorial 
int fact(int n){
    if(n==0){
        return 1;
    }
    return n*fact(n-1);
}

// fibonacci
int fibo(int n){
    if(n==0 or n==1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}

// increase
void in(int n){
    if(n==0){
        return;
    }
    in(n-1);
    cout<<n<<" "<<endl;
}

// decrease
void dec(int n){
    if(n==0){
        return;
    }
    cout<<n<<" "<<endl;
    dec(n-1);
}

int main() {
    int n;
    cin>>n;
    dec(n);
}
