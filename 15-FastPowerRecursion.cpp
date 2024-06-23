#include <iostream>
using namespace std;

//First let's build the fast power algorithm usig bitwise
int FatsMulti(int a,int b,int m){
    int ans = 0;
    while(b>0){
        if(b&1){
            ans = (ans+a)%m;
        }
        a = 2*a;
        b = b/2;
    }
    return (ans+m)%m;
}

int FastPower(int a,int b,int m){
    int ans = 1;
    while(b>0){
        if(b&1){
            ans = FatsMulti(ans,a,m);
        }
        a = FatsMulti(a,a,m);
        b = b/2;
    }
    return (ans+m)%m;
}

// Let's now build it using Recursion
int power(int a,int b){
    if(b==0) return 1;
    return a*power(a,b-1);
}

int fastP(int a,int b){
    if(b==1) return a;
    int ans = fastP(a,b/2);
    ans*=ans;
    if(b&1){
        ans*=a;
    }
    return ans;
}

int main() {
    cout<<fastP(2,3);
}
