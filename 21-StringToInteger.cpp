#include <iostream>
#include <cstring>
using namespace std;

int StringToInt(char *s,int n){
    if(n == 0) return 0;
    int digit = s[n-1] - '0';
    int ans = StringToInt(s,n-1);
    ans = ans*10 + digit;
    return ans;
}

int main() {
    char s[] = "473846329";
    int n = strlen(s);
    
    cout<<StringToInt(s,n);;
}
