#include <iostream>
using namespace std;

int NumberOfWays(int n){
    if(n==2) return n;
     if (n == 0 || n == 1) {
        return 1;
    }
    return NumberOfWays(n - 1) + (n - 1) * NumberOfWays(n - 2);
}

int main() {
    cout<<NumberOfWays(10);
}
