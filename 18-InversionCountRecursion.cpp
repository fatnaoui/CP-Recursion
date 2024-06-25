#include <iostream>
using namespace std;

int merge(int *a,int s,int e){
    int mid = (s+e)/2;
    int i=s;
    int j = (mid+1);
    int k = s;
    int t[100];
    int ans = 0;
    while(i<=mid && j<=e){
        if(a[i]<a[j]){
            t[k++] = a[i++];
        }
        else{
            t[k++] = a[j++];
            ans += mid-i+1; 
        }
    }
    while(i<=mid){
        t[k++] = a[i++];
    }
    while(j<=e){
        t[k++] = a[j++];
    }
    for(int i=s;i<=e;i++){
        a[i] = t[i];
    }
    return ans;
}

int inverse(int *a,int s,int e){
    if(s>=e) return 0;
    int middle = (s+e)/2;
    int x = inverse(a,s,middle);
    int y = inverse(a,middle+1,e);
    int z = merge(a,s,e);
    return x+y+z;
}

int main() {
    // int a[] = {1,5,2,6,3,0};
    int a[] = {9,2,5,4,7,0,1};
    cout<<inverse(a,0,6);
}
