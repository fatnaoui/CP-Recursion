#include <iostream>
using namespace std;

void merge(int *a,int s,int e){
    int m = (s+e)/2;
    int n = e-s+1;
    int t[n]; 
    int i = s;
    int j = m+1;
    int k =0;
    while(i<=m && j<=e){
        if(a[i] > a[j]){
            t[k++] = a[j++];
        }
        else{
            t[k++] = a[i++];
        }
    }
    while(i<=m){
        t[k++] = a[i++];
    }
    while(j<=e){
        t[k++] = a[j++];
    }
    for(int x:t){
        a[s] = x;
        s++;
    }
}

void merge_sort(int *a,int s,int e){
    if(s>=e){
        return;
    }
    int m = (s+e)/2;
    merge_sort(a,s,m);
    merge_sort(a,m+1,e);
    merge(a,s,e);
}

int main() {
    int a[] = {2,1,4,3,7,6};
    int n = sizeof(a)/sizeof(int);

    merge_sort(a,0,n-1);
    for(int x:a){
        cout<<x<<endl;
    }

}
