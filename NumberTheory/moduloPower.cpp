#include<bits/stdc++.h>

using namespace std;

int modpow(int n, int expo, int m){
    if(expo == 0) return 1%m;
    long long u = modpow(n,expo/2,m);
    u = (u*u)%m;
    if(expo%2 == 1) u = (u*n)%m;
    return u;
}
