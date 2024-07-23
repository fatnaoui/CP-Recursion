#include <iostream>
using namespace std;

void genere(char *inp,char *out,int i,int j){
    if(inp[i] == '\0'){
        out[j] = '\0';
        cout<<out<<"--";
        return ;
    }

    out[j] = inp[i];
    genere(inp,out,i+1,j+1);
    genere(inp,out,i+1,j);
}

int main() {
    char input[100];
    cin>>input;
    char output[100];
    genere(input,output,0,0);
}
