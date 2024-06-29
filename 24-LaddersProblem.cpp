#include <iostream>
using namespace std;

// how many ways to reach the top if you have n steps and the max jump steps you can do is 3

int NumberOfLadders(int n){
    if(n<3) return n;
    if(n==3) return 4;
    return NumberOfLadders(n-1)+NumberOfLadders(n-2)+NumberOfLadders(n-3);
}

int main() {
    cout<<NumberOfLadders(4);
}
