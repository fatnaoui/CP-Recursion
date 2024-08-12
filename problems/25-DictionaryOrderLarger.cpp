#include <bits/stdc++.h>
using namespace std;

string word;
string temp;

void print_combinations(int i){
    if(word[i] == '\0'){
        if(word > temp){
            cout<<word<<endl;
        }
        return ;
    }
    for(int j=i;word[j] != '\0';j++){
        swap(word[i],word[j]);
        print_combinations(i+1);
        swap(word[i],word[j]);
    }
    return ;
}

int main() {
    cin>>word;
    temp = word;
    print_combinations(0);
}
