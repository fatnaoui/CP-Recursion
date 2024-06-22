#include <iostream>
using namespace std;

int FirstOccurence(int *a,int n,int key){
    if(n==0){
        return -1;
    }
    if(a[0] == key){
        return 0;
    }
    int i = FirstOccurence(a+1,n-1,key);
    if(i == -1){
        return -1;
    }
    return i+1;
}

int main() {
    int a[] = {1,3,2,4,5,2,7};
    int n = sizeof(a)/sizeof(int);
    int k = 2;
    cout<<FirstOccurence(a,n,k);
}
