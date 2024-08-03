#include <iostream>
using namespace std;

char Keypad[][10] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXRZ"};

void generate_names(char *inp,char *out,int i,int j){
    // Base case 
    if(inp[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return ;
    }

    // Recursion case
    int digit = inp[i] - '0';

    if(digit == 1 || digit == 0){
        generate_names(inp,out,i+1,j);
    }

    char *name = Keypad[digit];
    int k = 0;
    while(name[k] != '\0'){
        out[j] = name[k];
        generate_names(inp,out,i+1,j+1);
        k++;
    }
}

int main() {
    char inp[10];
    cin>>inp;
    char out[100];
    generate_names(inp,out,0,0);
}
