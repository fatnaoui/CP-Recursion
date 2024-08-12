#include <bits/stdc++.h>
using namespace std;

bool null_sum(int i,int n,int *input){
    if(i == n){
        return false;
    }
    int ans = 0;
    for(int j=0;j<i;j++){
        ans += input[j];
        if(ans == 0) return true ;
        if((input[j] + input[i]) == 0) return true;
        if((ans + input[i]) == 0) return true;
    }
    if(null_sum(i+1,n,input)){
        return true;
    }
    return false;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        int input[4];
        for(int i=0;i<n;i++){
            cin>>input[i];
        }
        if(null_sum(0,n,input)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    
}
