#include<bits/stdc++.h>

using namespace std;

template<typename T>
vector<T> insertionSort(vector<T> insertion){
    T temp;
    for(int i=0;i<insertion.size();i++){
        int j = i+1;
        while(insertion[i] > insertion[j] && j < insertion.size()){
            temp = insertion[i];
            insertion[i] = insertion[j];
            insertion[j] = temp;
            j--;
            i--;
        } 
    }
    return insertion;
}

int main(){
    vector<int> insertion{5,3,2,2,4,2,1,4,6,4,2,5,3,2,5,7,8,3,2,34,67,633,5,3,5,3,5,6,7,3,56,9,8,4,2,34,5};
    for(auto &i: insertionSort(insertion)){
        cout<<i<<" ";
    }
    cout<<"\n";
}