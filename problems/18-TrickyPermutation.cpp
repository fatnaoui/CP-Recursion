#include <bits/stdc++.h>
using namespace std;

string input;
set<string> s;

void print_permutation(int i){
    if(input[i] == '\0'){
        s.insert(input);
        return ;
    }
    for(int k=i;input[k] != '\0';k++){
        swap(input[i],input[k]);
        print_permutation(i+1);
        swap(input[i],input[k]);
    }
    return ;
}

int main() {
    cin>>input;
    sort(input.begin(),input.end());
    print_permutation(0);
    for(string ss:s){
        cout<<ss<<endl;
    }
}
