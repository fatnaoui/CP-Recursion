#include <iostream>
using namespace std;

// partial recursive 
void bubble_sort(int *a,int n){
    if(n==1) return;
    int i=0;
    while(i<n-1){
        if(a[i]>a[i+1]){
            swap(a[i],a[i+1]);
        }
        i++;
    }
    bubble_sort(a,n-1);
}

// complete recursive
void bubble_sort_complete(int *a,int n,int i){
    if(n==1) return;
    if(i==n-1){
        return bubble_sort_complete(a,n-1,0);
    }
    if(a[i]>a[i+1]){
        swap(a[i],a[i+1]);
    }
    bubble_sort_complete(a,n,i+1);
}

int main() {
    int a[] = {2,1,4,3,7,6};
    int n = sizeof(a)/sizeof(int);

    // bubble_sort(a,n);
    // for(int x:a){
    //     cout<<x<<endl;
    // }

    bubble_sort_complete(a,n,0);
    for(int x:a){
        cout<<x<<endl;
    }

}
