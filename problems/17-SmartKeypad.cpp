#include <iostream>
using namespace std;

char input[10];
char output[10];
char table[10][10] = {
        " ", ".+@$", "abc", "def", "ghi",
        "jkl" , "mno", "pqrs" , "tuv", "wxyz"
};

void print_codes(int i){
    if(input[i] == '\0'){
        output[i] = '\0';
        cout<<output<<endl;
        return ;
    }
    int idx = input[i] - '0';
    for(int k=0;table[idx][k] != '\0';k++){
        output[i] = table[idx][k];
        print_codes(i+1);
    }
    return ;
}

int main() {
    cin>>input;
    print_codes(0);
}
