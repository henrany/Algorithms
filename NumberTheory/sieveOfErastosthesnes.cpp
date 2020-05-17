#include<bits/stdc++.h>

using namespace std;

bool prime(int n){
    if(n < 2) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0) return false;
    }
    return true;
}

vector<int> sieve(int n){
    vector<int> vec;
    for(int i=1;i<=n;i++){
        if(prime(i)){
            vec.push_back(i);
        }
    }

    return vec;
}

int main(){
    int test;
    while(test--){
        int n;
        cin>>n;
        cout<<"[\n";
        for(auto &i: sieve(n)){
            cout<<i<<"\n";
        }
        cout<<"]\n";
    }
}