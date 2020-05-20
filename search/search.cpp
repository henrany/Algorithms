#include<bits/stdc++.h>

using namespace std;

namespace search{
    template<typename T>
    T linearSearch(vector<T> l, T value){
        bool found = false;
        int index = 0;
        for(int i=0;i<l.size();i++){
            if(l[i] == value){
                found = true;
                cout<<i<<"\n";
            }
        }
        return found;
    }

    template<typename T>
    T binarySearch(vector<T> l, T value){
        //first the element needs to be sorted 
        int a = 0;
        int b = l.size() - 1;
        bool found = false;
        int index = 0;
        while(a<=b){
            int k = (a+b)/2;
            if(l[k] == value){
                found = true;
                cout<<k<<"\n";
                break;
            }
            else if(l[k] > value){
                b = k-1;
            }
            else{
                a = k+1;
            }
        }
        return found;
    }

    template<typename T>
    T jumpSearch(vector<T> l, T value){
        //array needs to be sorted
        bool found = false;
        int k=0;
        for(int i=l.size()/2;i>=1;i/=2){
            while(k+i<l.size() && l[k+i] <= value) k+=i;
        }
        if(l[k] == value){
            found = true;
            cout<<k<<"\n";
        }
        return found;
    }
}

int main(){
    vector<int> numbers{3,4,6,2,8,5,9,1,7};
    vector<double> dec{1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0};
    cout<<search::linearSearch(numbers,8)<<"\n";
    cout<<search::binarySearch(dec,2.0)<<"\n";
    cout<<search::jumpSearch(dec,1.7)<<"\n";
    return 0;
}