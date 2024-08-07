#include <iostream>
using namespace std;

void generate_parentheses(int i,int n,char *out,int open,int close){
    if(i > (2*n)-1){
        out[i] = '\0';
        cout<<out<<endl;
        return ;
    }
    if(open < n){
        out[i] = '(';
        generate_parentheses(i+1,n,out,open+1,close);
    }
    if(close < open){
        out[i] = ')';
        generate_parentheses(i+1,n,out,open,close+1);
    }
    return ;
}

int main() {
    int n; cin>>n;
    char out[30];
    generate_parentheses(0,n,out,0,0);
}
