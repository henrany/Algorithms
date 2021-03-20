#include<bits/stdc++.h>

using namespace std;

namespace generate_set{
    void method1(int k, vector<bool> &subset, int n){
        if(k == n){
            //process subset;
            cout<<"{ ";
            for(int i=0;i<n;i++){
                if(subset[i] == true){
                    cout<<i+1<<" ";
                }
            }
            cout<<"}\n";
        }
        else{
            subset[k] = true;
            method1(k+1,subset,n);
            subset[k] = false;
            method1(k+1,subset,n);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<bool> subset(n);
    generate_set::method1(0,subset,n);
}