#include <bits/stdc++.h>
using namespace std;

int n;
int input[15];
int target;
int limit;
int D;
set<vector<int>> v1;

int get_index(int number){
    int idx = 0;
    while((number & 1) == 0){
        number = number >> 1;
        idx++;
    }
    return idx;
}

void print_combinations(){
    for(int i=1;i<=limit;i++){
        vector<int> v2;
        int s = 0;
        int c = D & i;
        bool add = true;
        while(c > 0){
            int p = c & (-c);
            c = c- p;
            int idx = get_index(p);
            if((s+input[idx]) > target){
                add = false;
                break ;
            }
            s += input[idx];
            v2.push_back(input[idx]);
        }
        if((s == target) && add){
            sort(v2.begin(),v2.end());
            v1.insert(v2);
        }
    }
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    cin>>target;
    limit = (1<<n) - 1;
    D = ~(-1 << n);
    print_combinations();
    for(auto v :v1){
        for(auto number:v){
            cout<<number<<' ';
        }
        cout<<endl;
    }
}
