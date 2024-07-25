#include <iostream>
#include <string>
using namespace std;

void generate_brackets(int n,char *output,int idx,int open,int close){
    // base case
    if(idx == 2*n){
        output[idx] = '\0'; cout<<output<<endl; return ;
    }

    // recursion case
    if(open < n){
        output[idx] = '(';
        generate_brackets(n,output,idx+1,open+1,close);
    }
    if(close < open){
        output[idx] = ')';
        generate_brackets(n,output,idx+1,open,close+1);
    }
}

int main() {
    int n;
    cin>>n;
    char output[100];
    generate_brackets(n,output,0,0,0);
}
