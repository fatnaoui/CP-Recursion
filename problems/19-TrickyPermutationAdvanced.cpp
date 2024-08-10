#include <bits/stdc++.h>
using namespace std;

int n; 
int input[10];

void print_permutation(int i){
    if(i == n){
        for(int j = 0; j < n; j++) {
            cout << input[j] << " ";
        }
        cout << endl;
        return;
    }
    for(int k=i;input[k] !='\0';k++){
        bool shouldswap = true;
        for(int j=i;j<k;j++){
            if(input[j] == input[k]){
                shouldswap = false;
                break;
            }
        }
        if(shouldswap){
            if((input[i] != input[k]) || (i == k)){
                swap(input[i],input[k]);
                print_permutation(i+1);
                swap(input[i],input[k]);
            }
        }
    }
    return ;
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    sort(input,input+n);
    print_permutation(0);
}
