#include <iostream>
using namespace std;

int count(int n) {
    if (n == 0) return 0;
    if (n == 1) return 2;
    if (n == 2) return 3;
    return count(n-1) + count(n-2);
}

int main() {
    cout << count(3);
}

