#include <iostream>
using namespace std;

// given a wall of size of 4*n, and tiles of size (1,4) and (4,1)
// in how many ways you can build the wall

int NumberOfWall(int n){
    if(n==4) return 2;
    if(n<4) return 1;
    return NumberOfWall(n-1)+NumberOfWall(n-4);
}

int main() {
    cout<<NumberOfWall(5);
}
