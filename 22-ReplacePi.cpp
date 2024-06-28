#include <iostream>
#include <cstring>
using namespace std;

void ReplacePi(char *a,int i){
    if(a[i] == '\n') return ;
    if(a[i] == 'P' and a[i+1] == 'i'){
        int j = i+1;
        while(a[j] != '\n'){
            j++;
        }
        while(j>i+1){
            a[j+2] = a[j];
            j--;
        }
        a[i] = '3';
        a[i+1] = '.';
        a[i+2] = '1';
        a[i+3] = '4';
        ReplacePi(a,i+4);
    }
    else{
        ReplacePi(a,i+1);
    }
}

int main() {
    char a[1000];
    cin>>a;
    ReplacePi(a,0);
    cout<<a;
}
