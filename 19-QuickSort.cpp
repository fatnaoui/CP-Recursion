#include <iostream>
using namespace std;

int partition(int *a,int s,int e){
    int i = s-1;
    int j = s;
    int pivot = a[e];
    for(;j<e;){
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
        j++;
    }
    swap(a[i+1],a[e]);
    return i+1;
}

void quickSort(int *a,int s,int e){
    if(s>=e) return ;
    int p = partition(a,s,e);
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
}

int main() {
    int a[] = {2,7,8,6,1,5,4};
    int n = sizeof(a)/sizeof(int);
    quickSort(a,0,n-1);
    for(int x:a){
        cout<<x<<' ';
    }
}
