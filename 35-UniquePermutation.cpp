#include <iostream>
#include <set>
#include <string>
using namespace std;

void permute(char *inp,int i,set<string> &s){
    // Base case
    if(inp[i] == '\0'){
        string t(inp);
        s.insert(t);
        return ;
    }

    // Recursion case 
    for(int j=i;inp[j] != '\0';j++){
        swap(inp[i],inp[j]);
        permute(inp,i+1,s);

        // Backtracking - to restore the original array
        swap(inp[i],inp[j]);
    }
}

int main() {
    char inp[100];
    cin>>inp;
    set<string> s;

    permute(inp,0,s);

    // loop 
    for(auto str:s){
        cout<<str<<' ';
    }
}
