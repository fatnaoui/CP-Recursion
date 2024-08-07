#include <iostream>
using namespace std;

void code_of_string(int i,int j,char *inp,char *out){
    if(inp[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return ;
    }
    if(inp[i] == '0'){
        code_of_string(i+1,j,inp,out);
        return ;
    }
    int a = inp[i] - '0';
    char s = a + 'a' - 1;
    out[j] = s;
    code_of_string(i+1,j+1,inp,out);
    if(inp[i+1] != '\0'){
        int b = a*10 + (inp[i+1] - '0');
        if(b<=26){
            char s = b + 'a' - 1;
            out[j] = s;
            code_of_string(i+2,j+1,inp,out);
        }
    }
    return ;
}

int main() {
    char inp[30];
    cin>>inp;
    char out[30];
    code_of_string(0,0,inp,out);
}
