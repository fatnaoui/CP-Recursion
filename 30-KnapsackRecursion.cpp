#include <iostream>
using namespace std;

int max_profite(int n,int c,int i,int m_capacity,int *profite,int *capacity){
    if(i == n){
        return 0;
    }

    int ans = 0;
    int with,without;
    with = without = 0;
    
    without = max_profite(n,c,i+1,m_capacity, profite,capacity);
    if(capacity[i] <= c-m_capacity){
        with = profite[i] + max_profite(n,c,i+1,m_capacity+capacity[i] ,profite,capacity);
    }

    ans = max(with,without);
    return ans;

}

int main() {
    int c; cin>>c;
    int n; cin>>n;
    int profite[n];
    int capacity[n];
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        capacity[i] = a;
        profite[i] = b;
    }
    cout<<max_profite(n,c,0,0,profite,capacity); 
}
