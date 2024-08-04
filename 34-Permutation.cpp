#include <iostream>
using namespace std;

void permute(char *inp,int i){
    // Base case
    if(inp[i] == '\0'){
        cout<<inp<<endl;
        return ;
    }

    // Recursion case 
    for(int j=i;inp[j] != '\0';j++){
        swap(inp[i],inp[j]);
        permute(inp,i+1);

        // Backtracking - to restore the original array
        swap(inp[i],inp[j]);
    }
}

int main() {
    char inp[100];
    cin>>inp;
    permute(inp,0);
}
