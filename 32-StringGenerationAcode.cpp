#include <iostream>
using namespace std;

void generate_strings(char *inp,char *out,int i,int j){
    // Base case 
    if(inp[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }

    // Recursion case
    // One digit at time
    int digit1 = inp[i] - '0';
    if(digit1 == 0){
        generate_strings(inp,out,i+1,j);
    }
    else{
        char ch = digit1 + 'A' - 1;
        out[j] = ch;
        generate_strings(inp,out,i+1,j+1);
    }

    // Two digits at time
    if(inp[i+1] != '\0'){
        int digit2 = inp[i+1] - '0';
        int no = digit1*10 + digit2;
        if(no<=26){
            out[j] = no + 'A' - 1;
            generate_strings(inp,out,i+2,j+1);
        }
    }
}

int main() {
    char inp[100];
    cin>>inp;
    char out[100];
    generate_strings(inp,out,0,0);
}
