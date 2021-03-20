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