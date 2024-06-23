#include <iostream>
using namespace std;

void AllOccurence(int *a,int i,int n,int key){
    if(i==n) return ;
    if(a[i] == key) cout<<i<<',';
    AllOccurence(a,i+1,n,key);
}

int main() {
    int a[] = {1,3,2,4,6,5,2};
    AllOccurence(a,0,7,2);
}
