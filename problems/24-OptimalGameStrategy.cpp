#include <iostream>
using namespace std;

int n;
int input[30];

int max_points(int i,int j){
    if(i > j){
        return 0;
    }
    int pickfirst = input[i] + min(max_points(i+2,j),max_points(i+1,j-1));
    int picklast = input[j] + min(max_points(i,j-2),max_points(i+1,j-1));
    return max(pickfirst,picklast);
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    cout<<max_points(0,n-1);
}
