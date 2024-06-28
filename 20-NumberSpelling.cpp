#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Number to spellings
// 2048 --> two zero four eight

void NTS(string *a,int n){
    if(n==0) return ;
    NTS(a,n/10);
    int digit = n % 10;
    cout<<a[digit]<<' ';
}

// if you swap these two lines -int digit = n % 10;
//                             -cout<<a[digit]<<' ';
// we will notice that order has been changed

int main() {
    string arr[] = {"zero","one","two","three","foor","five","six","seven","eight","nine","ten"};
    int n;
    cin>>n;
    NTS(arr,n);
}
